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
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e2+5)

vector<pii> dp[MAXN][MAXN][4][4];
bool dp0[MAXN][MAXN][4][4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp0[0][0][0][0]=1;
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
            for(int s1=0;s1<3;s1++)
                for(int s2=0;s2<3;s2++)
                    for(int w=0;w<2;w++)
                    {
                        if(!dp0[i][j][s1][s2])
                            continue;
                        vector<pii> pw;
                        if(s1==2 && s2==2)
                        {
                            for(int p=0;p<14;p++)
                                pw.push_back(pii(15,p));
                            for(int p=14;p<MAXN;p++)
                                pw.push_back(pii(p+2,p));
                        }
                        else
                        {
                            for(int p=0;p<24;p++)
                                pw.push_back(pii(25,p));
                            for(int p=24;p<MAXN;p++)
                                pw.push_back(pii(p+2,p));
                        }
                        if(w)
                            for(int i=0;i<pw.size();i++)
                                pw[i]=pii(pw[i].s,pw[i].f);

                        for(auto p : pw)
                        {
                            int ni=i+p.f;
                            int nj=j+p.s;
                            if(ni<MAXN && nj<MAXN)
                            {
                                if(!dp0[ni][nj][s1+(w==0)][s2+(w==1)])
                                {
//                                    if(ni==90 && nj==88 && s1+(w==0)==3 && s2+(w==1)==0)
//                                    {
//                                        cout << i << ' ' << j << ' ' << s1 << ' ' << s2 << ' ' << '\n';
//                                    }
                                    dp0[ni][nj][s1+(w==0)][s2+(w==1)]=1;
                                    for(auto pp : dp[i][j][s1][s2])
                                        dp[ni][nj][s1+(w==0)][s2+(w==1)].push_back(pp);
                                    dp[ni][nj][s1+(w==0)][s2+(w==1)].push_back(p);
                                }
                            }
                        }
                    }

    int t;
    cin >> t;
    while(t--)
    {
        int x,y;
        cin >> x >> y;
        vector<pii> ts;
//        db(dp0[90][88][3][0])
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if((i==3 || j==3) && dp0[x][y][i][j])
                    ts.push_back(pii(-i,j));
        sort(all(ts));
        if(ts.empty())
        {
            db("Impossible")
            continue;
        }
        int i=-ts[0].f;
        int j=ts[0].s;
        cout << i << ":" << j << '\n';
        for(auto p : dp[x][y][i][j])
            cout << p.f << ':' << p.s << ' ';
        cout << '\n';
    }

    return 0;
}
/**
6
75           0
90           90
20           0
0           75
78           50
80           100

1
90 88
**/