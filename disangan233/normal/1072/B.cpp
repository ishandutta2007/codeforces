#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],t[100005];


inline int solve(int x) 
{
	if(x>n) 
	return 1;
	int bj=0;
	for(int i=0;i<4&&!bj;i++)
	if((i&t[x-1])==b[x-1]
	&&(i|t[x-1])==a[x-1])
	t[x]=i,
	bj|=solve(x+1);
	return bj;
}


int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	scanf("%d",&b[i]);
	for(int i=0;i<4;i++) 
	{
		t[1]=i;
		if(solve(2)) 
		{
			puts("YES");
			for(i=1;i<=n;i++)
			printf("%d",t[i]),
			putchar(i==n?'\n':' ');
			return 0;
		}
	}
	puts("NO");
	return 0;
}