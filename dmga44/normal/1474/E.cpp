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
const ll mod=(ll)(1e9+7);
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
        int n;
        cin >> n;
        ll res=0;
        vector<int> p(n);
        vector<pii> ans;
        if(n<=3)
        {
            for(int i=0;i<n-1;i++)
                p[i]=i+2;
            p[n-1]=1;
            for(int i=0;i<n-1;i++)
                ans.push_back(pii(i,n-1));
        }
        else
        {
            int mid=n/2;
            for(int i=1;i<mid-1;i++)
                p[i]=i+2;
            p[mid-1]=n-1;
            p[n-1]=2;

            for(int i=mid+1;i<n-1;i++)
                p[i]=i;
            p[mid]=1;
            p[0]=n;
            for(int i=1;i<mid;i++)
                ans.push_back(pii(i,n-1));
            for(int i=n-1;i>=mid;i--)
                ans.push_back(pii(i,0));
        }

        for(auto p : ans)
            res+=(p.f-p.s)*(p.f-p.s);
        db(res)
        for(auto v : p)
            cout << v << ' ';
        cout << '\n';
        db(ans.size())
        for(auto p : ans)
            cout << p.f+1 << ' ' << p.s+1 << '\n';
    }

    return 0;
}