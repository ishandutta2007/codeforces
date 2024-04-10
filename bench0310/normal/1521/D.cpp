#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v[n+1];
        vector<array<int,2>> edges;
        set<array<int,2>> used_edges;
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
            edges.push_back({a,b});
        }
        vector<array<int,2>> dp(n+1,{0,0});
        vector<array<int,2>> zero(n+1,{0,0});
        vector<int> one(n+1,0);
        function<void(int,int)> solve=[&](int a,int p)
        {
            vector<array<int,2>> opt;
            int cnt=0;
            for(int to:v[a])
            {
                if(to==p) continue;
                solve(to,a);
                cnt+=dp[to][0];
                opt.push_back({dp[to][1]-dp[to][0],to});
            }
            sort(opt.begin(),opt.end(),greater<>());
            dp[a][0]=cnt;
            for(int i=0;i<min(2,(int)opt.size());i++)
            {
                if(opt[i][0]>=0)
                {
                    dp[a][0]+=(opt[i][0]+1);
                    zero[a][i]=opt[i][1];
                }
            }
            dp[a][1]=cnt;
            if(opt.size()>=1&&opt[0][0]>=0)
            {
                dp[a][1]+=(opt[0][0]+1);
                one[a]=opt[0][1];
            }
        };
        solve(1,0);
        vector<int> g[n+1];
        function<void(int,int,int)> go=[&](int a,int x,int p)
        {
            int b=0,c=0;
            if(x==0) tie(b,c)={zero[a][0],zero[a][1]};
            else b=one[a];
            for(int to:{b,c})
            {
                if(to>0)
                {
                    g[a].push_back(to);
                    g[to].push_back(a);
                }
            }
            for(int to:v[a])
            {
                if(to==p) continue;
                if(to==b||to==c) go(to,1,a);
                else go(to,0,a);
            }
        };
        go(1,0,0);
        vector<bool> vis(n+1,0);
        int prv=0;
        vector<array<int,2>> add,rm;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==1||g[i].size()==2) continue;
            vector<int> q={i};
            vis[i]=1;
            int idx=0;
            while(idx<(int)q.size())
            {
                int a=q[idx++];
                for(int to:g[a])
                {
                    if(vis[to]==0)
                    {
                        q.push_back(to);
                        vis[to]=1;
                    }
                }
            }
            int sz=q.size();
            for(int j=0;j+1<sz;j++)
            {
                int a=q[j];
                int b=q[j+1];
                used_edges.insert({a,b});
                used_edges.insert({b,a});
            }
            if(prv!=0) add.push_back({prv,q[0]});
            prv=q.back();
        }
        for(auto [a,b]:edges) if(used_edges.find({a,b})==used_edges.end()) rm.push_back({a,b});
        cout << add.size() << "\n";
        for(int i=0;i<(int)add.size();i++) cout << rm[i][0] << " " << rm[i][1] << " " << add[i][0] << " " << add[i][1] << "\n";
    }
    return 0;
}