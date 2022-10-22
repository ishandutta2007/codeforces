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
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> ps;
    vector<int> res(n);
    vector<int> ts(2*n);
    bool ok=1;
    int cont=0;
    for(int i=0;i<2*n;i++)
    {
        char c;
        cin >> c;
        if(c=='-')
        {
            int x;
            cin >> x;
            if(!ps.empty())
            {
                res[ps.top()]=x;
                ps.pop();
            }
            else
                ok=0;
            ts[i]=x;
        }
        else
        {
            ps.push(cont);
            cont++;
        }
    }

    if(!ok)
    {
        db("NO")
        return 0;
    }

    priority_queue<int,vector<int>,greater<int>> pq;
    cont=0;
    for(int i=0;i<2*n;i++)
    {
        if(ts[i])
        {
            ok&=(ts[i]==pq.top());
            pq.pop();
        }
        else
        {
            pq.push(res[cont]);
            cont++;
        }
    }
    if(!ok)
    {
        db("NO")
        return 0;
    }
    else
    {
        db("YES")
        for(auto y : res)
            cout << y << ' ';
        cout << '\n';
    }

    return 0;
}