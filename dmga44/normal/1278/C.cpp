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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> ty(2*n);
        for(int i=0;i<2*n;i++)
            cin >> ty[i];
        vector<int> ac(n+1);
        map<int,int> last;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            ac[i]=sum;
            if(ty[i]==1)
                sum++;
            else
                sum--;
        }
        ac[n]=sum;

        sum=0;
        for(int i=2*n-1;i>=n;i--)
        {
            last[sum]=i+1;
            if(ty[i]==2)
                sum++;
            else
                sum--;
        }
        last[sum]=n;

        int res=1e6;
        for(int i=0;i<=n;i++)
        {
            int l=last[ac[i]];
            if(!l)
                continue;
            res=min(res,l-i);
        }
        db(res)
    }

    return 0;
}