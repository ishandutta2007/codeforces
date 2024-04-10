#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node;
using twoNodes=array<Node*,2>;

struct Node
{
    int val;
    int mn;
    int sz;
    int flip;
    twoNodes kids;
    Node *p;
    Node *pathp;
    Node(int a){val=mn=a;sz=1;flip=0;kids[0]=kids[1]=p=pathp=nullptr;}
};

int sz(Node *me){return (me?me->sz:0);}
int side(Node *me){return (me->p?(me->p->kids[1]==me):0);}

void recalc(Node *me)
{
    if(!me) return;
    me->sz=1;
    me->mn=me->val;
    for(Node *to:me->kids) if(to) {me->sz+=to->sz;me->mn=min(me->mn,to->mn);}
}

void apply(Node *me)
{
    if(!me) return;
    swap(me->kids[0],me->kids[1]);
    me->flip^=1;
}

void prop(Node *me)
{
    if(me&&me->flip==1)
    {
        for(Node *to:me->kids) apply(to);
        me->flip=0;
    }
}

void make_parent(Node *me,int id,Node *kid)
{
    if(me) me->kids[id]=kid;
    recalc(me);
    if(kid) kid->p=me;
}

void unmake_parent(Node *me,int id)
{
    make_parent(nullptr,0,me->kids[id]);
    make_parent(me,id,nullptr);
}

void rotate_up(Node *me)
{
    Node *p=me->p;
    int id=side(me);
    if(!p->p) swap(me->pathp,p->pathp);
    make_parent(p->p,side(p),me);
    make_parent(p,id,me->kids[id^1]);
    make_parent(me,id^1,p);
}

void splay(Node *me)
{
    while(me->p)
    {
        prop(me->p->p);
        prop(me->p);
        prop(me);
        if(me->p->p)
        {
            if(side(me)==side(me->p)) rotate_up(me->p);
            else rotate_up(me);
        }
        rotate_up(me);
    }
    prop(me);
    recalc(me);
}

void detach_path(Node *me)
{
    if(me->kids[1]) me->kids[1]->pathp=me;
    unmake_parent(me,1);
}

Node* access(Node *me)
{
    Node *up=me;
    splay(me);
    detach_path(me);
    while(me->pathp)
    {
        up=me->pathp;
        me->pathp=nullptr;
        splay(up);
        detach_path(up);
        make_parent(up,1,me);
        splay(me);
    }
    return up;
}

Node* find_root(Node *me)
{
    access(me);
    while(me->kids[0])
    {
        me=me->kids[0];
        prop(me);
    }
    splay(me);
    return me;
}

int depth(Node *me)
{
    access(me);
//    cout << "sz=" << me->sz << endl;
    return (((me->sz+1)/2)&1);
}

void make_root(Node *me)
{
    access(me);
    apply(me);
}

void cut(Node *me)
{
    access(me);
    unmake_parent(me,0);
}

void link(Node *me,Node *up)
{
    make_root(me);
    access(up);
    make_parent(me,0,up);
}

int query(Node *a,Node *b)
{
    make_root(a);
    access(b);
    return (b->mn);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int inf=(1<<30);
    int n,m,q;
    cin >> n >> m >> q;
    vector<Node*> v(n+2*m+1,nullptr);
    for(int i=1;i<=n;i++) v[i]=new Node(inf);
    vector<array<int,2>> edges(m+1,{0,0});
    for(int i=1;i<=m;i++)
    {
        cin >> edges[i][0] >> edges[i][1];
        v[n+i]=new Node(i);
        v[n+m+i]=new Node(inf);
    }
    vector<array<int,2>> queries[m+1];
    vector<bool> res(q+1,0);
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin >> l >> r;
        queries[l-1].push_back({r+1,i});
    }
    int dangling=0;
    vector<bool> in_use(m+1,0);
    for(int i=m;i>=1;i--)
    {
        auto [a,b]=edges[i];
        make_root(v[a]);
        if(find_root(v[a])!=find_root(v[b]))
        {
            link(v[a],v[n+i]);
            link(v[b],v[n+i]);
            in_use[i]=1;
        }
        else if(depth(v[a])==depth(v[b]))
        {
//            cout << "depth[" << a << "]=" << depth(v[a]) << endl;
//            cout << "depth[" << b << "]=" << depth(v[b]) << endl;
            dangling=i;
            break;
        }
    }
    auto out=[&]()
    {
        for(int i=1;i<=q;i++) cout << (res[i]?"YES":"NO") << "\n";
        exit(0);
    };
//    cout << "dangling=" << dangling << endl;
    if(dangling==0) out();
    for(auto [r,id]:queries[0]) res[id]=(r<=dangling);
    for(int i=1;i<=m;i++)
    {
//        cout << "l=" << i << endl;
        auto [a,b]=edges[i];
        make_root(v[a]);
        if(find_root(v[a])!=find_root(v[b]))
        {
//            cout << "not connected, link " << "[" << a << "," << b << "]" << endl;
            link(v[a],v[n+m+i]);
            link(v[b],v[n+m+i]);
        }
        else if(depth(v[a])!=depth(v[b]))
        {
            int mn=query(v[a],v[b]);
//            cout << "even cycle, mn=" << mn << endl;
            if(mn<inf)
            {
                in_use[mn]=0;
                make_root(v[n+mn]);
                auto [c,d]=edges[mn];
                cut(v[c]);
                cut(v[d]);
                link(v[a],v[n+m+i]);
                link(v[b],v[n+m+i]);
//                cout << "cut [" << c << "," << d << "]" << endl;
//                cout << "link [" << a << "," << b << "]" << endl;
            }
        }
        else
        {
            int mn=query(v[a],v[b]);
//            cout << "possible to move dangling, mn=" << mn << endl;
            if(mn==inf)
            {
                for(int j=i;j<=m;j++) for(array<int,2> x:queries[j]) res[x[1]]=1;
                out();
            }
            for(int j=dangling;j<=mn;j++)
            {
                if(in_use[j])
                {
                    auto [c,d]=edges[j];
                    make_root(v[n+j]);
                    cut(v[c]);
                    cut(v[d]);
                    in_use[j]=0;
                }
            }
            dangling=mn;
//            cout << "link [" << a << "," << b << "]" << endl;
            link(v[a],v[n+m+i]);
            link(v[b],v[n+m+i]);
        }
        for(auto [r,id]:queries[i]) res[id]=(r<=dangling);
//        cout << "after [1," << i << "], dangling=" << dangling << endl << endl;
    }
    out();
    return 0;
}