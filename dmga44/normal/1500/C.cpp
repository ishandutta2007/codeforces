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
#define MAXN (ll)(1.5e3+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen(".in","r",stdin);

    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    vector<vector<int>> b(n,vector<int>(m));
    vector<vector<int>> tsa(n,vector<int>(m+1));
    vector<vector<int>> tsb(n,vector<int>(m+1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
            tsa[i][j]=a[i][j];
        }
        tsa[i][m]=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> b[i][j];
            tsb[i][j]=b[i][j];
        }
        tsb[i][m]=i;
    }

    sort(all(tsa));
    sort(all(tsb));

    bool okk=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            okk&=(tsa[i][j]==tsb[i][j]);

    if(!okk)
    {
        db(-1)
        return 0;
    }

    vector<int> pa(n);
    vector<int> pb(n);
    for(int i=0;i<n;i++)
    {
        pa[tsa[i][m]]=i;
        pb[tsb[i][m]]=i;
//        cout << tsa[i][m] << ' ' << tsb[i][m] << '\n';
    }

    set<int> act[MAXN];
    set<int> pre[MAXN];
    vector<int> f(m);
    vector<bool> mk(m);
    set<int> oblig[MAXN];
    vector<bool> ok(n);
    for(int i=1;i<n;i++)
    {
        int p1=tsa[pb[i-1]][m];
        int p2=tsa[pb[i]][m];
//        db("")
//        cout << i << ' ' << p1 << ' ' << p2 << '\n';
        for(int j=0;j<m;j++)
        {
            if(a[p1][j]<a[p2][j])
                oblig[i].insert(j);
            if(a[p1][j]<=a[p2][j])
                act[i].insert(j);
            else
                pre[i].insert(j);
        }
        if(p1<p2)
        {
            if(oblig[i].empty())
            {
                ok[i]=1;
                pre[i].clear();
            }
        }
        else
        {
            if(oblig[i].empty())
            {
//                db("xxx")
                db(-1)
                return 0;
            }
        }
//        db("act")
//        for(auto v : act[i])
//            cout << v << ' ';
//        cout << '\n';
//        db("oblig")
//        for(auto v : oblig[i])
//            cout << v << ' ';
//        cout << '\n';
//        db("pre")
//        for(auto v : pre[i])
//            cout << v << ' ';
//        cout << '\n';
        for(auto v : act[i])
            f[v]++;
    }

    vector<int> ans;
    while(1)
    {
        int tar=-1;
        for(int i=0;i<m;i++)
            if(f[i]==n-1 && !mk[i])
                tar=i;
        if(tar==-1)
            break;
        ans.push_back(tar+1);
        mk[tar]=1;
        for(int i=1;i<n;i++)
        {
            act[i].erase(tar);
            if(oblig[i].count(tar))
                ok[i]=1;
            if(act[i].empty() || oblig[i].count(tar))
            {
                for(auto v : pre[i])
                {
                    act[i].insert(v);
                    f[v]++;
                }
                pre[i].clear();
            }
        }
    }

    bool kk=1;
    for(int i=1;i<n;i++)
        kk&=ok[i];
    if(!kk)
    {
        db(-1)
        return 0;
    }

    reverse(all(ans));
    db(ans.size())
    for(auto v : ans)
        cout << v << ' ';
    cout << '\n';

    return 0;
}