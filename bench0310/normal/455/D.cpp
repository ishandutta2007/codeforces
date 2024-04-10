#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
const int K=223;
vector<int> id(N,-1);

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rng(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}

struct Treap;
using twoTreaps=array<Treap*,2>;

struct Treap
{
    int val;
    int c[K];
    int sz;
    int priority;
    twoTreaps kids;
    Treap *p;
    Treap(int a){val=a;for(int i=0;i<K;i++)c[i]=(i==id[a]);sz=1;priority=rng(1,(1<<30));kids[0]=kids[1]=p=nullptr;}
};

int sz(Treap *me){return (me?me->sz:0);}

void recalc(Treap *me)
{
    if(!me) return;
    me->sz=1;
    for(int i=0;i<K;i++) me->c[i]=(me->kids[0]?me->kids[0]->c[i]:0)+(me->kids[1]?me->kids[1]->c[i]:0)+(i==id[me->val]);
    for(Treap *to:me->kids) if(to) me->sz+=to->sz;
}

void make_parent(Treap *me,int a,Treap *kid)
{
    if(me) me->kids[a]=kid;
    if(kid) kid->p=me;
}

twoTreaps split(Treap *me,int cnt)
{
    if(!me) return {nullptr,nullptr};
    if(sz(me->kids[0])>=cnt)
    {
        if(me->kids[0]) me->kids[0]->p=nullptr;
        twoTreaps res=split(me->kids[0],cnt);
        make_parent(me,0,res[1]);
        recalc(me);
        return {res[0],me};
    }
    else
    {
        if(me->kids[1]) me->kids[1]->p=nullptr;
        twoTreaps res=split(me->kids[1],cnt-sz(me->kids[0])-1);
        make_parent(me,1,res[0]);
        recalc(me);
        return {me,res[1]};
    }
}

Treap* tmerge(Treap *a,Treap *b)
{
    if(!a) return b;
    if(!b) return a;
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

int pos(Treap *me)
{
    int res=1+sz(me->kids[0]);
    while(me)
    {
        Treap *up=me->p;
        if(up&&up->kids[1]==me) res+=(1+sz(up->kids[0]));
        me=up;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v[n+1];
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    int bid=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()>=(N+K-1)/K) id[i]=bid++;
    }
    vector<Treap*> ini(n+1,0);
    for(int i=1;i<=n;i++) ini[i]=new Treap(a[i]);
    Treap *root=ini[1];
    for(int i=2;i<=n;i++) root=tmerge(root,ini[i]);
    int q;
    cin >> q;
    int res=0;
    while(q--)
    {
        int t,l,r,k=0;
        cin >> t >> l >> r;
        if(t==2) cin >> k;
        l=((l+res-1)%n+1);
        r=((r+res-1)%n+1);
        k=((k+res-1)%n+1);
        if(l>r) swap(l,r);
        if(t==1)
        {
            auto [one,tmp1]=split(root,l-1);
            auto [two,tmp2]=split(tmp1,r-l);
            auto [three,four]=split(tmp2,1);
            root=tmerge(tmerge(one,three),tmerge(two,four));
        }
        else
        {
            if(id[k]!=-1)
            {
                auto [one,tmp]=split(root,l-1);
                auto [two,three]=split(tmp,r-l+1);
                res=two->c[id[k]];
                root=tmerge(tmerge(one,two),three);
            }
            else
            {
                res=0;
                for(int i:v[k])
                {
                    int x=pos(ini[i]);
                    res+=(l<=x&&x<=r);
                }
            }
            cout << res << "\n";
        }
    }
    return 0;
}