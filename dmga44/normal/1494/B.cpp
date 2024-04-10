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
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
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
        int n,u,r,d,l;
        cin >> n >> u >> r >> d >> l;
        bool ok=0;
        int x[4];
        x[0]=u;
        x[1]=r;
        x[2]=d;
        x[3]=l;
        for(int i=0;i<16;i++)
        {
            for(int j=0;j<4;j++)
                if(i&(1<<j))
                {
                    x[j]--;
                    x[(j+1)%4]--;
                }

            bool kk=1;
            for(int j=0;j<4;j++)
                kk=(kk&(x[j]>=0 && x[j]<=n-2));
            ok|=kk;

            for(int j=0;j<4;j++)
                if(i&(1<<j))
                {
                    x[j]++;
                    x[(j+1)%4]++;
                }
        }

        if(ok)
            db("YES")
        else
            db("NO")
    }

    return 0;
}