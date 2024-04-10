#include<bits/stdc++.h>
using namespace std;
const int N=234;
vector<int> Tree[N];
int ans;
//
//
// 
int n,deep;
bool Map[N][N];

int dfs(int son,int root)
{
    int s=0;
    int maxd1=0,maxd2=0;
    for(int i=1;i<=n;i++)
	{
        if(Map[son][i]==true && i!=root)
		{
			int tmp = dfs(i,son);
            s=max(tmp,s);
            if(deep>maxd1)
			{
                maxd2=maxd1;
                maxd1=deep;
            }
            else maxd2=max(deep,maxd2);
        }
    }
    s=max(s,maxd1+maxd2);
    deep=maxd1+1;
    return s;
}

int main()
{
   int u,v;
   cin>>n;
    memset(Map,0,sizeof(Map));
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        Map[u][v]=Map[v][u]=true;
    }
  	ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1;j<=n;j++)
        {
          	if(Map[i][j]==true)
         	{
               	int a=dfs(i,j);
               	int b=dfs(j,i);
               	ans=max(ans,a*b);
           	}
        }
	}
    cout<<ans<<endl;
    return 0;
}