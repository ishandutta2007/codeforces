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
typedef unsigned long long ll;
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
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

int dp[2][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;
    if(n<12)
    {
        dp[0][0]=1;
        vector<int> vs;
        vs.push_back(1);
        vs.push_back(5);
        vs.push_back(10);
        vs.push_back(50);
        for(int i=0;i<n;i++)
        {
            int act=i&1;
            int ne=1-act;
            for(int j=0;j<=50*i;j++)
                if(dp[act][j])
                    for(auto y : vs)
                        dp[ne][j+y]=1;
            for(int j=0;j<=50*i;j++)
                dp[act][j]=0;
        }

        int cant=0;
        for(int j=0;j<=50*n;j++)
        {
            if(dp[n&1][j])
                cant++;
            dp[n&1][j]=0;
        }
        db(cant)
    }
    if(n>=12)
        db((n-12ll)*49ll+341ll)

    return 0;
}