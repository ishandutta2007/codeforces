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
int T,n,K,a[100010],b[100010],c[100010],N,val[100010],ton[100010],mem[100010];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),K=read();
		for(int i=1;i<=n;++i) a[i]=read();
		if(K>=n) {puts("0");continue;}
		sort(a+1,a+n+1);
		N=0;
		for(int i=0;i<=n;++i) ton[i]=mem[i]=0;
		for(int l=1,r;l<=n;l=r+1)
		{
			r=l;
			while(r+1<=n && a[r+1]==a[r]) ++r;
			b[++N]=a[l];
			c[N]=r-l+1;
			if(a[l]<=n) ton[a[l]]=1;
			++mem[r-l+1];
		}
		int ctb=N,res=K,cur=0;
		while(cur<=n)
		{
			while(res>=cur && mem[cur]) res-=cur,--mem[cur],--ctb;
			if(mem[cur]) break;
			++cur;
		}
		int ans=n+1;
		int need=0;
		for(int mex=0,rem=0;mex<=n;++mex)
		{
			if(mex) need+=(ton[mex-1]==0);
			if(need>K) break;
			int st=upper_bound(a+1,a+n+1,mex)-a-1;
			if(n-st+1<=need) {ans=0;break;}
			while(rem+1<=N && b[rem+1]<=mex) ++rem;
			if(b[rem]==mex)
			{
				if(c[rem]<=cur)
				{
					res+=c[rem];
					while(cur<=n)
					{
						while(res>=cur && mem[cur]) res-=cur,--mem[cur],--ctb;
						if(mem[cur]) break;
						++cur;
					}
				}
				else --mem[c[rem]],--ctb;
			}
			ans=min(ans,ctb);
		}
		printf("%d\n",ans);
	}
	return 0;
}
//ore no turn,draw!