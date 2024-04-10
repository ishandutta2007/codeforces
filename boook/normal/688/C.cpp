#include<bits/stdc++.h>
using namespace std;
#define MAX 100050
vector<int> v[MAX];int dp[MAX];
int DFS(int y)
{
    for(int i=0;i<v[y].size();i++)
    {
        if(dp[ v[y][i] ]==-1)
        {
            dp[ v[y][i] ]=1-dp[y];
            if(DFS(v[y][i])==0)return 0;
        }
        else if(dp[ v[y][i] ]== dp[y])return 0;
    }
    return 1;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<MAX;i++)
            v[i].clear();
        for(int i=0,q,w;i<m;i++)
            scanf("%d%d",&q,&w),v[q].push_back(w),v[w].push_back(q);
        memset(dp,-1,sizeof dp);
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            if(dp[i]==-1)
            {//cout<<"i="<<i<<endl;
                dp[i]=0;
                if(DFS(i)==0)ans=0;
            }
        }
        vector<int> aa,bb;
//        for(int i=1;i<=n;i++)
//            printf("%d ",dp[i]);puts("");
        for(int i=1;i<=n;i++)
            if(dp[i]==0)aa.push_back(i);
            else bb.push_back(i);
        if(!ans)puts("-1");
        else if(bb.empty())
        {
            printf("%d\n",aa.size()-1);
            printf("%d",aa[1]);
            for(int i=2;i<aa.size();i++)
                printf(" %d",aa[i]);puts("");
            printf("1\n%d\n",aa[0]);
        }
        else
        {
            printf("%d\n",aa.size());
            printf("%d",aa[0]);
            for(int i=1;i<aa.size();i++)
                printf(" %d",aa[i]);puts("");
            printf("%d\n",bb.size());
            printf("%d",bb[0]);
            for(int i=1;i<bb.size();i++)
                printf(" %d",bb[i]);puts("");
        }

    }
    return 0;
}