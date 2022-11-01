#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct obj
{
    int n;
    vector<int> tree;
    vector<int> v;
    obj(){}
    void ini(vector<int> u)
    {
        v=u;
        n=v.size();
        tree.assign(n,0);
        for(int i=0;i<n;i++) add(i,1);
    }
    void rm(int x){add(id(x),-1);}
    int qry(int x,int y){return sum(id(x),id(y));}
    int id(int a){return (ranges::lower_bound(v,a)-v.begin());}
    void add(int p,int d){for(;p<n;p=p|(p+1))tree[p]+=d;}
    int sum(int p){int r=0; for(;p>=0;p=(p&(p+1))-1)r+=tree[p]; return r;}
    int sum(int l,int r){return sum(r)-sum(l-1);}
};

const int N=300005;
vector<ll> tree(4*N,0);

void update(int idx,int l,int r,int pos,ll x)
{
    if(l==r) tree[idx]=x;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,x);
        else update(2*idx+1,m+1,r,pos,x);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> tin(n+1,0);
    vector<int> tout(n+1,0);
    int tcnt=0;
    int a=0;
    string s;
    cin >> s;
    s="$"+s;
    vector<int> v[n+1];
    vector<ll> c(n+1,0);
    vector<int> p(n+1,0);
    vector<int> pos(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(')
        {
            int b=++tcnt;
            tin[b]=b;
            v[a].push_back(b);
            c[a]++;
            p[b]=a;
            pos[i]=b;
            a=b;
        }
        else
        {
            if(a==0) continue;
            pos[i]=a;
            tout[a]=tcnt;
            a=p[a];
        }
    }
    auto opt=[&](ll cnt)->ll{return (cnt*(cnt+1)/2);};
    vector<obj> st(n+1);
    for(int i=0;i<=tcnt;i++)
    {
        update(1,0,n,i,opt(c[i]));
        st[i].ini(v[i]);
    }
    while(q--)
    {
        int t,l,r;
        cin >> t >> l >> r;
        int x=pos[l];
        int y=pos[r];
        if(t==1)
        {
            st[p[x]].rm(x);
            c[p[x]]--;
            update(1,0,n,p[x],opt(c[p[x]]));
            update(1,0,n,x,0);
        }
        else cout << opt(st[p[x]].qry(x,y))+query(1,0,n,x,tout[y]) << "\n";
    }
    return 0;
}