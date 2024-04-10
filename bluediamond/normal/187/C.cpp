#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=(int) 1e5+7;
const int INF=(int) 1e9+7;
int n;
int m;
int k;
bool is[N];
vector<int> g[N];
int limit;
int dp[N];
int s;
int t;

struct T
{
        int node;
        int val;
};

bool operator < (T a,T b)
{
        return a.val>b.val;
}

bool ok(int val)
{
        limit=val;
        for (int i=1;i<=n;i++)
                dp[i]=INF;
        priority_queue<T> pq;
        pq.push({s,0});
        dp[s]=0;
        while (!pq.empty())
        {
                auto it=pq.top();
                pq.pop();
                int a=it.node;
                if (it.val!=dp[a])
                        continue;
                if (is[a] && dp[a])
                {
                        dp[a]=0;
                        pq.push({a,0});
                        continue;
                }
                if (dp[a]<limit)
                        for (auto &b:g[a])
                                if (dp[a]+1<dp[b])
                                {
                                        dp[b]=dp[a]+1;
                                        pq.push({b,dp[a]+1});
                                }
        }
        return (dp[t]!=INF);
}

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin>>n>>m>>k;
        for (int i=1;i<=k;i++)
        {
                int x;
                cin>>x;
                is[x]=1;
        }
        for (int i=1;i<=m;i++)
        {
                int x,y;
                cin>>x>>y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        cin>>s>>t;
        int l=0,r=n,sol=-1;
        while (l<=r)
        {
                int m=(l+r)/2;
                if (ok(m))
                {
                        sol=m;
                        r=m-1;
                }
                else
                {
                        l=m+1;
                }
        }
        cout<<sol<<"\n";
}