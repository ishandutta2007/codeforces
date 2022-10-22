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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    sort(allr(a));
    k++;

    ll sum=0;
    ll ans=0;
    ll pos=-1;
    for(int i=0;i<n;i++)
    {
        ans+=sum;
        sum+=a[i];
        if(sum<0)
        {
            pos=i;
            break;
        }
    }
//    cout << sum << ' ' << ans << ' ' << pos << '\n';

    if(pos==-1)
    {
        db(ans)
        return 0;
    }

    ll sz=(n-pos)/k;
    for(int i=0;i<(n-pos)%k;i++)
    {
        if(i==0)
            ans+=sz*(sum-a[pos]);
        ans+=sz*a[i+pos];
    }
    for(int i=pos+((n-pos)%k);i<n;i++)
    {
        if(i==pos)
            ans+=((n-i-1)/k)*(sum-a[pos]);
        ans+=a[i]*((n-i-1)/k);
    }
    db(ans)

    return 0;
}