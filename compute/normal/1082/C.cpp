#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
vector<int> all[maxn];
int id[maxn];
int sum[maxn];
bool vis[maxn];
bool cmp(int a,int b)
{
    return all[a].size()>all[b].size();
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int s,r;
    memset(sum,0,sizeof(sum));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&s,&r);
        all[s].push_back(r);
    }
    for(int i=0;i<=m;i++)
        sort(all[i].begin(),all[i].end(),greater<int>());
    for(int i=0;i<=m;i++)
        id[i]=i;
    sort(id,id+m+1,cmp);
    int ans=0;
    int now=0;
    int ed=m;
    for(int i=0;i<=n;i++)
    {
        while(all[id[ed]].size()<i+1&&ed>=0)
        {
            if(!vis[ed])
                now-=sum[ed];
            vis[ed]=1;
            ed--;
        }
        for(int j=0;j<=ed;j++)
        {
            if(!vis[j])
            {
                now+=all[id[j]][i];
                sum[j]+=all[id[j]][i];
                if(sum[j]<0)
                {
                    now-=sum[j];
                    vis[j]=1;
                }
            }
        }
        ans=max(ans,now);
    }
    printf("%d\n",ans);

}