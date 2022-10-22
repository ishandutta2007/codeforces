#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
#define lowbit(k) (k&-k)
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,a[2010],father[2010];
int find(int k)
{
	if(father[k]!=k) father[k]=find(father[k]);
	return father[k];
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y) father[x]=y;
}
int check()
{
	for(int i=1;i<=n;++i) father[i]=i;
	for(int i=0;i<=30;++i)
	{
		int st=1; while(st<=n && !((a[st]>>i)&1)) ++st;
		if(st>n) continue;
		for(int j=st+1;j<=n;++j) if((a[j]>>i)&1) merge(st,j);
	}
	int num=0;
	for(int i=1;i<=n;++i) num+=(find(i)==i);
	return num==1;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			if(!a[i]) ++a[i],++ans;
		}
		if(check())
		{
			printf("%d\n",ans);
			for(int i=1;i<=n;++i) printf("%d ",a[i]);
			putchar('\n');
			continue;
		}
		int flag=0;
		for(int i=1;i<=n;++i)
		{
			++a[i];
			if(check()) {flag=1;break;}
			--a[i];
			if(a[i])
			{
				--a[i];
				if(check()) {flag=1;break;}
				++a[i];
			}
		}
		if(flag)
		{
			printf("%d\n",ans+1);
			for(int i=1;i<=n;++i) printf("%d ",a[i]);
			putchar('\n');
		}
		else
		{
			printf("%d\n",ans+2);
			int maxn=0;
			for(int i=1;i<=n;++i) maxn=max(maxn,lowbit(a[i]));
			int x=0,y=0;
			for(int i=1;i<=n;++i) if(lowbit(a[i])==maxn)
			{
				if(!x) x=i;
				else y=i;
			}
			--a[x];
			++a[y];
			for(int i=1;i<=n;++i) printf("%d ",a[i]);
			putchar('\n');
		}
	}
	return 0;
}
//ore no turn,draw!