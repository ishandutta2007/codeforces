#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];

    vector<ll> ac;
    ac.push_back(0);
    for(int i=0;i<n;i++)
        ac.push_back(ac.back()+a[i]*b[i]);
    ll add=0;
    for(int i=0;i<n;i++)
    {
        int k=min(i,n-i-1);
        ll sum=a[i]*b[i];
        for(int j=1;j<=k;j++)
        {
            sum+=a[i-j]*b[i+j];
            sum+=a[i+j]*b[i-j];
            add=max(add,sum-ac[i+j+1]+ac[i-j]);
        }
    }
    for(int i=1;i<n;i++)
    {
        int k=min(i,n-i);
        ll sum=0;
//        cout << i << ' ' << k << '\n';
        for(int j=1;j<=k;j++)
        {
            sum+=a[i-j]*b[i+j-1];
            sum+=a[i+j-1]*b[i-j];
//            db(sum-ac[i+j]+ac[i-j])
            add=max(add,sum-ac[i+j]+ac[i-j]);
        }
    }
//    db(add)
    db(add+ac.back())

    return 0;
}