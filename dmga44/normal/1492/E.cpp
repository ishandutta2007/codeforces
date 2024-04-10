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
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];

    vector<vector<pii>> pos;
    for(int i=1;i<n;i++)
    {
        vector<int> difs;
        for(int j=0;j<m;j++)
            if(a[0][j]!=a[i][j])
                difs.push_back(j);
        if(difs.size()>2)
        {
            if(difs.size()>4)
            {
                db("No")
                return 0;
            }
            if(difs.size()==4)
            {
                pos.clear();
                for(int p1=0;p1<4;p1++)
                    for(int p2=p1+1;p2<4;p2++)
                        pos.push_back({pii(difs[p1],a[i][difs[p1]]),pii(difs[p2],a[i][difs[p2]])});
            }
            if(difs.size()==3)
            {
                pos.clear();
                for(int p1=0;p1<3;p1++)
                    pos.push_back({pii(difs[p1],a[i][difs[p1]])});
            }
        }
        if(difs.size()==4)
        {
            for(auto ops : pos)
            {
                vector<int> kk=a[0];
                for(auto p : ops)
                    kk[p.f]=p.s;
                bool ok=1;
                for(int i=0;i<n;i++)
                {
                    int difs=0;
                    for(int j=0;j<m;j++)
                        if(kk[j]!=a[i][j])
                            difs++;
                    ok&=(difs<=2);
                }
                if(ok)
                {
                    db("Yes")
                    for(auto x : kk)
                        cout << x << ' ';
                    cout << '\n';
                    return 0;
                }
            }
            db("No")
            return 0;
        }
    }

    if(pos.empty())
    {
        db("Yes")
        for(int i=0;i<m;i++)
            cout << a[0][i] << ' ';
        cout << '\n';
        return 0;
    }

    vector<int> pool;
    for(auto p : pos)
        pool.push_back(p[0].f);
    for(auto ops : pos)
    {
        vector<int> kk=a[0];
        for(auto p : ops)
            kk[p.f]=p.s;
        vector<vector<int>> difs(m);
        bool ok=1;
        bool hay=0;
        for(int i=0;i<n;i++)
        {
            int diffs=0;
            for(int j=0;j<m;j++)
                if(kk[j]!=a[i][j])
                    diffs++;
            ok&=(diffs<4);
            if(diffs==3)
            {
                hay=1;
                for(auto p : pool)
                    if(kk[p]!=a[i][p])
                        difs[p].push_back(a[i][p]);
            }
        }
        if(!ok)
            continue;
        if(!hay)
        {
            db("Yes")
            for(auto x : kk)
                cout << x << ' ';
            cout << '\n';
            return 0;
        }
        vector<int> oks;
        for(auto p : pool)
        {
            if(difs[p].empty())
                continue;
            bool ok=1;
            for(auto x : difs[p])
                ok&=(x==difs[p][0]);
            if(ok)
                oks.push_back(p);
        }
        for(auto p : oks)
        {
            vector<int> kkk=kk;
            kkk[p]=difs[p][0];
            bool ok=1;
            for(int i=0;i<n;i++)
            {
                int difs=0;
                for(int j=0;j<m;j++)
                    if(kkk[j]!=a[i][j])
                        difs++;
                ok&=(difs<=2);
            }
            if(!ok)
                continue;
            db("Yes")
            for(auto x : kkk)
                cout << x << ' ';
            cout << '\n';
            return 0;
        }
    }
    db("No")

    return 0;
}
/**
6 5
1 1 1 1 1
2 2 2 1 1
1 2 2 2 1
1 1 2 2 2
1 1 1 2 2
1 1 1 1 2
**/