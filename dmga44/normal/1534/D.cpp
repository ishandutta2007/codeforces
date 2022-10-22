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
#define MAXN (ll)(5e5+5)

int n;
vector<int> ask(int u)
{
    cout << "? " << u+1 << '\n';
    cout.flush();
    vector<int> ans(n);
    for(int i=0;i<n;i++)
        cin >> ans[i];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> v=ask(0);
    vector<int> f(2);
    set<pii> s;
    for(int i=1;i<n;i++)
    {
        if(v[i]==1)
            s.insert(pii(0,i));
        f[v[i]&1]++;
    }

    if(f[0]<=(n-1)/2)
    {
        for(int i=1;i<n;i++)
        {
            if(v[i]&1)
                continue;
            vector<int> kk=ask(i);
            for(int j=0;j<n;j++)
                if(kk[j]==1)
                    s.insert(pii(min(i,j),max(i,j)));
        }
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            if(!(v[i]&1))
                continue;
            vector<int> kk=ask(i);
            for(int j=0;j<n;j++)
                if(kk[j]==1)
                    s.insert(pii(min(i,j),max(i,j)));
        }
    }

    db("!")
    for(auto p : s)
        cout << p.f+1 << ' ' << p.s+1 << '\n';
    cout.flush();

    return 0;
}