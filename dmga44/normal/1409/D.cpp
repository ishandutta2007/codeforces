 #pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef unsigned long long ll;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll val(vector<int> ds)
{
    ll res=0;
    for(auto y : ds)
        res=(res*10+y);
    return res;
}

int sum(vector<int> ds)
{
    int res=0;
    for(auto y : ds)
        res+=y;
    return res;
}

vector<int> nexx(vector<int> ds)
{
    int ceroes=1;
    while(!ds.back())
    {
        ceroes++;
        ds.pop_back();
    }
    ds.pop_back();
    while(!ds.empty() && ds.back()==9)
    {
        ceroes++;
        ds.pop_back();
    }
    if(ds.empty())
        ds.push_back(1);
    else
    {
        int v=ds.back();
        ds.pop_back();
        ds.push_back(v+1);
    }
    for(int i=0;i<ceroes;i++)
        ds.push_back(0);
    return ds;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        int x;
        cin >> s >> x;
        vector<int> digits;
        for(int i=0;i<s.size();i++)
            digits.push_back(s[i]-'0');
        ll base=val(digits);

        while(sum(digits)>x)
            digits=nexx(digits);
        ll b2=val(digits);
        db(b2-base);
    }

    return 0;
}