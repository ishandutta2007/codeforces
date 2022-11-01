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
        for(int i=2;i<=n;i++)
        {
            int a;
            cin >> a;
            v[a].push_back(i);
            v[i].push_back(a);
        }
        vector<ll> val(n+1,0);
        for(int i=2;i<=n;i++) cin >> val[i];
        vector<int> depth[n+1];
        vector<int> ch[n+1];
        int lim=0;
        function<void(int,int,int)> dfs=[&](int a,int p,int d)
        {
            depth[d].push_back(a);
            lim=max(lim,d);
            for(int to:v[a])
            {
                if(to==p) continue;
                ch[a].push_back(to);
                dfs(to,a,d+1);
            }
        };
        dfs(1,0,1);
        vector<ll> dp(n+1,0);
        auto get_xy=[&](vector<int> &b)->array<ll,2>
        {
            array<ll,2> res={val[b[0]],val[b[0]]};
            for(int a:b)
            {
                res[0]=min(res[0],val[a]);
                res[1]=max(res[1],val[a]);
            }
            return res;
        };
        auto eval=[&](ll ini,ll origin,ll now,ll slope)->ll{return (ini+(now-origin)*slope);};
        const ll inf=(1<<30);
        for(int i=1;i<lim;i++)
        {
            auto [xd,yd]=get_xy(depth[i+1]);
            vector<array<ll,6>> e; //time,pre,ini,slope,add/rm,time_added or time,pre,id,0,0,0
            for(int a:depth[i])
            {
                for(int to:ch[a])
                {
                    dp[to]=max(dp[to],dp[a]+max(abs(xd-val[to]),abs(yd-val[to])));
                }
                auto [x,y]=get_xy(ch[a]);
                auto add=[&](ll l,ll r,ll ini,ll slope)
                {
                    e.push_back({l,0,ini,slope,1,l});
                    e.push_back({r,2,ini,slope,-1,l});
                };
                add(1,(x+y)/2,eval(dp[a]+y-x,x,1,-1),-1);
                add((x+y+1)/2,inf,eval(dp[a]+y-x,y,(x+y+1)/2,1),1);
            }
            for(int b:depth[i+1]) e.push_back({val[b],1,b,0,0,0});
            sort(e.begin(),e.end());            
            multiset<ll> up,down;
            for(auto [d,pre,ini,slope,tp,pd]:e)
            {
                if(slope==0)
                {
                    if(!up.empty()) dp[ini]=max(dp[ini],(*up.rbegin())+d);
                    if(!down.empty()) dp[ini]=max(dp[ini],(*down.rbegin())-d);
                }
                else
                {
                    if(slope==1)
                    {
                        if(tp==1) up.insert(ini-d);
                        else up.erase(up.find(ini-pd));
                    }
                    else
                    {
                        if(tp==1) down.insert(ini+d);
                        else down.erase(down.find(ini+pd));
                    }
                }
            }
        }
        ll res=0;
        for(int i=1;i<=n;i++) res=max(res,dp[i]);
        cout << res << "\n";
    }
    return 0;
}