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
#define MAXN (ll)(1e3+5)

int ask(int x)
{
    cout << x << '\n';
    cout.flush();
    cin >> x;
    return x;
}

int f[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    mt19937 rng(time(0));
    for(int i=0;i<m;i++)
    {
        string s;
        cin >> s;
        int ma=0;
        for(int j=0;j<n;j++)
            ma=max(ma,f[j]);
        int c[2];
        c[0]=c[1]=0;
        for(int j=0;j<n;j++)
            if(ma-f[j]<=10)
                c[s[j]-'0']+=(1<<(10-(ma-f[j])));
        int v;
        int x=rng();
        x=abs(x)%(c[0]+c[1]);
        if(c[0]>x)
            v=ask(0);
        else
            v=ask(1);
        for(int j=0;j<n;j++)
            f[j]+=(v==(s[j]-'0'));
    }

    return 0;
}