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
#define MAXN (ll)(5e3+5)

int solve(vector<int>& a)
{
    int n=a.size();
    vector<int> f[33];
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        int p=0;
        while(x)
        {
            x/=2;
            p++;
        }
        f[p].push_back(a[i]);
    }

    int res=0;
    vector<int> ap;
    for(int i=32;i>=0;i--)
        if(f[i].size())
            ap.push_back(i);
    reverse(all(ap));
    for(int i=0;i<ap.size();i++)
    {
        if(ap[i]==0)
            res=max(res,(int)ap.size());
        else
        {
            for(auto &y : f[ap[i]])
                y^=(1<<(ap[i]-1));
            res=max(res,solve(f[ap[i]])+(int)ap.size()-i-1+(min(1,i)));
        }
    }

//    for(auto y : a)
//        cout << y << ' ';
//    cout << '\n';
//    db(res)
//    db("")
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    db(n-solve(a))

    return 0;
}