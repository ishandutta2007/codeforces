#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 3505

int a[MAXN],ma[MAXN];
int rmq[MAXN][14],lg[MAXN];

int query(int l,int r)
{
    int p=lg[r-l+1];
    return min(rmq[l][p],rmq[r-(1<<p)+1][p]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lg[0]=-1;
    for(int i=1;i<MAXN;i++)
        lg[i]=lg[i-1]+!(i&(i-1));

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        for(int i=0;i<n;i++)
            cin >> a[i];
        int sz=n-m;
        for(int i=0;i+sz<n;i++)
            ma[i]=max(a[i],a[i+sz]);

        for(int i=0;i+sz<n;i++)
            rmq[i][0]=ma[i];
        for(int j=1;j<=lg[n-sz+1];j++)
            for(int i=0;i+(1<<j)<=n-sz+1;i++)
                rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);

        int left=max(0,m-k-1);
        int res=0;
        for(int i=0;i<=min(m-1,k);i++)
            res=max(res,query(i,i+left));
        db(res)

        for(int i=0;i<n;i++)
        {
            a[i]=0;
            ma[i]=0;
            for(int j=0;j<14;j++)
                rmq[i][j]=0;
        }
    }

    return 0;
}