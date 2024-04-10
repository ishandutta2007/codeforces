#include<bits/stdc++.h>
using namespace std;
bool vis[1234][1234];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		int px=(k+1)/2;
		int py=(k+1)/2;
		int ans1=0,ans2=0,ans3=0,ans4=1e9;
		
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=k-x+1;j++)
			{
				int sum = 0;
				bool flag = true;
				for(int t=j;t<j+x;t++)
				{
					if(vis[i][t]==true)
					{
						flag = false;
						break;
					}
					sum += abs(i-px)+abs(t-py);
				}
				if(flag==true && sum < ans4)
				{
					ans4=sum;
					ans1=i;
					ans2=j;
					ans3=j+x-1;
				}
			}
		}
		if(ans4==1e9)puts("-1");
		else
		{
			for(int i=ans2;i<=ans3;i++)
			{
				vis[ans1][i]=true;
			}
			printf("%d %d %d\n",ans1,ans2,ans3);
		}
	}
	return 0;
}