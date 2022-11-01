#include<bits/stdc++.h>
using namespace std;
const int mod = 9973;
typedef long long ll;
const int N = 345;
int n,m;
ll link[1 << 20][20], circle[1 << 20];
bool vis[20][20];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;v--;
		vis[u][v]=1;
		vis[v][u]=1;
	}
	for(int i=0;i<n;i++)
	{
		link[1<<i][i] = 1;
	}
	int limit = 1<<n;
	ll sum = 0;
	for(int i=1;i<limit;i++)
	{
		int beg = -1;
		for(int j=0;j<n;j++)
		{
			if((i>>j)& 1)
			{
				if(beg==-1){
					beg = j;
				}
				for(int k=beg+1;k<n;k++)
				{
					if(!((i>>k)& 1))
					{
						int target = i + (1<<k);
						if(vis[j][k])
						{
							link[target][k] += link[i][j];
						}
						if(vis[j][k] && vis[beg][k])
						{
							circle[target] += link[i][j];
						}
						
					}
				}
			}
		}
		//cout<<"i="<<i<<" "<<circle[i]<<endl;
		if(__builtin_popcount(i) >= 3)
		{
			//cout<<"i="<<i<<endl;
			sum+=(circle[i] /2 );
		}
		
	}
	cout<<sum<<endl;
	return 0;	
} 
/*
4 6
1 2
1 3
1 4
2 3
2 4
3 4

7
*/