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
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

vector<int> solve(vector<int> a)
{
    int n=a.size();
    vector<bool> mk(n+2);
    int pos=-1;
    for(int i=0;i<n;i++)
    {
        if(mk[a[i]+1])
            pos=i;
        mk[a[i]]=1;
    }

    if(pos==-1)
        return {};
    int p1=pos;
    int p2;
    for(int i=0;i<n;i++)
        if(a[i]==a[pos]+1)
            p2=i;

    vector<int> res;
    if(p2)
        res.push_back(p2);
    int sz=0;
    while(a[p1-sz-1]==a[p1]-sz-1)
        sz++;
    res.push_back(p1-p2-sz);
    res.push_back(1+sz);
    if(p1!=n-1)
        res.push_back(n-1-p1);
    return res;
}

vector<int> apply(vector<int> a,vector<int> q)
{
    vector<vector<int> > pieces(q.size());
    int cont=0;
    for(int i=0;i<q.size();i++)
        for(int j=0;j<q[i];j++)
        {
            pieces[i].push_back(a[cont]);
            cont++;
        }

    vector<int> res;
    for(int i=q.size()-1;i>=0;i--)
        for(auto y : pieces[i])
            res.push_back(y);
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    vector<vector<int> > qs;
    while(solve(a)!=vector<int>(0))
    {
        qs.push_back(solve(a));
        a=apply(a,solve(a));
    }

    db(qs.size())
    for(int i=0;i<qs.size();i++)
    {
        cout << qs[i].size() << ' ';
        for(auto y : qs[i])
            cout << y << ' ';
        cout << '\n';
    }

    return 0;
}