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
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

int ask(int x,int y)
{
    cout << "? " << x << ' ' << y << '\n';
    cout.flush();
    int xx;
    cin >> xx;
    return xx;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> res(n+1);
    int p=1;
    for(int i=2;i<=n;i++)
    {
        int x=ask(p,i);
        int y=ask(i,p);
        if(x<y)
            res[i]=y;
        else
        {
            res[p]=x;
            p=i;
        }
    }
    res[p]=n;

    cout << "! ";
    for(int i=1;i<=n;i++)
        cout << res[i] << ' ';
    cout << '\n';
    cout.flush();

    return 0;
}