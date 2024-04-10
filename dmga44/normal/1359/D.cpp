#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN 100005

ll rmq[MAXN][20],lg[MAXN],a[MAXN],ac[MAXN],last[100*MAXN];

int query(int l,int r)
{
    int po=lg[r-l+1];
    return max(rmq[l][po],rmq[r-(1<<po)+1][po]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lg[0]=-1;
    for(int i=1;i<MAXN;i++)
        lg[i]=lg[i-1]+!(i&(i-1));

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
        rmq[i][0]=a[i];
    for(int j=1;j<=lg[n];j++)
        for(int i=0;i+(1<<j)<=n;i++)
            rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);

    for(int i=0;i<100*MAXN;i++)
        last[i]=-1;

    ll mi=0;
    ll add=30*MAXN;
    last[add]=0;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        ac[i+1]=ac[i]+a[i];
//        cout << ac[i+1] << ' ';
        last[add+ac[i+1]]=i+1;
        mi=min(mi,ac[i+1]);
        for(int j=0;j<60;j++)
            if(last[j+add+mi]!=-1)
                res=max(res,ac[i+1]-mi-j-query(last[j+add+mi],i));
    }
    db(res)

    return 0;
}
/**
8
5 2 5 3 -30 -30 6 9
**/