#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN 100005

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n&1)
        {
            if(n==1)
                db("FastestFinger")
            else
                db("Ashishgup")
            continue;
        }
        if(n==(n&-n))
        {
            if(n==2)
                db("Ashishgup")
            else
                db("FastestFinger")
            continue;
        }
        else
        {
            int po=1;
            while(!(n&1))
            {
                po<<=1;
                n>>=1;
            }
            if(po==2)
            {
                bool ok=1;
                for(int i=2;i<min(n,(int)(sqrt(n)+3));i++)
                    if(n%i==0)
                        ok=0;
                if(ok)
                    db("FastestFinger")
                else
                    db("Ashishgup")
            }
            else
                db("Ashishgup")
        }
    }

    return 0;
}