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
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,x,y;
        cin >> n >> x >>y;
        vector<int> divs;
        for(int i=1;i<=(y-x);i++)
            if((y-x)%i==0)
                divs.push_back(i);
        int ini,d;
        for(int i=y;1;i++)
        {
            pii res=pii(-1,-1);
            for(auto v : divs)
                if((i-y)%v==0 && i-(n-1)*v>0 && i-(n-1)*v<=x)
                    res=pii(i,v);
            if(res.first!=-1)
            {
                ini=i-(n-1)*res.s;
                d=res.s;
                break;
            }
        }

        for(int i=0;i<n;i++)
            cout << ini+i*d << ' ';
        cout << '\n';
    }

    return 0;
}