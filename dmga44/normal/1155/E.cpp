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
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e6+3)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

vector<ll> lagrange_interpolation(vector<ll> &xs,vector<ll> &ys)
{
    int n=xs.size();
    vector<ll> res(n);
    vector<vector<ll>> prec(n);
    for(int i=0;i<n;i++)
    {
        prec[i].resize(n);
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            prec[i][j]=qp(xs[i]-xs[j]+mod,mod-2);
        }
    }
    for(int i=0;i<n;i++)
    {
        vector<ll> add(n);
        add[0]=ys[i];
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            for(int k=n-2;k>=0;k--)
            {
                add[k+1]=(add[k+1]+add[k])%mod;
                add[k]=(add[k]*(mod-xs[j]))%mod;
            }
            for(int k=0;k<n;k++)
                add[k]=(add[k]*prec[i][j])%mod;
        }
        for(int j=0;j<n;j++)
            res[j]=(res[j]+add[j])%mod;
    }
    return res;
}

//vector<ld> lagrange_interpolation(vector<ld> &xs,vector<ld> &ys)
//{
//    int n=xs.size();
//    vector<ld> res(n);
//    for(int i=0;i<n;i++)
//    {
//        vector<ld> add(n);
//        add[0]=ys[i];
//        for(int j=0;j<n;j++)
//        {
//            if(i==j)
//                continue;
//            for(int k=n-2;k>=0;k--)
//            {
//                add[k+1]=add[k+1]+add[k];
//                add[k]=add[k]*(mod-xs[j]);
//            }
//            for(int k=0;k<n;k++)
//                add[k]/=prec[i-j+n])%mod;
//        }
//        for(int j=0;j<n;j++)
//            res[j]=(res[j]+add[j])%mod;
//    }
//    return res;
//}

int query(int x)
{
    cout << "? " << x << '\n';
    cout.flush();
    int y;
    cin >> y;
    return y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> xs(11),ys(11);
    for(int i=0;i<11;i++)
    {
        xs[i]=i;
        ys[i]=query(i);
    }

    vector<ll> coef=lagrange_interpolation(xs,ys);

    int res=-1;
    for(ll i=0;i<mod;i++)
    {
        ll v=0;
        for(ll j=10;j>=0;j--)
            v=((v*i)+coef[j])%mod;
        if(!v)
            res=i;
    }
    cout << "! " << res << '\n';
    cout.flush();

    return 0;
}