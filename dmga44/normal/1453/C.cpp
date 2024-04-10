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
const ld eps=(1e-8);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(n,vector<int>(n));
        vector<int> f(10);
        vector<pii> ps[10];
        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;
            for(int j=0;j<n;j++)
            {
                a[i][j]=s[j]-'0';
                f[a[i][j]]++;
                ps[a[i][j]].push_back(pii(i,j));
            }
        }
        for(int i=0;i<10;i++)
        {
            if(f[i]<2)
            {
                cout << "0 ";
                continue;
            }
            vector<int> mic(n,n);
            vector<int> mac(n,-1);
            vector<int> mir(n,n);
            vector<int> mar(n,-1);
            int ic=n;
            int ac=-1;
            int ir=n;
            int ar=-1;
            for(auto p : ps[i])
            {
                int x=p.f;
                int y=p.s;
                mic[y]=min(mic[y],x);
                mac[y]=max(mac[y],x);
                mir[x]=min(mir[x],y);
                mar[x]=max(mar[x],y);
                ic=min(ic,y);
                ac=max(ac,y);
                ir=min(ir,x);
                ar=max(ar,x);
            }

            int res=0;
            for(int i=0;i<n;i++)
                res=max(res,i*(mac[i]-mic[i]));
            for(int i=0;i<n;i++)
                res=max(res,i*(mar[i]-mir[i]));
            for(int i=0;i<n;i++)
                res=max(res,(n-i-1)*(mac[i]-mic[i]));
            for(int i=0;i<n;i++)
                res=max(res,(n-i-1)*(mar[i]-mir[i]));
            for(int i=0;i<n;i++)
            {
                if(i<ic)
                    continue;
                res=max(res,(i-ic)*(mac[i]));
                res=max(res,(i-ic)*(n-1-mic[i]));
            }
            for(int i=0;i<n;i++)
            {
                if(i>ac)
                    continue;
                res=max(res,(ac-i)*(mac[i]));
                res=max(res,(ac-i)*(n-1-mic[i]));
            }
            for(int i=0;i<n;i++)
            {
                if(i<ir)
                    continue;
                res=max(res,(i-ir)*(mar[i]));
                res=max(res,(i-ir)*(n-1-mir[i]));
            }
            for(int i=0;i<n;i++)
            {
                if(i>ar)
                    continue;
                res=max(res,(ar-i)*(mar[i]));
                res=max(res,(ar-i)*(n-1-mir[i]));
            }
            cout << res << ' ';
        }
        cout << '\n';
    }

    return 0;
}