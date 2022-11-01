#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int inf=(1<<29);
    int n,m,k;
    cin >> n >> m >> k;
    auto h=[&](int i,int j)->int{return i*m+j;};
    auto hr=[&](int x)->array<int,2>{return {x/m,x%m};};
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int o=0;o<n;o++) for(int i=0;i<m;i++) cin >> a[o][i];
    vector<array<int,2>> v(k);
    for(int i=0;i<k;i++)
    {
        cin >> v[i][0] >> v[i][1];
        v[i][0]--;
        v[i][1]--;
    }
    vector<vector<int>> dp((1<<k),vector<int>(n*m,inf));
    vector<vector<bitset<200>>> res((1<<k),vector<bitset<200>>(n*m,bitset<200>(0)));
    for(int o=0;o<n*m;o++)
    {
        dp[0][o]=a[hr(o)[0]][hr(o)[1]];
        res[0][o][o]=1;
    }
    vector<vector<int>> d(n*m,vector<int>(n*m,inf));
    vector<vector<bitset<200>>> p(n*m,vector<bitset<200>>(n*m,bitset<200>(0)));
    auto in=[&](int i,int j)->bool{return (0<=i&&i<n&&0<=j&&j<m);};
    vector<array<int,2>> z={{1,0},{-1,0},{0,-1},{0,1}};
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            d[h(o,i)][h(o,i)]=a[o][i];
            p[h(o,i)][h(o,i)][h(o,i)]=1;
            for(auto [one,two]:z)
            {
                int r=o+one;
                int c=i+two;
                if(in(r,c)==0) continue;
                d[h(o,i)][h(r,c)]=a[o][i]+a[r][c];
                p[h(o,i)][h(r,c)][h(o,i)]=1;
                p[h(o,i)][h(r,c)][h(r,c)]=1;
            }
        }
    }
    for(int j=0;j<n*m;j++)
    {
        for(int o=0;o<n*m;o++)
        {
            for(int i=0;i<n*m;i++)
            {
                if(d[o][j]+d[j][i]-a[hr(j)[0]][hr(j)[1]]<d[o][i])
                {
                    d[o][i]=d[o][j]+d[j][i]-a[hr(j)[0]][hr(j)[1]];
                    p[o][i]=p[o][j]|p[j][i];
                }
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        dp[(1<<i)][h(v[i][0],v[i][1])]=a[v[i][0]][v[i][1]];
        res[(1<<i)][h(v[i][0],v[i][1])][h(v[i][0],v[i][1])]=1;
    }
    for(int mask=1;mask<(1<<k);mask++)
    {
        for(int submask=((mask-1)&mask);submask>0;submask=((submask-1)&mask))
        {
            for(int o=0;o<n;o++)
            {
                for(int i=0;i<m;i++)
                {
                    if(dp[submask][h(o,i)]+dp[mask^submask][h(o,i)]-a[o][i]<dp[mask][h(o,i)])
                    {
                        dp[mask][h(o,i)]=dp[submask][h(o,i)]+dp[mask^submask][h(o,i)]-a[o][i];
                        res[mask][h(o,i)]=res[submask][h(o,i)]|res[mask^submask][h(o,i)];
                    }
                }
            }
        }
        for(int o=0;o<n*m;o++)
        {
            for(int i=0;i<n*m;i++)
            {
                if(o==i) continue;
                if(dp[mask][i]+d[o][i]-a[hr(i)[0]][hr(i)[1]]<dp[mask][o])
                {
                    dp[mask][o]=dp[mask][i]+d[o][i]-a[hr(i)[0]][hr(i)[1]];
                    res[mask][o]=res[mask][i]|p[o][i];
                }
            }
        }
    }
    int best=inf;
    bitset<200> b;
    for(int i=0;i<n*m;i++)
    {
        if(dp[(1<<k)-1][i]<best)
        {
            best=dp[(1<<k)-1][i];
            b=res[(1<<k)-1][i];
        }
    }
    cout << best << "\n";
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++) cout << ".X"[b[h(o,i)]];
        cout << "\n";
    }
    return 0;
}