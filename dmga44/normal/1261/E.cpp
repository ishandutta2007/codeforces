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
typedef unsigned long long ull;
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
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(998244353)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

char res[MAXN][MAXN];
int a[MAXN];

void solve(vector<vector<int> > vp)
{
    int p=vp.size()-1;
    int d=-1;
    for(int i=0;i<=p;i++)
        if(vp[i].size()>1)
            d=i;
    if(d==-1)
        return;
    vector<vector<int> > np;
    for(int i=0;i<=p;i++)
    {
        if(i==d)
            continue;
        for(auto y : vp[i])
            if(a[p]>=2)
            {
                res[y][p]='1';
                a[p]--;
            }
        np.push_back(vp[i]);
    }

    vector<int> m1,m2;
    for(int i=0;i<a[p];i++)
    {
        m1.push_back(vp[d][i]);
        res[vp[d][i]][p]='1';
    }
    for(int i=a[p];i<vp[d].size();i++)
        m2.push_back(vp[d][i]);
    np.push_back(m1);
    np.push_back(m2);
    solve(np);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n+1;i++)
        for(int j=0;j<n;j++)
            res[i][j]='0';

    for(int i=0;i<n;i++)
        cin >> a[i];

    vector<vector<int>> vp(1,vector<int>(n+1));
    for(int i=0;i<n+1;i++)
        vp[0][i]=i;
    solve(vp);

    db(n+1)
    for(int i=0;i<n+1;i++,cout<<'\n')
        for(int j=0;j<n;j++)
            cout << res[i][j];

    return 0;
}