#include<bits/stdc++.h>
using namespace std;
char a[123][123];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	 }
	
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<m;j++)
	 	{
	 		if(a[i][j]!=a[i][j+1])
	 		{
	 			puts("NO");exit(0);
			}
	 	}
	 	if(i<n && a[i][1]==a[i+1][1])
	 	{
	 		puts("NO");exit(0);
		}
	 }
	 puts("YES");
	 
	return 0;
}