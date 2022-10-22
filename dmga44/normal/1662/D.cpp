#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper") // Enable AVX

/// UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
typedef pair<ll, ll> pii;
typedef pair<ld, ll> pdi;
typedef pair<ld, ld> pdd;
typedef pair<ld, pdd> pdp;
typedef pair<string, ll> psi;
typedef pair<ll, string> pls;
typedef pair<string, string> pss;
typedef pair<ll, pii> pip;
typedef pair<pii, pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point, int> ppi;
#define prec(n)        \
    cout.precision(n); \
    cout << fixed
const ll mod = (1e9 + 7);
const ld eps = (1e-9);
const ll oo = (ll)(1e18 + 5);
#define pi acos(-1)
#define MAXN (ll)(1e6 + 5)

// vector<pip> solve(string s)
// {
//     int n=s.size();
//     vector<pip> ans;
//     vector<vector<bool>> dp(n,vector<bool>(n));
//     vector<string> dis={"AA","BB","CC","ABAB","BCBC"};

//     for(int l=2;l<=n;l++)
//         for(int i=0;i+l<=n;i++)
//         {
//             int j=i+l-1;
//             for(auto sx : dis)
//             {
//                 if(sx.size()>l)
//                     continue;
//                 for(int k=0;k<=sx.size();k++)
//                 {
//                     bool ok=1;
//                     for(int p=i;p<i+k;p++)
//                         ok&=(sx[p-i]==s[p]);
//                     for(int p=j;p>j-sx.size()+k;p++)
//                         ok&=(sx[p-(j-sx.size()+1)]==s[p]);
//                     if(!ok)
//                         continue;
//                     dp[i][j]=(sx.size()==l || dp[i])
//                 }
//             }
//         }

//     return ans;
// } 

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string s,t;
        cin >> s >> t;

        for(int i=0;i<s.size();i++)
        {
            for(int j=1;j<s.size();j++)
            {
                if(s[j]=='B' && s[j-1]!='B')
                {
                    swap(s[j],s[j-1]);
                }
            }
        }
        
        for(int i=0;i<t.size();i++)
        {
            for(int j=1;j<t.size();j++)
            {
                if(t[j]=='B' && t[j-1]!='B')
                {
                    swap(t[j],t[j-1]);
                }
            }
        }

        while(1)
        {
            bool ok=0;
            for(int j=1;j<s.size();j++)
                if(s[j]==s[j-1])
                {
                    s=s.substr(0,j-1)+s.substr(j+1,s.size()-(j+1));
                    ok=1;   
                }
            if(!ok)
                break;
        }

        while(1)
        {
            bool ok=0;
            for(int j=1;j<t.size();j++)
                if(t[j]==t[j-1])
                {
                    t=t.substr(0,j-1)+t.substr(j+1,t.size()-(j+1));
                    ok=1;   
                }
            if(!ok)
                break;
        }
        if(s==t)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}