#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
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
int n,m,mod,father[100001],vis[100001],size[100001],ans=1;
int find(int k)
{
	if(father[k]!=k) father[k]=find(father[k]);
	return father[k];
}
void merge(int x,int y)
{
	int ax=find(x),ay=find(y);
	if(ax==ay) return;
	father[ax]=ay,size[ay]+=size[ax];
}
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y&1) z=(ll)z*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return z;
}
int main()
{
	n=read(),m=read(),mod=read();
	for(int i=1;i<=n;++i) father[i]=i,size[i]=1;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		merge(u,v);
	}
	int K=0;
	for(int i=1;i<=n;++i)
	{
		int id=find(i);
		if(!vis[id]) vis[id]=1,++K,ans=(ll)ans*size[id]%mod;
	}
    if(K==1)
    {
        printf("%d\n",1%mod);
        return 0;
    }
	ans=(ll)ans*ksm(n,K-2)%mod;
	printf("%d\n",ans);
	return 0;
}