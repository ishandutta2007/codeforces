#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=(int)5e5+7;
vector <pair <int,int>> g[N];
int n,k;
ll dp1[N],dp2[N];
bool seen[N];

void dfs(int nod)
{
        seen[nod]=1;
        vector <ll> gud;
        ll sumdp=0;
        for(auto &it : g[nod])
        {
                int nou=it.first;
                ll c=it.second;
                if(seen[nou]) continue;
                dfs(nou);
               // if(c+dp2[nou]>max(dp1[nou],dp2[]))
                sumdp+=max(dp1[nou],dp2[nou]);
                gud.push_back(-max(dp1[nou],dp2[nou])+c+dp2[nou]);
              //  gud.push_back(c);
        }

        sort(gud.rbegin(),gud.rend());
        dp1[nod]=dp2[nod]=sumdp;



        for(int i=0;i<(int)gud.size();i++)
        {
                dp1[nod]+=(i<k)*max(0LL,gud[i]);
                dp2[nod]+=(i<k-1)*max(0LL,gud[i]);
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int q;
        cin>>q;

        for(int tc=1;tc<=q;tc++)
        {
                cin>>n>>k;
                for(int i=1;i<=n;i++)
                {
                        seen[i]=0;
                        g[i].clear();
                        dp1[i]=dp2[i]=0;
                }

                for(int i=1;i<n;i++)
                {
                        int a,b,c;
                        cin>>a>>b>>c;
                        g[a].push_back({b,c});
                        g[b].push_back({a,c});
                }

                dfs(1);
                ll ans=0;
                for(int i=1;i<=n;i++)
                        ans=max(ans,dp1[i]),
                        ans=max(ans,dp2[i]);

                cout<<ans<<"\n";

        }

        return 0;
}