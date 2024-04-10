#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 200000
using namespace std;
int T,n,a[5][N+5];
char s[N*2+5];
bool cmp(int a,int b) {return a>b;}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s);
			for(int j=0;j<5;++j) a[j][i]=0;
			int len=strlen(s);
			for(int j=0;j<len;++j)
				++a[s[j]-'a'][i];
			for(int j=0;j<5;++j) a[j][i]=2*a[j][i]-len;
		}
		int ans=0;
		for(int i=0;i<5;++i)
		{
			int now=0,j=1;
			sort(a[i]+1,a[i]+1+n,cmp);
			while(j<=n && now+a[i][j]>0)
				now+=a[i][j],++j;
			ans=max(ans,j-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}