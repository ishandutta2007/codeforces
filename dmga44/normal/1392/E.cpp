#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

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
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(2e18)
#define pi acos(-1)
#define MAXN (ll)(2e1+5)

ll a[MAXN][MAXN];
ll dp[MAXN][MAXN][2];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!(i+j) || (i+j)==2*n-2)
            {
                cout << '0' << ' ';
                continue;
            }
            else
            {
//                if(i+j<n)
//                    a[i][j]=(1ll<<(2*n-(j)+1-i));
//                else
//                    a[i][j]=(1ll<<max((n-1-i),0));
                a[i][j]=(1ll<<(2*n-(i+j)+1-(i&1)));
            }
            cout << a[i][j] << ' ';
        }
        cout << '\n';
        cout.flush();
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=n-1 || j!=n-1)
                dp[i][j][0]=oo;

    for(int i=2*n-2;i>=0;i--)
    {
//        db("")
//        cout << i << '\n';
        for(int j=0;j<n;j++)
        {
            int k=i-j;
            if(k>=0 && k<n)
            {
                dp[j][k][0]+=a[j][k];
                dp[j][k][1]+=a[j][k];
//                cout << j << ' ' << k << '\n';
//                cout << dp[j][k][0] << ' ' << dp[j][k][1] << '\n';
//                db("")
                if(j)
                {
                    dp[j-1][k][0]=min(dp[j-1][k][0],dp[j][k][0]);
                    dp[j-1][k][1]=max(dp[j-1][k][1],dp[j][k][1]);
                }
                if(k)
                {
                    dp[j][k-1][0]=min(dp[j][k-1][0],dp[j][k][0]);
                    dp[j][k-1][1]=max(dp[j][k-1][1],dp[j][k][1]);
                }
            }
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        ll k;
        cin >> k;
        pii ap=pii(0,0);
//        db(2*n-2);
        for(int tt=0;tt<2*n-1;tt++)
        {
            int i=ap.f;
            int j=ap.s;
            k-=a[i][j];
            cout << i+1 << ' ' << j+1 << '\n';
            cout.flush();
            if(i<n-1 && k>=dp[i+1][j][0] && k<=dp[i+1][j][1])
                i++;
            else
                j++;
            ap=pii(i,j);
        }
    }

    return 0;
}