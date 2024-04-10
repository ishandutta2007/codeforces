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

int ask(vector<int> v)
{
    cout << "?";
    for(auto u : v)
        cout << ' ' << u+1;
    cout << '\n';
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    for(int i=1;i<=500;i++)
        if(k*i>=n && ((k*i)-n)%2==0)
        {
            int fal=((k*i)-n)/2;
            vector<int> f(n);
            for(int j=0;j<n;j++)
            {
                f[j]=1;
                ll v=min((i-1)/2,fal);
                fal-=v;
                f[j]+=2*v;
            }
            if(fal)
                continue;
            vector<vector<int>> ps(i);
            int act=0;
            for(int j=0;j<n;j++)
                for(int l=0;l<f[j];l++)
                {
                    ps[act].push_back(j);
                    act=(act+1)%i;
                }

            ll ans=0;
            for(auto vv : ps)
                ans^=ask(vv);
            cout << "! " << ans << '\n';
            cout.flush();
            return 0;
        }
    cout << -1 << '\n';
    cout.flush();

    return 0;
}