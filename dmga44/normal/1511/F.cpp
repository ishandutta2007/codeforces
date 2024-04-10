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
const ll mod=(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

vector<int> g[45][26];
ll dp[8][6][45][45];

struct matrix{
    vector< vector<ll> > m;
    ll mod,sz;
    ll mod2;

    matrix (ll n,ll modc) : sz(n),m(n),mod(modc) {
        for(int i=0;i<n;i++)
            m[i].resize(n);
        mod2=mod*mod;
    }

    matrix operator*(matrix b)
    {
        matrix ans(sz,mod);
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                for(int u=0;u<sz;u++)
                {
                    ans.m[i][u]+=m[i][j]*b.m[j][u];
                    if(ans.m[i][u]>=mod2)
                        ans.m[i][u]-=mod2;
                }
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                ans.m[i][j]%=mod;
        return ans;
    }

    matrix qp(ll e)
    {
        if(e==1)
            return *this;
        matrix x=qp(e/2);
        x=(x*x);
        if(e&1)
            x=(x*(*this));
        return x;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    vector<int> ini(45);
    vector<int> pos(45);
    int sz=0;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        for(int j=1;j<s[i].size();j++)
        {
            ini[sz+j]=sz;
            pos[sz+j]=i;
        }
        sz+=(s[i].size()-1);
    }

    sz=0;
    for(int i=0;i<n;i++)
    {
        int ne=sz+1;
        if(s[i].size()==1)
            ne=0;
//        cout << ne << '\n';
        g[0][s[i][0]-'a'].push_back(ne);
        sz+=(s[i].size()-1);
    }

    for(int i=1;i<=sz;i++)
    {
        int ne=i+1;
        if(i-ini[i]==s[pos[i]].size()-1)
            ne=0;
//        cout << ne << '\n';
//        cout << s[pos[i]][i-ini[i]]-'a' << '\n';
//        db("xxx")
        g[i][s[pos[i]][i-ini[i]]-'a'].push_back(ne);
    }

    for(int i=0;i<n;i++)
    {
        for(int ini=0;ini<=sz;ini++)
        {
            dp[i][0][ini][ini]=1;
            for(int j=0;j<s[i].size();j++)
            {
                for(int act=0;act<=sz;act++)
                    for(auto p : g[act][s[i][j]-'a'])
                    {

                        dp[i][j+1][ini][p]=(dp[i][j+1][ini][p]+dp[i][j][ini][act])%mod;
                    }
            }
        }
    }

//    db("xxx")
//    db(dp[0][2][0][0])
//    db(dp[1][2][0][0])
    matrix ma(5*(sz+1)+2,mod);
    for(int i=sz+2;i<=5*(sz+1)+1;i++)
        ma.m[i][i-sz-1]=1;
    ma.m[1][0]=1;
//    db("xxx")
    for(int i=0;i<n;i++)
    {
//        db(i)
        for(int ini=0;ini<=sz;ini++)
            for(int tar=0;tar<=sz;tar++)
                ma.m[tar+1][ini+1+((s[i].size()-1)*(sz+1))]+=dp[i][s[i].size()][ini][tar];
    }

//    for(int i=0;i<5*(sz+1)+2;i++,cout << '\n')
//    {
//        for(int j=0;j<5*(sz+1)+2;j++)
//            cout << ma.m[i][j] << ' ';
//    }
//    cout << '\n';

//    db("xxx")
//    for(int i=0;i<m;i++)
//    {
//        matrix x=ma.qp(i+1);
//        for(int i=0;i<=sz;i++)
//            cout << x.m[i+1][0] << ' ';
//        cout << '\n';
//    }
    ma=ma.qp(m+1);
    db(ma.m[1][0])

    return 0;
}
/**
3 5
ababa
ab
a
**/