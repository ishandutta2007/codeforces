#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128_t int128;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2.5e3+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string ss;
        cin >> ss;
        int ta=0,tb=0,tc=0;
        for(int i=0;i<n/2;i++)
        {
            if(ss[i]!=ss[n-i-1])
                ta++;
            if(ss[i]==ss[n-i-1] && ss[i]=='0')
                tb++;
        }
        if(n&1 && ss[n/2]=='0')
            tc++;
        int act=0;
        vector<int> s(2);
        if(tb)
        {
            if(tc+ta)
            {
                s[0]+=1;
                s[1]+=tc+ta-1;
                s[1]+=2;
            }
            else
            {
                s[0]=2;
            }
        }
        else
        {
            s[1]+=ta;
            s[0]+=tc;
        }
        if(s[0]<s[1])
            db("ALICE")
        if(s[0]>s[1])
            db("BOB")
        if(s[0]==s[1])
            db("DRAW")
    }

    return 0;
}