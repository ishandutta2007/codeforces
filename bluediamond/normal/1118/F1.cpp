#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)3e5+7;

int n;
int a[N];

vector<int>g[N];

int red[N];
int blue[N];

bool viz[N];

void calc(int nod)
{
        viz[nod]=1;
        if(a[nod]==1)
        {
                red[nod]++;
        }
        if(a[nod]==2)
        {
                blue[nod]++;
        }
        for(auto &nou:g[nod])
        {
                if(viz[nou]) continue;
                calc(nou);
                blue[nod]+=blue[nou];
                red[nod]+=red[nou];
        }
}

int ans=0;

void dfs(int nod)
{
        viz[nod]=1;
        for(auto &nou:g[nod])
        {
                if(viz[nou]) continue;
                dfs(nou);
              ///  cout<<nod<<" : "<<red[nod]<<" , "<<blue[nod]<<"\n";
                if(red[1]==0 || blue[1]==0)
                {
                        ans++;
                        continue;
                }
                if(red[nou]==red[1] && blue[nou]==0)
                {
                        ans++;
                        continue;
                }
                if(blue[nou]==blue[1] && red[nou]==0)
                {
                        ans++;
                        continue;
                }
        }
}

int32_t main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
        }
        for(int i=1;i<n;i++)
        {
                int x,y;
                cin>>x>>y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        calc(1);
        for(int i=1;i<=n;i++)
        {
                viz[i]=0;
        }
        dfs(1);
        cout<<ans<<"\n";
        return 0;
}
/**



**/