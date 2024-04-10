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
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

ld res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ld l,v1,v2;
    cin >> n >> l >> v1 >> v2;
    vector<pdi> vp;
    ld add=v2/(v2+v1);
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        ld xx=x;
        xx/=l;
        ld xx2=xx+add;
        vp.push_back(pdi(xx,1));
        vp.push_back(pdi(min(xx2,(ld)2),-1));
        if(xx2>2.0)
        {
            vp.push_back(pdi(0,1));
            vp.push_back(pdi(xx2-2.0,-1));
        }
    }

    sort(all(vp));

    ld last=0;
    int sum=0;
    for(auto y : vp)
    {
        ld t=y.f;
        ll d=y.s;
        res[sum]+=(t-last);
        last=t;
        sum+=d;
    }
//    db(sum)
//    db(last)
    res[sum]+=(2.0-last);

    cout.precision(15);
    cout<<fixed;
    for(int i=0;i<=n;i++)
        db(res[i]/2.0)

    return 0;
}
/**
1 1 1 1
0
2 3 1 2
2 5
**/