#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

struct Treap;
using twoTreaps=array<Treap*,2>;

struct Treap
{
    int val;
    int lazy;
    int sz;
    int priority;
    twoTreaps kids;
    Treap *p;
    Treap(int a){val=a;lazy=-1;sz=1;priority=gen();kids[0]=kids[1]=p=nullptr;}
};

int sz(Treap *me){return (me?me->sz:0);}

void recalc(Treap *me)
{
    if(!me) return;
    me->sz=1;
    for(Treap *to:me->kids) me->sz+=sz(to);
}

void make_parent(Treap *me,int id,Treap *kid)
{
    if(me) me->kids[id]=kid;
    if(kid) kid->p=me;
}

void apply(Treap *me,int x)
{
    if(!me) return;
    me->val=me->lazy=x;
}

void push(Treap *me)
{
    if(!me) return;
    if(me->lazy!=-1)
    {
        for(Treap *to:me->kids) apply(to,me->lazy);
        me->lazy=-1;
    }
}

twoTreaps splitcnt(Treap *me,int cnt)
{
    if(!me) return {nullptr,nullptr};
    push(me);
    if(sz(me->kids[0])>=cnt)
    {
        make_parent(nullptr,0,me->kids[0]);
        twoTreaps res=splitcnt(me->kids[0],cnt);
        make_parent(me,0,res[1]);
        recalc(me);
        return {res[0],me};
    }
    else
    {
        make_parent(nullptr,1,me->kids[1]);
        twoTreaps res=splitcnt(me->kids[1],cnt-sz(me->kids[0])-1);
        make_parent(me,1,res[0]);
        recalc(me);
        return {me,res[1]};
    }
}

twoTreaps splitval(Treap *me,int lim)
{
    if(!me) return {nullptr,nullptr};
    push(me);
    if(me->val>lim)
    {
        make_parent(nullptr,0,me->kids[0]);
        twoTreaps res=splitval(me->kids[0],lim);
        make_parent(me,0,res[1]);
        recalc(me);
        return {res[0],me};
    }
    else
    {
        make_parent(nullptr,1,me->kids[1]);
        twoTreaps res=splitval(me->kids[1],lim);
        make_parent(me,1,res[0]);
        recalc(me);
        return {me,res[1]};
    }
}

Treap* tmerge(Treap *a,Treap *b)
{
    if(!a) return b;
    if(!b) return a;
    push(a);
    push(b);
    if(a->priority<b->priority)
    {
        make_parent(a,1,tmerge(a->kids[1],b));
        recalc(a);
        return a;
    }
    else
    {
        make_parent(b,0,tmerge(a,b->kids[0]));
        recalc(b);
        return b;
    }
}

int getpos(Treap *me)
{
    int pos=sz(me->kids[0]);
    while(me->p!=nullptr)
    {
        Treap *u=me->p;
        if(u->kids[1]==me) pos+=(sz(u->kids[0])+1);
        me=u;
    }
    return pos+1;
}

void upd(Treap*& root,Treap *me,int nx)
{
    int pos=getpos(me);
    auto [tmp,three]=splitcnt(root,pos);
    auto [one,two]=splitcnt(tmp,sz(tmp)-1);
    two->val=nx;
    root=tmerge(one,three);
    auto [x,y]=splitval(root,nx);
    root=tmerge(tmerge(x,two),y);
}

int qry(Treap *me)
{
    vector<Treap*> v={me};
    while(v.back()->p!=nullptr) v.push_back(v.back()->p);
    ranges::reverse(v);
    for(Treap *a:v) push(a);
    return (me->val);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Treap*> a(n+1,nullptr);
    Treap *root=nullptr;
    vector<array<int,2>> h(n);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        a[i]=new Treap(x);
        h[i-1]={x,i};
    }
    ranges::sort(h);
    for(int i=0;i<n;i++) root=tmerge(root,a[h[i][1]]);
    int q;
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int k,w;
            cin >> k >> w;
            upd(root,a[k],w);
        }
        if(t==2)
        {
            int k;
            cin >> k;
            cout << qry(a[k]) << "\n";
        }
        if(t==3)
        {
            int l,r;
            cin >> l >> r;
            auto [x,y]=splitval(root,(l+r)/2);
            auto [one,two]=splitval(x,l-1);
            auto [three,four]=splitval(y,r);
            apply(two,l-1);
            apply(three,r+1);
            root=tmerge(tmerge(one,two),tmerge(three,four));
        }
    }
    return 0;
}