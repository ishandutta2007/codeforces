//  228

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j,k,judge=1;
	char a[100][100];
	scanf("%d %d",&n,&m);
	getchar();
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%c",&a[i][j]);
		}
		getchar();
	}

	for(i=0;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
				if(a[i][0]!=a[i][j])
				{
					printf("NO");
					return 0;
				}
		}
		
		if(a[i][0]==a[i+1][0])
			{
				printf("NO");
				return 0;
			}	
	}

	
	printf("YES");
	return 0;
}