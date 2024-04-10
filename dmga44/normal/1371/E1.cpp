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
typedef pair<point,int> ppi;
#define mod (int)(1e4+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,p;
    cin >> n >> p;
    int ma=0;
    int mi=1e9;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    sort(all(v));
    for(int i=0;i<n;i++)
    {
        int a=v[i];
        ma=max(ma,a-i);
        if(i>=p-1)
            mi=min(mi,a+p-(i+1));
    }

    vector<int> res;
    for(int i=ma;i<mi;i++)
        res.push_back(i);
    db(res.size())
    for(auto y : res)
        cout << y << ' ';
    cout << '\n';

    return 0;
}