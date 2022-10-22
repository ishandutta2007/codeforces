#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 400005

ll l[MAXN],r[MAXN],fs[MAXN],ls[MAXN];
int dp[MAXN][256];
vector<int> sg[MAXN];
set<int> xs;
map<int,int> mm;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
        cin >> l[i] >> r[i];
        r[i]++;
        xs.insert(l[i]);
        xs.insert(r[i]);
    }

    int cont=1;
    for(auto y : xs)
    {
        mm[y]=cont;
        ls[cont]=y;
        cont++;
    }

    for(int i=1;i<cont-1;i++)
        fs[i]=ls[i+1]-ls[i];

    for(int i=0;i<n;i++)
        for(int j=mm[l[i]];j<mm[r[i]];j++)
            sg[j].push_back(i);

    for(int i=1;i<cont-1;i++)
    {
//        db(i)
        vector<pii> eq;
        for(int j=0;j<sg[i].size();j++)
            for(int k=0;k<sg[i-1].size();k++)
                if(sg[i][j]==sg[i-1][k])
                    eq.push_back(pii(j,k));

        int base=(1<<sg[i-1].size())-1;
        for(auto y : eq)
            base-=(1<<y.second);

        for(int bm=0;bm<(1<<sg[i].size());bm++)
        {
            int ad=0;
            if(__builtin_popcount(bm)&1)
                ad=fs[i];

            int ma=0;
            int trans=0;
            for(auto y : eq)
                if(bm&(1<<y.first))
                    trans+=(1<<y.second);

            for(int j=base;1;j=(j-1)&base)
            {
                ma=max(ma,dp[i-1][trans+j]);
                if(j==0)
                    break;
            }
            dp[i][bm]=ad+ma;
//            cout << bm << ' ' << dp[i][bm] << '\n';
        }
//        db("")
    }

    int res=0;
    for(int i=0;i<(1<<sg[cont-2].size());i++)
        res=max(res,dp[cont-2][i]);
    db(res)

    return 0;
}
/**
2 10 8
2 5
6 8
**/