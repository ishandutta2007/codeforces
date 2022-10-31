#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
using namespace std;
char g[20][200];
int l[20],r[20];
int f1[30],f2[30];
int n,m;
int ans;
int cnt[30];
int main()
{	

	cin>>n>>m;
	int flag=0;
	for(int i=n;i>=1;i--)
	{
		getchar();
		l[i]=r[i]=0;
		cnt[i]=0;
		for(int j=1;j<=m+2;j++)
		{
			scanf("%c",&g[i][j]);
			if (g[i][j]=='1')r[i]=j;
			if (g[i][j]=='1'&&l[i]==0)l[i]=j;
			if (g[i][j]=='1')cnt[i]++;
		}
		if (l[i]==0)l[i]=m+2;
		if (r[i]==0)r[i]=1;
	}
	for(int i=n-1;i>=1;i--)cnt[i]+=cnt[i+1];
	f1[0]=0;
	f2[0]=2000003647;
	f1[1]=2*(r[1]-1);
	f2[1]=m+1;
	int now=-1;
	for(int i=2;i<n;i++)
	{
		if (cnt[i]==0){now=i; break; }
		f1[i]=min(f1[i-1]+1+2*(r[i]-1),f2[i-1]+1+m+1);
		f2[i]=min(f1[i-1]+1+m+1,f2[i-1]+1+2*(m+2-l[i]));
	}
	if (now==-1&&cnt[n]==0)now=n;
	if (now!=-1)now--; else now=n;
	ans=min(f1[now-1]+1+(r[now]-1),f2[now-1]+1+(m+2-l[now]));
	if (now==0)ans=0;
	if (now==1)ans--;
	cout<<ans<<endl;
	return 0;
}