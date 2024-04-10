#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int fb[26];
int fc[26];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string p,h;
        cin >> p >> h;
        int n=p.size();
        int m=h.size();
        if(n>m)
        {
            db("NO")
            continue;
        }
        for(int i=0;i<26;i++)
            fb[i]=fc[i]=0;
        for(int i=0;i<n;i++)
            fb[p[i]-'a']++;
        bool ok=0;
        for(int i=0;i<=m-n;i++)
        {
            for(int j=0;j<n;j++)
                fc[h[i+j]-'a']++;
            bool kk=1;
            for(int j=0;j<26;j++)
            {
                kk&=(fc[j]==fb[j]);
                fc[j]=0;
            }
            ok|=kk;
        }
        if(ok)
            db("YES")
        else
            db("NO")
    }

    return 0;
}