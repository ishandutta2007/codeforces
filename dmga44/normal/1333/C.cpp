#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

ll a[MAXN],ac[MAXN],p[MAXN],rmq[MAXN][18],lg[MAXN];
map<ll,int> last;

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
    last[0]=1;
    for(int i=0;i<n;i++)
    {
        p[i]=-1;
        cin >> a[i];
        ac[i+1]=ac[i]+a[i];
        if(last[ac[i+1]])
            p[i]=last[ac[i+1]]-1;
        last[ac[i+1]]=i+2;
//        cout << p[i] << ' ';
    }
//    cout << '\n';

    for(int i=0;i<n;i++)
        rmq[i][0]=p[i];
    for(int j=1;j<=lg[n];j++)
        for(int i=0;i+(1<<j)<=n;i++)
            rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);

    ll res=0;
    for(int i=0;i<n;i++)
    {
        int lim=i;
        for(int po=(1<<lg[n]);po;po>>=1)
        {
//            cout << lim+po << ' ' << query(i,lim+po) << '\n';
            if(lim+po<n && query(i,lim+po)<i)
                lim+=po;
        }
        res+=lim-i+(a[i]!=0);
    }
    db(res)

    return 0;
}
/**

**/