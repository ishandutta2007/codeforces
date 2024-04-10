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
#define MAXN (ll)(4e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        string a,b;
        cin >> a >> b;
        vector<int> fa(26);
        vector<int> fb(26);
        for(int i=0;i<n;i++)
        {
            fa[a[i]-'a']++;
            fb[b[i]-'a']++;
        }

        bool ok=1;
        for(int i=0;i<26;i++)
        {
            if(fb[i]>fa[i])
            {
//                db(i)
                ok=0;
                break;
            }
            if((fa[i]-fb[i])%k)
            {
                ok=0;
                break;
            }
            if(fa[i]==fb[i])
                continue;
            fa[i+1]+=(fa[i]-fb[i]);
        }
        if(ok)
            db("Yes")
        else
            db("No")
    }

    return 0;
}