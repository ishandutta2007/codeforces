#include <bits/stdc++.h>

using namespace std;

const int N=(int)3e5+7;
int n;
vector <int> g[N];
int dp1[N],dp2[N],dp3[N];
bool u[N];

void dfs(int nod)
{
        u[nod]=1;
        int o=0;
        vector <int> vals;

        for(auto &nou : g[nod])
                if(u[nou]==0)
                        o++,
                        dfs(nou),
                        dp1[nod]=max(dp1[nod],dp1[nou]),
                        vals.push_back(dp1[nou]),
                        dp3[nod]=max(dp3[nod],1+dp2[nou]);

        dp1[nod]+=o;

        dp1[nod]=max(dp1[nod],1+o);

        dp2[nod]=max(dp2[nod],dp1[nod]);
        if(o>=2)
        {
                sort(vals.rbegin(),vals.rend());
                dp2[nod]=max(dp2[nod],1+o-2+vals[0]+vals[1]);
        }
        dp3[nod]=max(dp3[nod],dp1[nod]);
        dp3[nod]=max(dp3[nod],dp2[nod]);

}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int t;
        cin>>t;

        while(t--)
        {
                cin>>n;
                for(int i=1;i<=n;i++)
                        dp1[i]=dp2[i]=dp3[i]=0,
                        g[i].clear(),
                        u[i]=0;
                for(int i=1;i<n;i++)
                {
                        int a,b;
                        cin>>a>>b;
                        g[a].push_back(b);
                        g[b].push_back(a);
                }
                dfs(1);
                int ans=1;

                for(int i=1;i<=n;i++)
                        ans=max(ans,dp3[i]);
                cout<<ans<<"\n";
        }

        return 0;
}