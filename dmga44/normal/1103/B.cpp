#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1<<24)

bool ask(int x,int y)
{
    cout << "? " << x << ' ' << y << '\n';
    cout.flush();
    char c;
    cin >> c;
    return c=='x';
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    string s;
    cin >> s;
    while(s=="start")
    {
        if(ask(0,1))
        {
            cout << "! 1\n";
            cout.flush();
            cin >> s;
            continue;
        }
        ll lim=2;
        while(ask(lim,lim/2))
            lim*=2;
        ll res=lim/2;
        for(ll po=(1ll<<31);po;po>>=1)
            if(res+po<lim && !ask(lim,res+po))
                res+=po;
        res++;
        cout << "! " << res << '\n';
        cout.flush();
        cin >> s;
    }

    return 0;
}