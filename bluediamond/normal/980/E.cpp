#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e6+7;

int t[N][20];
bool viz[N];
vector<int>g[N];

int n,x;

void dfs(int nod)
{
        viz[nod]=1;
        for(auto &nou:g[nod])
        {
                if(viz[nou]) continue;
                t[nou][0]=nod;
                dfs(nou);
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>x;
        x=n-x;
        for(int i=1;i<n;i++)
        {
                int x,y;
                cin>>x>>y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        viz[0]=1;
        dfs(n);
        for(int k=1;k<20;k++)
        {
                for(int i=1;i<=n;i++)
                {
                        t[i][k]=t[t[i][k-1]][k-1];
                }
        }
        x--;
        for(int i=1;i<=n;i++)
        {
                viz[i]=0;
        }
        viz[n]=1;
        for(int i=n-1;i>=1;i--)
        {
                if(viz[i]) continue;
                int co=0;
                int nod=i;
                for(int pas=19;pas>=0;pas--)
                {
                        int nou=t[nod][pas];
                        if(viz[nou]==0)
                        {
                                co+=(1<<pas);
                                nod=nou;
                        }
                }
                co++;
                if(co<=x)
                {
                        x-=co;
                        nod=i;
                        while(viz[nod]==0)
                        {
                                viz[nod]=1;
                                nod=t[nod][0];
                        }
                }
        }
        for(int i=1;i<=n;i++)
        {
                if(viz[i]==0)
                {
                        cout<<i<<" ";
                }
        }
        cout<<"\n";
        return 0;
}
/**

**/