#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
char s[510][110];
char a[510],ans[510];
int n;
int v1[500],v2[500];
void work()
{
	rep(i,2*n-2)
	{
		//cout<<i<<endl;
		v1[i]=v2[i]=1;
		for(int j=1;j<=strlen(s[i]+1);j++)
			if (s[i][j]!=a[j])v1[i]=0;
		for(int j=n-strlen(s[i]+1)+1;j<=n;j++)
			if (s[i][j-n+strlen(s[i]+1)]!=a[j])v2[i]=0;
	}

	for(int i=1;i<=2*n-2;i++)if (v1[i]==0 && v2[i]==0)return;
	for(int i=1;i<2*n-2;i++)
		for(int j=i+1;j<=2*n-2;j++)
			if (strlen(s[i]+1)==strlen(s[j]+1))
			{
				if (v1[i]==0 && v1[j]==0)return;
				if (v2[i]==0 && v2[j]==0)return;
				if (v1[i]==1)ans[i]=1,ans[j]=2;
				else ans[i]=2,ans[j]=1;		
			}
	for(int i=1;i<=2*n-2;i++)putchar(ans[i]==1?'P':'S'); puts("");
	exit(0);
}
int main()
{
	scanf("%d",&n);

	int maxid1=0,maxid2=0;
	rep(i,2*n-2)
	{ 
		scanf("%s",s[i]+1); 
		if (strlen(s[i]+1)==n-1 && maxid1==0)maxid1=i;
		else if (strlen(s[i]+1)==n-1)maxid2=i;
	}
	for(int i=1;i<n;i++)a[i]=s[maxid1][i]; a[n]=s[maxid2][n-1]; a[n+1]=0;
//	printf("%s\n",a+1);
	work();
	for(int i=1;i<n;i++)a[i]=s[maxid2][i]; a[n]=s[maxid1][n-1]; a[n+1]=0;
//	printf("%s\n",a+1);
	work();
	return 0;
}