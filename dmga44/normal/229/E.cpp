#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
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
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

ld pas[MAXN][MAXN];

ld comb(int n,int m)
{
    return pas[n+1][m+1];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pas[0][0]=1;
    for(int i=1;i<MAXN;i++)
        for(int j=1;j<=i;j++)
            pas[i][j]=pas[i-1][j-1]+pas[i-1][j];

    int n,m;
    cin >> n >> m;
    map<int,vector<int>> fs;
    vector<int> a[m];
    for(int i=0;i<m;i++)
    {
        int k;
        k=1;
        cin >> k;
        for(int j=0;j<k;j++)
        {
            int x;
            x=1;
            cin >> x;
            a[i].push_back(x);
            fs[-x].push_back(-i);
        }
        sort(allr(a[i]));
    }

    int extra=n;
    int lim=-1;
    for(auto y : fs)
    {
        int v=-y.first;
        auto ids=y.second;
        if(extra>ids.size())
        {
            extra-=ids.size();
            continue;
        }
        else if(extra==ids.size())
        {
            extra=0;
            lim=v-1;
            break;
        }
        else
        {
            lim=v;
            break;
        }
    }
    // cout << lim << '\n';

    vector<ld> ans(1,1);
    for(int i=0;i<m;i++)
    {
        int cant=0;
        bool hay=0;
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j]>lim)
                cant++;
            else if(a[i][j]==lim)
                hay=1;
            else
                break;
        }
        // cout << cant << ' ' << hay << '\n';
        ld v1=1.0/comb(a[i].size(),cant);
        ld v2=0;
        if(hay)
            v2=1.0/comb(a[i].size(),cant+1);
        // cout << v1 << ' '<< v2 << '\n';
        vector<ld> nans(ans.size()+1);
        for(int j=0;j<ans.size();j++)
        {
            nans[j]+=ans[j]*v1;
            nans[j+1]+=ans[j]*v2;
        }
        ans=nans;
        // for(int i=0;i<ans.size();i++)
        //     cout << ans[i] << ' ';
        // cout << '\n';
        // cout << '\n';
    }
    prec(10);
    ld mul=1;
    if(extra)
        mul=1/comb(fs[-lim].size(),extra);
    // db(mul)
    cout << ans[extra]*mul << '\n';

    return 0;   
}