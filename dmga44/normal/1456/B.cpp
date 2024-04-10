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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    int ans=1e6;
    vector<int> sup(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<30;j++)
            if(a[i]&(1<<j))
                sup[i]=j;

//    db("xxx")
    bool ok=0;
    for(int i=0;i<n-2;i++)
        if(sup[i]==sup[i+1] && sup[i]==sup[i+2])
            ok=1;
    if(ok)
    {
        db(1)
        return 0;
    }

    vector<vector<int>> xs(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        xs[i][i]=a[i];
        for(int j=i+1;j<n;j++)
            xs[i][j]=xs[i][j-1]^a[j];
    }

    for(int i=0;i<n-1;i++)
        for(int j=0;j<=i;j++)
            for(int k=i+1;k<n;k++)
                if(xs[j][i]>xs[i+1][k])
                    ans=min(ans,k-j-1);

    if(ans==1e6)
        db(-1)
    else
        db(ans)

    return 0;
}