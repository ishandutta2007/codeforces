#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 55
#define oo 2500

int dp[MAXN][MAXN][MAXN][MAXN],ac[MAXN][MAXN];
string s[MAXN];

int c(int x1,int y1,int x2,int y2)
{
    return ac[x2+1][y2+1]-ac[x2+1][y1]-ac[x1][y2+1]+ac[x1][y1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> s[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int u=i;u<n;u++)
                for(int k=j;k<n;k++)
                    dp[i][j][u][k]=max(u-i+1,k-j+1);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            ac[i+1][j+1]=ac[i+1][j]+ac[i][j+1]-ac[i][j];
            if(s[i][j]=='#')
                ac[i+1][j+1]++;
        }

    for(int sz=1;sz<=(n*n);sz++)
    {
        vector<pii> pos;
        for(int i=1;i<=n;i++)
            if(sz%i==0 && sz/i<=n)
                pos.push_back(pii(i,sz/i));
        for(auto y : pos)
        {
            int di=y.first;
            int dj=y.second;
            for(int i=0;i+di<=n;i++)
                for(int j=0;j+dj<=n;j++)
                {
                    int i2=i+di-1;
                    int j2=j+dj-1;
                    if(!c(i,j,i2,j2))
                    {
                        dp[i][j][i2][j2]=0;
                        continue;
                    }
                    for(int u=i;u<=i2;u++)
                        if(!c(u,j,u,j2))
                        {
                            ll sum=0;
                            if(u!=i)
                                sum+=dp[i][j][u-1][j2];
                            if(u!=i2)
                                sum+=dp[u+1][j][i2][j2];
                            if(sum<dp[i][j][i2][j2])
                                dp[i][j][i2][j2]=sum;
                        }

                    for(int u=j;u<=j2;u++)
                        if(!c(i,u,i2,u))
                        {
                            ll sum=0;
                            if(u!=j)
                                sum+=dp[i][j][i2][u-1];
                            if(u!=j2)
                                sum+=dp[i][u+1][i2][j2];
                            if(sum<dp[i][j][i2][j2])
                                dp[i][j][i2][j2]=sum;
                        }
                }
        }
    }
    db(dp[0][0][n-1][n-1])

    return 0;
}