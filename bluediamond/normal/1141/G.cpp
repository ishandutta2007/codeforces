#include <iostream>
#include <vector>

using namespace std;

const int N=200000+7;
int n,k;
int sum[N];
vector<int>g[N];

int kol;
int col[N];
bool viz[N];
int cost;

void dfs(int nod,int papa)
{
        viz[nod]=1;
        int nefol=0;
        for(auto &i:g[nod])
        {
                int nou=sum[i]-nod;
                if(nou==papa)
                {
                        nefol=col[i];
                }
        }
        int id=0;
        for(auto &i:g[nod])
        {
                if(col[i]==-1)
                {
                        id++;
                        if(id==nefol)
                        {
                                id++;
                        }
                        if(id>kol)
                        {
                                break;
                        }
                        col[i]=id;
                }
        }
        bool add=0;
        for(auto &i:g[nod])
        {
                if(col[i]==-1)
                {
                        add=1;
                        col[i]=1;
                }
        }
        if(add)
        {
                cost++;
        }
        for(auto &i:g[nod])
        {
                int nou=sum[i]-nod;
                if(viz[nou]==0)
                {
                        dfs(nou,nod);
                }
        }
}

bool ok(int vla)
{
        cost=0;
        kol=vla;
        for(int i=1;i<=n;i++)
        {
                col[i]=-1;
                viz[i]=0;
        }
        dfs(1,0);
        return (cost<=k);
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
                int x,y;
                cin>>x>>y;
                sum[i]=x+y;
                g[x].push_back(i);
                g[y].push_back(i);
        }
        int lo=1;
        int hi=n-1;
        int rs;
        while(lo<=hi)
        {
                int mid=(lo+hi)>>1;
                if(ok(mid))
                {
                        rs=mid;
                        hi=mid-1;
                }
                else
                {
                        lo=mid+1;
                }
        }
        cout<<rs<<"\n";
        ok(rs);
        for(int i=1;i<n;i++)
        {
                cout<<col[i]<<" ";
        }
        cout<<"\n";
        return 0;
}