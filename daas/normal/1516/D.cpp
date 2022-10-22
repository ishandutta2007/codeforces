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
int n,q,jump[100010][20],las[100010],pd[100010],prime[100010],cnt,a[100010];
int calc(int l,int r)
{
	if(l>r) return 0;
	int LOG=log2(r-l+1);
	for(int i=LOG;i>=0;--i) if(jump[l][i] && jump[l][i]<=r) return (1<<i)+calc(jump[l][i]+1,r);
	return 1;
}
int main()
{
	for(int i=2;i<=100000;++i)
	{
		if(!pd[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt && (ll)i*prime[j]<=100000;++j)
		{
			pd[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=cnt;++i) las[i]=n+1;
	for(int i=n;i>=1;--i)
	{
		int LOG=log2(n-i+1),tmp=a[i],nxt=n+1;
		for(int j=1;prime[j]<=sqrt(tmp);++j) if(tmp%prime[j]==0)
		{
			while(tmp%prime[j]==0) tmp/=prime[j];
			nxt=min(nxt,las[j]);
			las[j]=i;
		}
		if(tmp!=1)
		{
			int id=lower_bound(prime+1,prime+cnt+1,tmp)-prime;
			nxt=min(nxt,las[id]);
			las[id]=i;
		}
		jump[i][0]=nxt-1;
		if(i!=n) jump[i][0]=min(jump[i][0],jump[i+1][0]);
		for(int j=1;j<=LOG && jump[i][j-1];++j) jump[i][j]=jump[jump[i][j-1]+1][j-1];
	}
	while(q--)
	{
		int l=read(),r=read();
		printf("%d\n",calc(l,r));
	}
	return 0;
}