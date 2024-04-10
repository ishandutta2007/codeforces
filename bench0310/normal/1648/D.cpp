#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N=500005;
const ll inf=(1ll<<60);
vector<ll> tree(4*N,-inf);

void update(int idx,int l,int r,int pos,ll val)
{
    if(l==r) tree[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return -inf;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

struct obj
{
    ll mxa=-inf,mxb=-inf,best=-inf;
    void ini(ll a,ll b){mxa=a;mxb=b;best=a+b;}
    void pull(obj l,obj r)
    {
        mxa=max(l.mxa,r.mxa);
        mxb=max(l.mxb,r.mxb);
        best=max({l.best,r.best,l.mxa+r.mxb});
    }
};

vector<obj> tree2(4*N);
vector<array<ll,2>> opt(N);

void build2(int idx,int l,int r)
{
    if(l==r) tree2[idx].ini(opt[l][0],opt[l][1]);
    else
    {
        int m=(l+r)/2;
        build2(2*idx,l,m);
        build2(2*idx+1,m+1,r);
        tree2[idx].pull(tree2[2*idx],tree2[2*idx+1]);
    }
}

obj query2(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return obj();
    if(l==ql&&r==qr) return tree2[idx];
    int m=(l+r)/2;
    obj tmp;
    tmp.pull(query2(2*idx,l,m,ql,min(qr,m)),query2(2*idx+1,m+1,r,max(ql,m+1),qr));
    return tmp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector s(4,vector(n+1,ll(0)));
    for(int j=1;j<=3;j++)
    {
        for(int i=1;i<=n;i++)
        {
            cin >> s[j][i];
            s[j][i]+=s[j][i-1];
        }
    }
    vector<ll> one(n+1,0);
    vector<ll> two(n+1,0);
    for(int i=1;i<=n;i++)
    {
        one[i]=s[1][i]-s[2][i-1];
        two[i]=s[3][n]-s[3][i-1]+s[2][i];
    }
    vector<ll> dp(n+1,-inf);
    vector<array<int,2>> v[n+1];
    for(int i=1;i<=q;i++)
    {
        int l,r,k;
        cin >> l >> r >> k;
        v[r].push_back({l,k});
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=max(dp[i],one[i]);
        update(1,1,n,i,dp[i]);
        for(auto [l,k]:v[i]) if(i<n) dp[i+1]=max(dp[i+1],query(1,1,n,l,i)-k);
        opt[i]={dp[i],two[i]};
    }
    build2(1,1,n);
    ll res=-inf;
    for(int r=1;r<=n;r++) for(auto [l,k]:v[r]) res=max(res,query2(1,1,n,l,r).best-k);
    cout << res << "\n";
    return 0;
}