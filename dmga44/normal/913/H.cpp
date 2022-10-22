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
const ll mod=(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

ll invs[MAXN];
vector<ll> fun_p[35][MAXN];
vector<ll> acum[35][MAXN];

ll qp(ll b,ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
            ans=(ans*b)%mod;
        b=(b*b)%mod;
        e>>=1;
    }
    return ans;
}

vector<ll> integrate(vector<ll>& p)
{
    vector<ll> ans(p.size()+1);
    for(int i=0;i<p.size();i++)
        ans[i+1]=(p[i]*invs[i+1])%mod;
    return ans;
}

vector<ll> operator-(vector<ll> a,vector<ll> b)
{
    while(a.size()<b.size())
        a.push_back(0);
    for(int i=0;i<b.size();i++)
        a[i]=(a[i]-b[i]+mod)%mod;
    return a;
}

ll eval(vector<ll> a,ll x)
{
    ll ans=0,mul=1;
    for(int i=0;i<a.size();i++)
    {
        ans=(ans+mul*a[i])%mod;
        mul=(mul*x)%mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1;i<MAXN;i++)
        invs[i]=qp(i,mod-2);

    int n;
    cin >> n;
    vector<int> xs;
    for(int i=0;i<n;i++)
    {
        string x;
        cin >> x;
        int fal=0;
        int pos=0;
        while(pos<x.size() && x[pos]!='.')
        {
            fal=fal*10+x[pos]-'0';
            pos++;
        }
        if(pos<x.size())
        {
            pos++;
            int mul=6;
            while(pos<x.size())
            {
                mul--;
                fal=fal*10+x[pos]-'0';
                pos++;
            }
            while(mul)
            {
                fal=fal*10;
                mul--;
            }
        }
        else
            fal*=1000000;
        xs.push_back(fal);
    }

    xs.push_back(0);
    set<int> imps;
    for(auto x : xs)
    {
        imps.insert(x);
        int cx=x;
        while(x>=1e6)
        {
            x-=1e6;
            imps.insert(x);
        }
        while(cx+1e6<=n*1e6)
        {
            cx+=1e6;
            imps.insert(cx);
        }
    }

    vector<int> intervals;
    map<int,int> pps;
    for(auto x : imps)
    {
        pps[x]=intervals.size();
        intervals.push_back(x);
    }

    int sz=intervals.size();
    fun_p[0][0]={1};
    acum[0][0]={0};
    for(int i=1;i<sz;i++)
        acum[0][i]={1};
    for(int i=1;i<=n;i++)
        for(int j=1;j<sz;j++)
        {
            if(intervals[j]>xs[i-1])
                fun_p[i][j]={0};
            else if(intervals[j]<=1e6)
                fun_p[i][j]=acum[i-1][j];
            else
                fun_p[i][j]=acum[i-1][j]-acum[i-1][pps[intervals[j]-1e6]];
            acum[i][j]=integrate(fun_p[i][j]);
            if(j>1)
                acum[i][j][0]=(acum[i][j][0]+eval(acum[i][j-1],intervals[j-1]-intervals[j-2]))%mod;
//            db("")
//            cout << i << ' ' << j << '\n';
//            db(eval(acum[i][j-1],intervals[j-1]))
//            db("fun_p:")
//            for(auto x : fun_p[i][j])
//                cout << x << ' ';
//            cout << '\n';
//            db("acum:")
//            for(auto x : acum[i][j])
//                cout << x << ' ';
//            cout << '\n';
//            db("xxxx")
//            db("")
        }

    ll x1=eval(acum[n][sz-1],intervals.back()-intervals[sz-2]);

//    db((ll)(1e12)%mod)

    for(int i=0;i<n;i++)
        x1=(x1*qp(1e6,mod-2))%mod;
    db(x1)

    return 0;
}