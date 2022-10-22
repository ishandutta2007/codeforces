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
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int solve(vector<int>& x,vector<int>& y)
{
    int n=x.size();
    int m=y.size();
    if(min(n,m)==0)
        return 0;

    sort(all(x));
    sort(all(y));
    vector<int> ac(n+1);
    for(int i=0;i<n;i++)
    {
        int ok=(lower_bound(all(y),x[i]+1)-lower_bound(all(y),x[i]));
        ac[i+1]=ac[i]+ok;
    }

    int res=ac[n];
//    db(res)
    int pos=0;
    while(pos<m && y[pos]<x[0])
        pos++;

    int act=x[0];
    int sz=1;
    while(pos<m)
    {
        while(sz<n && x[sz]-sz<=y[pos])
            sz++;
//        cout << sz << ' ' << pos << '\n';
        act=y[pos];
        res=max(res,ac[n]-ac[sz]+((int)(lower_bound(all(y),act+sz)-y.begin())-(int)(lower_bound(all(y),act)-y.begin())));
//        cout << ac[n]-ac[sz]+(lower_bound(all(y),act+sz)-lower_bound(all(y),act)) << '\n';
        pos++;
    }

//    cout << "res:" << res << '\n';
//    db("")
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> pm;
        vector<int> pn;
        vector<int> nm;
        vector<int> nn;
        int x;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            if(x<0)
                nn.push_back(-x);
            else
                pn.push_back(x);
        }
        for(int i=0;i<m;i++)
        {
            cin >> x;
            if(x<0)
                nm.push_back(-x);
            else
                pm.push_back(x);
        }
        db(solve(pn,pm)+solve(nn,nm))
    }

    return 0;
}
/**
5
5 6
-1 1 5 11 15
-4 -3 -2 6 7 15
2 2
-1 1
-1000000000 1000000000
2 2
-1000000000 1000000000
-1 1
3 5
-1 1 2
-2 -1 1 2 5
2 1
1 2
10

1
5 6
-1 1 5 11 15
-4 -3 -2 6 7 15
**/