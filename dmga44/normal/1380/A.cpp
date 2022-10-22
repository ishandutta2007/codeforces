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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
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
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

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
        vector<int> p(n);
        for(int i=0;i<n;i++)
            cin >> p[i];
        vector<int> ml(n),mr(n);
        ml[0]=0;
        for(int i=1;i<n-1;i++)
        {
            ml[i]=ml[i-1];
            if(p[ml[i-1]]>p[i])
                ml[i]=i;
        }

        mr[n-1]=n-1;
        for(int i=n-2;i>0;i--)
        {
            mr[i]=mr[i+1];
            if(p[mr[i+1]]>p[i])
                mr[i]=i;
        }

        bool ok=0;
        for(int i=1;i<n-1;i++)
        {
            if(p[i]>p[ml[i]] && p[i]>p[mr[i]])
            {
                ok=1;
                db("YES")
                cout << ml[i]+1 << ' ' << i+1 << ' ' << mr[i]+1 << '\n';
                break;
            }
        }
        if(!ok)
            db("NO")
    }

    return 0;
}