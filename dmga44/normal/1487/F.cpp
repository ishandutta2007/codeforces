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
const ll mod=(ll)(2e9+99);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e1+5)

ll dp[MAXN][1205][120];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    reverse(all(s));
    s.push_back('0');
    s.push_back('0');
    int n=s.size();
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<1205;j++)
            for(int k=0;k<120;k++)
                dp[i][j][k]=oo;
    for(int i=0;i<1205;i++)
        if(i%10==s[0]-'0')
            dp[0][i][60]=0;
//    db(dp[0][601][60])
    for(int i=0;i<n;i++)
        for(int j=0;j<1205;j++)
            for(int k=0;k<120;k++)
            {
                if(dp[i][j][k]>1e17)
                    continue;
                if((j+k)%10!=s[i]-'0')
                    continue;
                for(int l=-9;l<10;l++)
                {
                    int act=j-l;
                    if(act<0 || act>=1205)
                        continue;
                    dp[i+1][act][(j+k-60)/10]=min(dp[i+1][act][(j+k-60)/10],dp[i][j][k]+abs(l)*(i+1));
//                    if(i==0 && j==601 && k==60)
//                    {
//                        cout << act << ' ' << l << ' ' << (j+k-60)/10 << ' ' << dp[i+1][act][(j+k-60)/10] << '\n';
//                    }
                }
            }
//    db(dp[0][600-10][60])
//    db(dp[1][600-11][60-1])
//    db(dp[2][600-7][60-2])
//    db(dp[3][600-2][60-1])
//    db(dp[4][600-1][60-1])
//    db(dp[5][600+1][60-1])
//    db(dp[6][600][60])
    db(dp[n][600][60])

    return 0;
}
/**
87180
**/