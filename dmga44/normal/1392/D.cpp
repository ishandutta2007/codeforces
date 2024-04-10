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
#define MAXN (ll)(2e5+5)

char a[2*MAXN];

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
        bool ok=1;
        string s;
        cin >> s;
        for(int i=0;i<n;i++)
        {
            ok&=(s[i]==s[0]);
            a[i]=a[i+n]=s[i];
        }

        if(ok)
            db((n+2)/3)
        else
        {
            int ini=1;
            while(a[ini]==a[ini-1])
                ini++;
            int sz=0;
            char c='7';
            int res=0;
            for(int i=ini;i<ini+n;i++)
            {
                if(c!=a[i])
                {
                    res+=sz/3;
                    sz=0;
                }
                c=a[i];
                sz++;
            }
            res+=sz/3;
            db(res)
        }
    }

    return 0;
}
/**
5
4
RLRL
6
LRRRRL
8
RLLRRRLL
12
LLLLRRLRRRLL
5
RRRRR
**/