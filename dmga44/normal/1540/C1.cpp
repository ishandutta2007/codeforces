//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e2+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> cs(n);
    for(int i=0;i<n;i++)
        cin >> cs[i];
    vector<ll> b(n-1);
    for(int i=0;i<n-1;i++)
        cin >> b[i];
    int q;
    cin >> q;
    int x;
    cin >> x;
    vector<ll> sums(100*100+1);
    sums[0]=1;
    ll sum=0;
    ll v=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            v=x;
            sum=x;
        }
        else
        {
            v+=b[i-1];
            sum+=v;
        }
        vector<ll> s2(100*100+1);
        for(int j=0;j<=cs[i];j++)
            for(int k=j;k<=100*100;k++)
                s2[k]=(s2[k]+sums[k-j])%mod;
        sums=s2;
        for(int j=0;j<=100*100;j++)
            if(j<sum)
                sums[j]=0;
    }

//    for(int i=0;i<10;i++)
//        cout << sums[i] << ' ';
//    cout << '\n';


    ll ans=0;
    for(int i=0;i<=100*100;i++)
        ans=(ans+sums[i])%mod;
    db(ans)

    return 0;
}