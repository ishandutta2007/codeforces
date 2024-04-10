#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct info
{
    int i;
    int save;
    int burn;
    int val;
};

bool cmp(info a,info b)
{
    return a.burn<b.burn;
}

const int N=100+5;
const int T=2000+5;
int n;
info v[N];

int dp[N][T]; /// dp[poz][time] neaparat ends in poz
bool valid[N][T];
int ans=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        v[i].i=i;
        cin>>v[i].save>>v[i].burn>>v[i].val;
    }
    sort(v+1,v+n+1,cmp);
    valid[0][0]=1;
    for(int i=1;i<=n;i++)
    {
     ///   cout<<"\t\t\t"<<v[i].save<<" "<<v[i].burn<<" "<<v[i].val<<"\n";
    }
    for(int poz=1;poz<=n;poz++)
    {
        for(int t=v[poz].save;t<v[poz].burn;t++)
        {
            for(int j=0;j<poz;j++)
            {
                if(valid[j][t-v[poz].save])
                {
                    valid[poz][t]=1;
                    dp[poz][t]=max(dp[poz][t],dp[j][t-v[poz].save]+v[poz].val);
                }
            }
            ans=max(ans,dp[poz][t]);
            continue;
            if(poz==1 && t==2)
            {
                cout<<"\t"<<poz<<" "<<t<<"\t\t\t"<<dp[poz][t]<<"\n";
            }
            if(poz==2 && t==5)
            {
                cout<<"\t"<<poz<<" "<<t<<"\t\t\t"<<dp[poz][t]<<"\n";
            }
        }
    }
    cout<<ans<<"\n";
    for(int poz=1;poz<=n;poz++)
    {
        for(int t=v[poz].save;t<v[poz].burn;t++)
        {
            if(valid[poz][t] && dp[poz][t]==ans)
            {
                vector<int>sol;
                while(t)
                {
                    sol.push_back(v[poz].i);
                    for(int j=0;j<poz;j++)
                    {
                        if(valid[j][t-v[poz].save] && dp[j][t-v[poz].save]+v[poz].val==dp[poz][t])
                        {
                            t-=v[poz].save;
                            poz=j;
                        }
                    }
                }
                reverse(sol.begin(),sol.end());
                cout<<sol.size()<<"\n";
                for(auto &x:sol)
                {
                    cout<<x<<" ";
                }
                cout<<"\n";
                return 0;
            }
        }

    }
    cout<<"0\n";
    return 0;
}