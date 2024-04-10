#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

using M=array<array<ll,2>,2>;
const ll inf=(1ll<<60);
const int N=100005;
vector<M> ini(N);
vector<M> d(N);
vector<M> tree(4*N);

M go(M a,M b,M c)
{
    M res={array<ll,2>{inf,inf},array<ll,2>{inf,inf}};
    for(int i=0;i<2;i++)
    {
        for(int l=0;l<2;l++)
        {
            for(int r=0;r<2;r++)
            {
                for(int j=0;j<2;j++)
                {
                    res[i][j]=min(res[i][j],a[i][l]+b[l][r]+c[r][j]);
                }
            }
        }
    }
    return res;
}

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=ini[l];
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=go(tree[2*idx],d[m],tree[2*idx+1]);
    }
}

M query(int idx,int l,int r,int ql,int qr)
{
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    if(qr<=m) return query(2*idx,l,m,ql,qr);
    if(m+1<=ql) return query(2*idx+1,m+1,r,ql,qr);
    return go(query(2*idx,l,m,ql,m),d[m],query(2*idx+1,m+1,r,m+1,qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> eu(n+1);
    vector<array<int,2>> er(n+1);
    for(int i=1;i<n;i++) cin >> eu[i][0] >> eu[i][1] >> er[i][0] >> er[i][1];
    auto mdist=[&](array<int,2> a,array<int,2> b)->int{return (abs(a[0]-b[0])+abs(a[1]-b[1]));};
    auto udoor=[&](array<int,2> a)->array<int,2>{return {a[0]+1,a[1]};};
    auto rdoor=[&](array<int,2> a)->array<int,2>{return {a[0],a[1]+1};};
    for(int i=1;i+1<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                d[i][j][k]=1+mdist((j==0?udoor(eu[i]):rdoor(er[i])),(k==0?eu[i+1]:er[i+1]));
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        ini[i][0][0]=ini[i][1][1]=0;
        ini[i][0][1]=ini[i][1][0]=mdist(eu[i],er[i]);
    }
    build(1,1,n-1);
    int q;
    cin >> q;
    while(q--)
    {
        array<int,2> a,b;
        cin >> a[0] >> a[1] >> b[0] >> b[1];
        int la=max(a[0],a[1]);
        int lb=max(b[0],b[1]);
        if(la>lb)
        {
            swap(a,b);
            swap(la,lb);
        }
        if(la==lb) cout << mdist(a,b) << "\n";
        else
        {
            M opt=query(1,1,n-1,la,lb-1);
            ll res=inf;
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<2;j++)
                {
                    res=min(res,mdist(a,(i==0?eu[la]:er[la]))+opt[i][j]+1+mdist((j==0?udoor(eu[lb-1]):rdoor(er[lb-1])),b));
                }
            }
            cout << res << "\n";
        }
    }
    return 0;
}