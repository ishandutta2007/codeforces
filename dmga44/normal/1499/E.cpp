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
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

ll dp[MAXN][MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string x;
    string y;
    cin >> x >> y;
    int n=x.size();
    int m=y.size();
    vector<int> ax(n);
    vector<int> ay(m);
    for(int i=0;i<n;i++)
    {
        ax[i]=1;
        if(i && x[i-1]!=x[i])
            ax[i]=ax[i-1]+1;
    }
    for(int i=0;i<m;i++)
    {
        ay[i]=1;
        if(i && y[i-1]!=y[i])
            ay[i]=ay[i-1]+1;
    }

    ll res=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            ///0:i->j
            if(x[i]!=y[j])
                dp[i][j][0]=ax[i];
            if(j)
            {
                if(x[i]!=y[j])
                    dp[i][j][0]=(dp[i][j][0]+dp[i][j-1][1])%mod;
                if(y[j-1]!=y[j])
                    dp[i][j][0]=(dp[i][j][0]+dp[i][j-1][0])%mod;
            }
            ///1:j->i
            if(x[i]!=y[j])
                dp[i][j][1]=ay[j];
            if(i)
            {
                if(x[i]!=y[j])
                    dp[i][j][1]=(dp[i][j][1]+dp[i-1][j][0])%mod;
                if(x[i-1]!=x[i])
                    dp[i][j][1]=(dp[i][j][1]+dp[i-1][j][1])%mod;
            }
            res=(res+dp[i][j][0]+dp[i][j][1])%mod;
        }
    db(res)

    return 0;
}