#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e2+5)

pii solve(int i,int j,int n)
{
    cout << "? 1 " << i << ' ' << j << ' ' << n-1 << '\n';
    cout.flush();
    int q1;
    cin >> q1;

    cout << "? 2 " << i << ' ' << j << ' ' << 1 << '\n';
    cout.flush();
    int q2;
    cin >> q2;

    if(q1>=n-1 || q2<=2)
    {
        cout << "? 1 " << j << ' ' << i << ' ' << n-1 << '\n';
        cout.flush();
        int q11;
        cin >> q11;

        cout << "? 2 " << j << ' ' << i << ' ' << 1 << '\n';
        cout.flush();
        int q22;
        cin >> q22;

        q1=max(q1,q11);
        q2=min(q2,q22);
    }
    cout << "? 1 " << i << ' ' << j << ' ' << q1-1 << '\n';
    cout.flush();
    int q3;
    cin >> q3;
    if(q3==q1)
        return pii(q2,q1);
    return pii(q1,q2);
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> ans(n);
        for(int i=0;i<n/2;i++)
        {
            pii x=solve(i*2+1,i*2+2,n);
            ans[2*i]=x.f;
            ans[2*i+1]=x.s;
        }

        if(n&1)
        {
            pii x=solve(n-1,n,n);
            ans[n-2]=x.f;
            ans[n-1]=x.s;
        }

        cout << "!";
        for(auto x : ans)
            cout << ' ' << x;
        cout << '\n';
        cout.flush();
    }

    return 0;
}