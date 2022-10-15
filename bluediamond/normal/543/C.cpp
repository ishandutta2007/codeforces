#include <bits/stdc++.h>

using namespace std;


const int N=20;
const int INF=(int) 1e9;
int n, len, cost[N][N], dp[1<<N], mn[N];
string s[N];
vector<vector<pair<int, int>>> groups;

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("input", "r", stdin);


        cin>>n>>len;

        for (int i=0; i<n; i++)
        {
                cin>>s[i];
                mn[i]=INF;
        }
        for (int i=0; i<n; i++)
                for (int j=0; j<len; j++)
                {
                        cin>>cost[i][j];
                        mn[i]=min(mn[i], cost[i][j]);
                }

        for (int j=0; j<len; j++)
        {
                for (int x=0; x<26; x++)
                {
                        vector<pair<int, int>> cur;
                        for (int i=0; i<n; i++)
                        {
                                if (s[i][j]-'a'==x)
                                {
                                        cur.push_back({i, cost[i][j]});
                                }
                        }
                        if (!cur.empty())
                        {
                                groups.push_back(cur);
                                continue;
                                for (auto &it : cur)
                                {
                                        cout<<"("<<it.first<<", "<<it.second<<")  ";
                                }
                                cout<<"\n";
                        }
                }
        }

        for (int mask=1; mask<(1<<n); mask++)
        {
                dp[mask]=INF;
        }

        for (auto &vec : groups)
        {
                int sz=(int) vec.size();
                int sum=0, mx=0, allmask=0;
                for (auto &it : vec)
                {
                        sum+=it.second;
                        mx=max(mx, it.second);
                        allmask+=(1<<it.first);
                }

                for (int mask=0; mask<(1<<n); mask++)
                {
                        dp[mask|allmask]=min(dp[mask|allmask], dp[mask]+sum-mx);
                }
        }

        for (int mask=0; mask<(1<<n); mask++)
        {
                for (int i=0; i<n; i++)
                {
                        if ((mask&(1<<i))==0)
                        {
                                dp[mask|(1<<i)]=min(dp[mask|(1<<i)], dp[mask]+mn[i]);
                        }
                }
        }

        cout<<dp[(1<<n)-1]<<"\n";

        return 0;
}