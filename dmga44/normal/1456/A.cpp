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

    int t;
    cin >> t;
    while(t--)
    {
        int n,p,k;
        cin >> n >> p >> k;
        vector<vector<int>> f(k);
        for(int i=0;i<k;i++)
            f[i].push_back(0);
        string s;
        cin >> s;
        for(int i=0;i<n;i++)
        {
            int a=s[i]-'0';
            f[i%k].push_back(f[i%k].back()+a);
        }

        int x,y;
        cin >> x >> y;
        int ans=2e9;
        for(int i=0;i<=n-p;i++)
        {
            int sum=0;
            int tot=(n-i-p)/k+1;
            int ini=p+i-1;

            sum=f[ini%k].back()-f[ini%k][ini/k];

            ans=min(ans,i*y+x*(tot-sum));
        }
        db(ans)
    }

    return 0;
}