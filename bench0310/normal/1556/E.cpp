#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<ll> tree(4*N,0);
vector<ll> tree2(4*N,0);
vector<ll> c(N,0);
vector<ll> sum(N,0);
const ll inf=(1ll<<60);

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=tree2[idx]=sum[l];
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
        tree2[idx]=min(tree2[2*idx],tree2[2*idx+1]);
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return -inf;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

ll query2(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return inf;
    if(l==ql&&r==qr) return tree2[idx];
    int m=(l+r)/2;
    return min(query2(2*idx,l,m,ql,min(qr,m)),query2(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<ll> b(n+1,0);
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++)
    {
        c[i]=a[i]-b[i];
        sum[i]=sum[i-1]+c[i];
    }
    cout << endl;
    build(1,1,n);
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        if(sum[r]-sum[l-1]==0&&query(1,1,n,l,r)-sum[l-1]<=0)
        {
            cout << -(query2(1,1,n,l,r)-sum[l-1]) << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}