#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<ll> tree(4*N,0);
vector<int> lazy(4*N,-1);
vector<ll> pre(N,0);
vector<ll> pw(N,1);
const ll mod=1000000007;

void push(int idx,int l,int r,int m)
{
    if(lazy[idx]==-1) return;
    tree[2*idx]=(lazy[idx]*pre[m-l+1])%mod;
    tree[2*idx+1]=(lazy[idx]*pre[r-m])%mod;
    lazy[2*idx]=lazy[2*idx+1]=lazy[idx];
    lazy[idx]=-1;
}

void update(int idx,int l,int r,int ql,int qr,int val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]=(val*pre[r-l+1])%mod;
        lazy[idx]=val;
    }
    else
    {
        int m=(l+r)/2;
        push(idx,l,r,m);
        update(2*idx,l,m,ql,min(qr,m),val);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,val);
        int x=(r-m);
        tree[idx]=(pw[x]*tree[2*idx]+tree[2*idx+1])%mod;
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx,l,r,m);
    ll one=query(2*idx,l,m,ql,min(qr,m));
    ll two=query(2*idx+1,m+1,r,max(ql,m+1),qr);
    int x=max(0,qr-max(ql,m+1)+1);
    return (pw[x]*one+two)%mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    m+=k;
    string s;
    cin >> s;
    s="$"+s;
    for(int i=1;i<N;i++) pw[i]=(pw[i-1]*10)%mod;
    for(int i=1;i<N;i++) pre[i]=(pre[i-1]*10+1)%mod;
    for(int i=1;i<=n;i++) update(1,1,n,i,i,s[i]-'0');
    while(m--)
    {
        int t,l,r,a;
        cin >> t >> l >> r >> a;
        if(t==1) update(1,1,n,l,r,a);
        else
        {
            int sz=a;
            while(2*sz<=r-l+1) sz*=2;
            bool ok=1;
            int d=(r-l+1-sz);
            ok&=(query(1,1,n,l,l+d-1)==query(1,1,n,r-d+1,r));
            while(sz!=a)
            {
                ok&=(query(1,1,n,l,l+sz/2-1)==query(1,1,n,l+sz/2,l+sz-1));
                sz/=2;
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}