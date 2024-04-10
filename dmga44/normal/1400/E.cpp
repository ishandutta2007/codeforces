#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(4e18)
#define pi acos(-1)
#define MAXN (ll)(3e3+5)

int solve(vector<int> a)
{
    int n=a.size();
    int res=0;
    int mi=1e9;
    for(int i=0;i<n;i++)
    {
        if(a[i])
            res++;
        mi=min(mi,a[i]);
    }

    for(int i=0;i<n;i++)
        a[i]-=mi;

    int r2=mi;
    vector<int> act;
    for(int i=0;i<n;i++)
    {
        if(a[i])
            act.push_back(a[i]);
        else
        {
            if(act.size())
                r2+=solve(act);
            act.clear();
        }
    }
    if(act.size())
        r2+=solve(act);

    return min(res,r2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    db(solve(a))

    return 0;
}