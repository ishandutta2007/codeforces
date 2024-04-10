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
        int n,q;
        cin >> n >> q;
        string s;
        cin >> s;
        while(q--)
        {
            int l,r;
            cin >> l >> r;
            l--,r--;
            vector<vector<bool>> hay(n+1,vector<bool>(r-l+2));
            vector<vector<bool>> ihay(n+1,vector<bool>(r-l+2));
            for(int i=0;i<n+1;i++)
            {
                hay[i][0]=1;
                ihay[i][r-l+1]=1;
            }
            for(int i=0;i<n;i++)
                for(int j=l;j<=r;j++)
                    if((s[i]==s[j] && hay[i][j-l]) || hay[i][j-l+1])
                        hay[i+1][j-l+1]=1;
            for(int i=n-1;i>=0;i--)
                for(int j=l;j<=r;j++)
                    if((s[i]==s[j] && ihay[i+1][j-l+1]) || ihay[i+1][j-l])
                        ihay[i][j-l]=1;
            bool ok=0;
            for(int i=0;i<n-2;i++)
                for(int j=l;j<r;j++)
                    if(hay[i+1][j-l+1] && ihay[i+2][j-l+1])
                    {
//                        cout << i << ' ' << j << '\n';
                        ok=1;
                    }
            if(ok)
                db("YES")
            else
                db("NO")
        }
    }

    return 0;
}