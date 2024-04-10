#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;
	scanf("%d",&x);
	return x;
}
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		if(n==1) 
		{
			printf("-1\n");
			continue;
		}
		for(int i=1; i<n; i++) printf("9");
		printf("8");
printf("\n");
		}	
	return 0;
}