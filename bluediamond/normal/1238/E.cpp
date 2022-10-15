#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=20;
const int INF=(int)1e9;
int n,m;
int f[M][M];
string s;
int dp[1<<M];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin>>n>>m>>s;

        for(int i=0;i+1<n;i++)
        {
                int a=s[i]-'a',b=s[i+1]-'a';
                f[a][b]++;
                f[b][a]++;
        }

        for(int i=0;i<(1<<m);i++)
                dp[i]=INF;

        for(int i=0;i<m;i++)
                dp[1<<i]=0;

        for(int i=0;i<(1<<m);i++)
        {
                vector <int> bts,nbts;
                for(int j=0;j<m;j++)
                        if(i&(1<<j))
                                bts.push_back(j);
                        else
                                nbts.push_back(j);
                for(auto &a : bts)
                {
                        for(auto &b : nbts)
                        {
                                dp[i]+=f[a][b];
                        }
                }
                for(auto &b : nbts)
                        dp[i+(1<<b)]=min(dp[i+(1<<b)],dp[i]);
        }
        cout<<dp[(1<<m)-1]<<"\n";

        return 0;
}