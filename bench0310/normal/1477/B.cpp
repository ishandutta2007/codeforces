#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<array<int,2>> tree(4*N,{0,0});
vector<int> lazy(4*N,-1);

array<int,2> operator+(const array<int,2> &a,const array<int,2> &b)
{
    return {a[0]+b[0],a[1]+b[1]};
}

void push(int idx,int l,int r,int m)
{
    if(lazy[idx]!=-1)
    {
        tree[2*idx]=tree[2*idx+1]={0,0};
        tree[2*idx][lazy[idx]]=(m-l+1);
        tree[2*idx+1][lazy[idx]]=(r-m);
        lazy[2*idx]=lazy[2*idx+1]=lazy[idx];
        lazy[idx]=-1;
    }
}

void update(int idx,int l,int r,int ql,int qr,int val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx][val]=(r-l+1);
        tree[idx][val^1]=0;
        lazy[idx]=val;
    }
    else
    {
        int m=(l+r)/2;
        push(idx,l,r,m);
        update(2*idx,l,m,ql,min(qr,m),val);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,val);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

array<int,2> query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return {0,0};
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx,l,r,m);
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,q;
        cin >> n >> q;
        string s,f;
        cin >> s >> f;
        s="$"+s;
        f="$"+f;
        vector<int> l(q+1,0);
        vector<int> r(q+1,0);
        for(int i=1;i<=q;i++) cin >> l[i] >> r[i];
        for(int i=1;i<=n;i++) update(1,1,n,i,i,f[i]-'0');
        bool ok=1;
        for(int i=q;i>=1;i--)
        {
            auto [a,b]=query(1,1,n,l[i],r[i]);
            ok&=(a!=b);
            if(a>b) update(1,1,n,l[i],r[i],0);
            else update(1,1,n,l[i],r[i],1);
        }
        for(int i=1;i<=n;i++) ok&=(query(1,1,n,i,i)[s[i]-'0']==1);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}