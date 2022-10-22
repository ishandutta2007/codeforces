#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN 100005

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,x;
        cin >> n;
        vector<int> p[2];
        for(int i=0;i<2*n;i++)
        {
            cin >> x;
            p[x&1].push_back(i+1);
        }

        vector<pii> res;
        for(int i=0;i<(int)(p[0].size())-1;i+=2)
            res.push_back(pii(p[0][i],p[0][i+1]));
        for(int i=0;i<(int)(p[1].size())-1;i+=2)
            res.push_back(pii(p[1][i],p[1][i+1]));
        for(int i=0;i<n-1;i++)
            cout << res[i].f << ' ' << res[i].s << '\n';
    }

    return 0;
}