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
typedef long double ld;
typedef pair<int,int> pii;
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
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9+5)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

set<pii> s[MAXN];
vector<ppp> ss;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,w;
    cin >> n >> w;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        s[i].insert(pii(oo,-2));
        sum-=oo;
        int k;
        cin >> k;
        ll x;
        if(2*k<=w)
            ss.push_back(ppp(pii(0,i),pii(0,-1)));
        else if(k!=w)
        {
            ss.push_back(ppp(pii(0,i),pii(0,-1)));
            ss.push_back(ppp(pii(w-k,i),pii(0,-1)));
        }
        for(int j=0;j<k;j++)
        {
            cin >> x;
            ss.push_back(ppp(pii(j,i),pii(x,j)));
            ss.push_back(ppp(pii(j+w-k+1,i),pii(x,j)));
        }
        if(k!=w && 2*k>w)
        {
            ss.push_back(ppp(pii(k,i),pii(0,k)));
            ss.push_back(ppp(pii(w,i),pii(0,k)));
        }
    }

    sort(all(ss));

    int p=0;
    for(int i=0;i<w;i++)
    {
        while(p<ss.size() && ss[p].f.f<=i)
        {
            ppp xxx=ss[p];
            int id=xxx.f.s;
            int v=xxx.s.f;
            int pos=xxx.s.s;
            ll act=(*(s[id].begin())).f;
            sum+=act;
            if(s[id].find(pii(-v,pos))!=s[id].end())
                s[id].erase(pii(-v,pos));
            else
                s[id].insert(pii(-v,pos));
            act=(*(s[id].begin())).f;
            sum-=act;
            p++;
        }

        cout << sum << ' ';
    }
    cout << '\n';

    return 0;
}
/**
3 2
2 1 -1
2 1 -1
2 1 -1
3 0
**/