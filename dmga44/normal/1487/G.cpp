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
const ll mod=(ll)(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(4e2+5)

ll dp1[MAXN];
ll dp2[MAXN][MAXN][2][2];
ll dp3[2][MAXN][MAXN][3][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> c(26);
    for(int i=0;i<26;i++)
        cin >> c[i];

    dp1[2]=26*26;
    for(int i=3;i<=n;i++)
        dp1[i]=(dp1[i-1]*25)%mod;

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            dp2[2][(i==0)+(j==0)][i][j]=max(1,(25*(i==1)))*max(1,(25*(j==1)));
    for(int i=2;i<n;i++)
        for(int j=0;j<n;j++)
            for(int p1=0;p1<2;p1++)
                for(int p2=0;p2<2;p2++)
                {
                    vector<int> pos;
                    pos.push_back(1);
                    if(p1)
                        pos.push_back(0);
                    for(auto p3 : pos)
                    {
                        ll x=1;
                        if(p3==1)
                        {
                            x=25;
                            if(p1==1)
                                x--;
                        }
                        dp2[i+1][j+(p3==0)][p2][p3]=(dp2[i+1][j+(p3==0)][p2][p3]+dp2[i][j][p1][p2]*x)%mod;
                    }
                }

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            dp3[0][(i==0)+(j==0)][(i==1)+(j==1)][i][j]=max(1,(24*(i==2)))*max(1,(24*(j==2)));
    for(int i=2;i<n;i++)
    {
        int act=i&1;
        int nep=act^1;
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                for(int p1=0;p1<3;p1++)
                    for(int p2=0;p2<3;p2++)
                        dp3[nep][j][k][p1][p2]=0;
        vector<int> pos;
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                for(int p1=0;p1<3;p1++)
                    for(int p2=0;p2<3;p2++)
                    {
                        if(!dp3[act][j][k][p1][p2])
                            continue;
                        pos.clear();
                        pos.push_back(2);
                        if(p1)
                            pos.push_back(0);
                        if(p1!=1)
                            pos.push_back(1);
                        for(auto p3 : pos)
                        {
                            ll x=1;
                            if(p3==2)
                            {
                                x=24;
                                if(p1==2)
                                    x--;
                            }
                            dp3[nep][j+(p3==0)][k+(p3==1)][p2][p3]=(dp3[nep][j+(p3==0)][k+(p3==1)][p2][p3]+dp3[act][j][k][p1][p2]*x)%mod;
                        }
                    }
    }

    ll res=dp1[n];
    for(int i=0;i<=n;i++)
        for(int p1=0;p1<2;p1++)
            for(int p2=0;p2<2;p2++)
                for(int j=0;j<26;j++)
                    if(c[j]<i)
                        res=(res-dp2[n][i][p1][p2]+mod)%mod;

    for(int c1=0;c1<26;c1++)
        for(int c2=c1+1;c2<26;c2++)
            for(int j=0;j<=n;j++)
                for(int k=0;k<=n;k++)
                    for(int p1=0;p1<3;p1++)
                        for(int p2=0;p2<3;p2++)
                            if(c[c1]<j && c[c2]<k)
                                res=(res+dp3[n&1][j][k][p1][p2])%mod;
    db(res)

    return 0;
}
/**
6 5
1 1 1 1 1
2 2 2 1 1
1 2 2 2 1
1 1 2 2 2
1 1 1 2 2
1 1 1 1 2
**/