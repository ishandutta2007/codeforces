#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#define maxn 110000
using namespace std;
#define MAXN 200010
struct Suffix_Array
{
	int n,m,c[MAXN],y[MAXN],sa[MAXN],rank[MAXN],height[MAXN],st[MAXN][20],lg[MAXN];
	char s[MAXN];
	void build_SA()
	{
		for(int i=1;i<=n;i++)c[rank[i]=s[i]]++;
		for(int i=2;i<=m;i++)c[i]+=c[i-1];
		for(int i=n;i;i--)sa[c[rank[i]]--]=i;
		for(int k=1;k<=n;k<<=1)
		{
			int p=0;
			for(int i=n-k+1;i<=n;i++)y[++p]=i;
			for(int i=1;i<=n;i++)if(sa[i]>k)y[++p]=sa[i]-k;
			for(int i=1;i<=m;i++)c[i]=0;
			for(int i=1;i<=n;i++)c[rank[y[i]]]++;
			for(int i=2;i<=m;i++)c[i]+=c[i-1];
			for(int i=n;i;i--)sa[c[rank[y[i]]]--]=y[i];
			swap(rank,y);
			p=1;
			rank[sa[1]]=1;
			for(int i=2;i<=n;i++)rank[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p:++p;
			if(p>=n)break;
			m=p;
		}
	}
	void build_height()
	{
		int k=0;
		for(int i=1;i<=n;i++)
		{
			if(k)k--;
			int j=sa[rank[i]-1];
			for(;s[i+k]==s[j+k];k++);
			height[rank[i]]=k;
		}
		for(int i=1;i<=n;i++)st[i][0]=height[i];
		for(int j=1;j<=lg[n];j++)
		for(int i=1;i<=n-(1<<j)+1;i++)
		st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	int get_LCP(int x,int y)
	{
		if(x==y)return n-x+1;
		if(rank[x]>rank[y])swap(x,y);
		int len=lg[rank[y]-rank[x]];
		return min(st[rank[x]+1][len],st[rank[y]-(1<<len)+1][len]);
	}
	void init()
	{
		for(int i=1,j=0;i<MAXN;i<<=1,j++)lg[i]=j;
		for(int i=3;i<MAXN;i++)lg[i]=max(lg[i],lg[i-1]);
		build_SA();
		build_height();
	}
	void print()
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=sa[i];j<=n;j++)putchar(s[j]);
			printf(" %d\n",height[i]);
		}
	}
}SA;
int f[maxn][32];
int n,m,target;
char s1[maxn],s2[maxn];
void dp()
{
	int flag=0;
	memset(f,0,sizeof(f));
	for(int i=0;i<=n;i++)
		for(int j=0;j<=target;j++)
		{
			if (f[i][j]==m)flag=1;
			if (i==n)continue;
			f[i+1][j]=max(f[i+1][j],f[i][j]);
			if (f[i][j]==m)continue;
			int t=SA.get_LCP(i+1,n+2+f[i+1][j]);
			f[i+t][j+1]=max(f[i+t][j+1],f[i][j]+t);
		}
	if (flag)cout<<"YES"<<endl; else cout<<"NO"<<endl;
}
int main()
{
	cin>>n;
	scanf("%s",s1);
	cin>>m;
	scanf("%s",s2);
	cin>>target;
	for(int i=1;i<=n;i++)SA.s[i]=s1[i-1];
	SA.s[n+1]='$';
	for(int i=1;i<=m;i++)SA.s[n+1+i]=s2[i-1];
	SA.n=n+m+1;
	SA.m=255;
	SA.init();

	dp();
}