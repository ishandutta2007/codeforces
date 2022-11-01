#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rng(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}

struct Treap;
using twoTreaps=array<Treap*,2>;

struct Treap
{
    int val;
    int pos;
    int priority;
    int sz;
    int lazy;
    array<Treap*,2> kids;
    Treap(int a,int p){val=a;pos=p;priority=rng(1,(1<<30));sz=1;lazy=0;kids[0]=kids[1]=nullptr;}
};

int sz(Treap *me){return (me?me->sz:0);}

void recalc(Treap *me)
{
    if(!me) return;
    me->sz=1;
    for(Treap *to:me->kids) if(to) me->sz+=to->sz;
}

void apply(Treap *me,int x)
{
    if(!me) return;
    me->pos+=x;
    me->lazy+=x;
}

void push(Treap *me)
{
    if(!me) return;
    for(Treap *to:me->kids) apply(to,me->lazy);
    me->lazy=0;
}

twoTreaps split(Treap *me,int lim)
{
    if(!me) return {nullptr,nullptr};
    push(me);
    if(me->pos>=lim)
    {
        twoTreaps res=split(me->kids[0],lim);
        me->kids[0]=res[1];
        recalc(me);
        return {res[0],me};
    }
    else
    {
        twoTreaps res=split(me->kids[1],lim);
        me->kids[1]=res[0];
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
        a->kids[1]=tmerge(a->kids[1],b);
        recalc(a);
        return a;
    }
    else
    {
        b->kids[0]=tmerge(a,b->kids[0]);
        recalc(b);
        return b;
    }
}

vector<array<int,2>> v;

void go(Treap *me)
{
    if(!me) return;
    push(me);
    go(me->kids[0]);
    v.push_back({me->val,me->pos});
    go(me->kids[1]);
}

vector<int> tree(4*200005,0);

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

int descend(int idx,int l,int r,int x)
{
    if(l==r) return l;
    int m=(l+r)/2;
    if(m-l+1-tree[2*idx]>=x) return descend(2*idx,l,m,x);
    else return descend(2*idx+1,m+1,r,x-(m-l+1-tree[2*idx]));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=998244353;
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    const int N=400000;
    vector<ll> f(N+1,1);
    vector<ll> inv(N+1,1);
    vector<ll> finv(N+1,1);
    for(int i=2;i<=N;i++)
    {
        f[i]=mul(f[i-1],i);
        inv[i]=mod-mul(mod/i,inv[mod%i]);
        finv[i]=mul(finv[i-1],inv[i]);
    }
    auto c=[&](int a,int b)->ll
    {
        return mul(f[a],mul(finv[b],finv[a-b]));
    };
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        Treap *root=nullptr;
        vector<int> a;
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin >> x >> y;
            a.push_back(x);
            update(1,1,n,x,1);
            auto [one,two]=split(root,y);
            apply(two,1);
            root=tmerge(one,tmerge(new Treap(x,y),two));
        }
        go(root);
        int cnt=0;
        int k=0;
        int sz=v.size();
        for(int i=0;i<sz;i++)
        {
            int prvval=-1,prvpos=-1;
            int nxtval=n+2,nxtpos=n+2;
            if(i-1>=0)
            {
                prvval=v[i-1][0];
                prvpos=v[i-1][1];
            }
            if(i+1<sz)
            {
                nxtval=v[i+1][0];
                nxtpos=v[i+1][1];
            }
            auto [val,pos]=v[i];
            if(prvpos!=pos-1&&pos>1)
            {
                int tmp=descend(1,1,n,pos-1-cnt);
                k+=(tmp>val);
            }
            if(nxtpos!=pos+1&&pos<n)
            {
                int tmp=descend(1,1,n,pos+1-(cnt+1));
                k+=(val>tmp);
            }
            if(nxtpos==pos+1) k+=(val>nxtval);
            cnt++;
        }
        cout << c(n+n-1-k,n-1-k) << "\n";
        for(int x:a) update(1,1,n,x,0);
        v.clear();
    }
    return 0;
}