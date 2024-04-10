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
typedef complex<ld> point;
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
        int n,x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin >> a[i];

        int ok=1;
        for(int i=1;i<n;i++)
            if(a[i-1]>a[i])
                ok=0;
        if(ok)
        {
            db(0)
            continue;
        }
        int mi=1e6;
        for(int i=0;i<n;i++)
        {
            vector<int> vs;
            vs.push_back(x);
            for(int j=0;j<n;j++)
                if(i!=j)
                    vs.push_back(a[j]);
            sort(all(vs));
            vector<int> kk;
            kk.push_back(x);
            for(int j=0;j<n;j++)
                if(vs[j]!=a[j])
                    kk.push_back(a[j]);
            bool ko=1;
            for(int j=1;j<kk.size();j++)
                if(kk[j-1]>=kk[j])
                    ko=0;
            if(ko)
                mi=min(mi,(int)kk.size()-1);
        }
        if(mi!=1e6)
            db(mi)
        else
            db(-1)
    }

    return 0;
}