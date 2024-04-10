#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
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
const ll mod=(ll)(175781251);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    vector<ll> a1(n1);
    vector<ll> a2(n2);
    vector<ll> a3(n3);
    ll sum=0;
    ll men=1e18;
    ll m1=1e18;
    ll m2=1e18;
    ll m3=1e18;
    ll s1=0;
    ll s2=0;
    ll s3=0;
    for(int i=0;i<n1;i++)
    {
        cin >> a1[i];
        sum+=a1[i];
        m1=min(m1,a1[i]);
        s1+=a1[i];
    }
    for(int i=0;i<n2;i++)
    {
        cin >> a2[i];
        sum+=a2[i];
        m2=min(m2,a2[i]);
        s2+=a2[i];
    }
    for(int i=0;i<n3;i++)
    {
        cin >> a3[i];
        sum+=a3[i];
        m3=min(m3,a3[i]);
        s3+=a3[i];
    }

    men=min(men,2*s1);
    men=min(men,2*s2);
    men=min(men,2*s3);
    vector<ll> ms;
    ms.push_back(m1);
    ms.push_back(m2);
    ms.push_back(m3);
    sort(all(ms));
    men=min(men,2*(ms[0]+ms[1]));
    db(sum-men)

    return 0;
}