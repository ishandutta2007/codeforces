#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

ll mi[MAXN];
ll lr[MAXN][2];
ll a[MAXN];
ll dp[MAXN];
ll ini[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen(".in","r",stdin);

    ll n,k;
    cin >> n >> k;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> lr[i][0] >> lr[i][1] >> a[i];
        ini[i]=a[i];
        sum+=a[i];
    }

    bool ok=1;
    for(int i=n-1;i>=0 && ok;i--)
    {
        ll extra=0;
        if(lr[i][1]==lr[i+1][0])
            extra=mi[i+1];
        if(lr[i][0]==lr[i][1])
            mi[i]=extra+a[i];
        else
        {
            a[i]-=(k-extra);
            a[i]-=k*(lr[i][1]-lr[i][0]-1);
            mi[i]=a[i];
        }
        if(mi[i]>k)
            ok=0;
        mi[i]=max(mi[i],0ll);
//        cout << i << ' ' << mi[i] << '\n';
    }

    if(!ok)
    {
        db(-1)
        return 0;
    }

    for(int i=0;i<MAXN;i++)
        dp[i]=oo;
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            a[j]=ini[j];
        ///start with k
        ll act=k;
//        db("")
        for(int j=i;j<n;j++)
        {
//            cout << i << ' ' << j << ' ' << act << ' ' << mi[j] << '\n';
            if(act<mi[j])
                break;
            if(j==n-1)
            {

//                cout << i << ' ' << dp[i] << '\n';
                dp[n]=min(dp[i],dp[n]);
                continue;
            }
            if(lr[j+1][0]>lr[j][1])
            {
//                db(a[j])
//                db(act)
                ll x=min(a[j],act);
                a[j]-=x;
                act-=x;
//                db(act)
                if(a[j])
                    act=(k-(a[j]%k))%k;
//                db(act)
//                if(act==0 || act>=mi[j+1])
                    dp[j+1]=min(dp[i]+act,dp[j+1]);
                if(act==0)
                    act=k;
                continue;
            }
            else
            {
                if(lr[j][0]<lr[j][1])
                {
                    ll x=min(a[j],act);
                    a[j]-=x;
                    act-=x;
//                    cout << act << ' ' << a[j] << '\n';
                    if(a[j]<=(lr[j][1]-lr[j][0]-1)*k)
                    {
                        if(a[j])
                            act=(k-(a[j]%k))%k;
//                        if(act==0 || act>=mi[j+1])
                            dp[j+1]=min(dp[i]+act,dp[j+1]);
                        if(act==0)
                            act=k;
                    }
                    else
                        act=k-(a[j]-((lr[j][1]-lr[j][0]-1)*k));
                }
                else
                {
                    act-=a[j];
                    a[j]=0;
                }
            }
        }
    }
//    for(int i=0;i<=n;i++)
//        cout << dp[i] << ' ';
//    cout << '\n';
    if(dp[n]<1e16)
        db(sum+dp[n])
    else
        db(-1)

    return 0;
}