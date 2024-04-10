#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int mod=998244353;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,K,a[200010],con[200010][2],b[200010],ans,id[200010];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),K=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		ans=1;
		for(int i=2;i<=n;++i)
			con[a[i]][0]=a[i-1];
		for(int i=1;i<n;++i)
			con[a[i]][1]=a[i+1];
		for(int i=1;i<=K;++i)
			id[b[i]=read()]=i;
		for(int i=1;i<=K;++i)
		{
			int cnt=0;
			if(con[b[i]][0] && id[con[b[i]][0]]<id[b[i]])
				++cnt;
			if(con[b[i]][1] && id[con[b[i]][1]]<id[b[i]])
				++cnt;
			ans=1ll*cnt*ans%mod;
			if(!cnt)
				break;
			if(con[b[i]][0] && id[con[b[i]][0]]<id[b[i]])
			{
				con[con[con[b[i]][0]][0]][1]=b[i];
				con[b[i]][0]=con[con[b[i]][0]][0];
			}
			else
			{
				con[con[con[b[i]][1]][1]][0]=b[i];
				con[b[i]][1]=con[con[b[i]][1]][1];
			}
		}
		for(int i=1;i<=K;++i)
			id[b[i]]=0;
		for(int i=2;i<=n;++i)
			con[a[i]][0]=0;
		for(int i=1;i<n;++i)
			con[a[i]][1]=0;
		con[0][1]=con[n+1][0]=0;
		printf("%d\n",ans);
	}
	return 0;
}