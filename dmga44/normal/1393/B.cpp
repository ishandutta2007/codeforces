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
#define MAXN (ll)(2e5+5)

vector<int> fs(MAXN);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    set<pii,greater<pii>> s;
    for(int i=0;i<MAXN;i++)
        s.insert(pii(0,i));
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        s.erase(pii(fs[x],x));
        fs[x]++;
        s.insert(pii(fs[x],x));
    }

    int q;
    cin >> q;
    while(q--)
    {
        char ty;
        cin >> ty;
        int v;
        cin >> v;
        s.erase(pii(fs[v],v));
        if(ty=='+')
            fs[v]++;
        else
            fs[v]--;
        s.insert(pii(fs[v],v));

        ///check
        vector<int> cs;
        auto it=s.begin();
        for(int i=0;i<3;i++)
        {
            cs.push_back((*it).first);
//            cout << (*it).first << '\n';
            it++;
        }
        bool ok=1;
        if(cs[0]<4)
            ok=0;
        cs[0]-=4;
        sort(allr(cs));
        ok&=(cs[1]>=2 || cs[0]>=4);
        if(ok)
            db("YES")
        else
            db("NO")
    }
    return 0;
}
/**
6
1 1 1 2 1 1
6
+ 2
+ 1
- 1
+ 2
- 1
+ 2
**/