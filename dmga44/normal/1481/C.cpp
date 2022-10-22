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
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(n);
        vector<pii> ba[n+1];
        vector<int> c[n+1];
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            b[i]=x;
            ba[x].push_back(pii(x==a[i],i));
        }
//        db("xxx")

        vector<int> xx(m);
        for(int i=0;i<m;i++)
        {
            int x;
            cin >> x;
            xx[i]=x;
            c[x].push_back(i);
        }
        for(int i=1;i<=n;i++)
            sort(all(ba[i]));

        vector<int> res(m);
        bool ok=(ba[xx[m-1]].size()!=0);
//        cout << n << ' ' << m << '\n';
        if(!ok)
        {
            db("NO")
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            reverse(all(c[i]));
            if(ba[i].empty())
            {
                if(c[i].size())
                {
                    for(auto x : c[i])
                        res[x]=ba[xx[m-1]][0].s;
                }
            }
            else
            {
                if(c[i].empty())
                    continue;
                for(int j=0;j<c[i].size();j++)
                {
                    int pos=ba[i][0].s;
                    if(j<ba[i].size())
                        pos=ba[i][j].s;
                    res[c[i][j]]=pos;
                    a[pos]=i;
                }
            }

        }
        for(int i=0;i<n;i++)
            ok&=(a[i]==b[i]);
        if(ok)
        {
            db("YES")
            for(int i=0;i<m;i++)
                cout << res[i]+1 << ' ';
            cout << '\n';
        }
        else
            db("NO")
    }

    return 0;
}