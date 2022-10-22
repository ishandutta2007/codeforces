#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
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
const ll mod=(ll)(175781251);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

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
        vector<int> a(n);
        vector<int> ac(n+1);
        vector<int> ty(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=1;i<n-1;i++)
        {
            ac[i+1]=ac[i];
            ac[i+1]+=((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1]));
            if((a[i]>a[i-1] && a[i]>a[i+1]))
                ty[i]=1;
            if((a[i]<a[i-1] && a[i]<a[i+1]))
                ty[i]=-1;
        }
        ac[n]=ac[n-1];

        int base=ac[n];
        int res=base;
        for(int i=1;i<n-1;i++)
        {
            int v=a[i];
            int v1=a[i-1];
            int v2=a[i+1];
            int val=base;
            if(ty[i])
                val--;
            a[i]=v1;
            if(ty[i-1])
                val--;
            if(i+2<n)
            {
                val-=(ty[i+1]!=0);
                if((a[i]<a[i+1] && a[i+2]<a[i+1]) || (a[i]>a[i+1] && a[i+2]>a[i+1]))
                    val++;
            }
            res=min(res,val);

            val=base;
            if(ty[i])
                val--;
            a[i]=v2;
            if(ty[i+1])
                val--;
            if(i-2>=0)
            {
                val-=(ty[i-1]!=0);
                if((a[i]<a[i-1] && a[i-2]<a[i-1]) || (a[i]>a[i-1] && a[i-2]>a[i-1]))
                    val++;
            }
            res=min(res,val);

            a[i]=v;
        }
        db(res)
    }

    return 0;
}