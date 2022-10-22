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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e7+5)

int p[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!p[i])
            for(int j=i;j<MAXN;j+=i)
                p[j]=i;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    int t;
    cin >> t;
    while(t--)
    {
        int c,d,x;
        cin >> c >> d >> x;
        vector<int> dx;
        for(int i=1;i*i<=x;i++)
        {
            if(x%i)
                continue;
            if(i==x/i)
            {
                dx.push_back(i);
                continue;
            }
            dx.push_back(i);
            dx.push_back(x/i);
        }

        int res=0;
        for(auto g : dx)
        {
            ll v=x/g+d;
            if(v%c)
                continue;
            v/=c;
            if(v==1)
            {
                res++;
                continue;
            }
            int cpy=v;
            vector<int> fac;
            while(v!=1)
            {
                if(p[v])
                {
                    if(fac.empty() || fac.back()!=p[v])
                        fac.push_back(p[v]);
                    v/=p[v];
                }
                else
                {
                    if(fac.empty() || fac.back()!=v)
                        fac.push_back(v);
                    v=1;
                }
            }
            v=cpy;

            int add=1;
            for(auto p : fac)
                add<<=1;

            res+=add;
        }
        db(res)
    }

    return 0;
}