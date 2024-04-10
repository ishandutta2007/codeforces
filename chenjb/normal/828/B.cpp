#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110][110];
int n,m;
int main()
{
	cin>>n>>m;
	char s[110];
	memset(a,0,sizeof(a));
	int total=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			if (s[j]=='B')a[i][j]++,total++;
		}
	}
	int ans=2147483647;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int p=1;p<=min(n-i+1,m-j+1);p++)
			{
				int now=a[i+p-1][j+p-1]-a[i-1][j+p-1]-a[i+p-1][j-1]+a[i-1][j-1];
				if (now!=total)continue;
				ans=min(ans,p*p-now);
			}
	if (ans==2147483647)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;

}