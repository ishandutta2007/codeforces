// Problem: F. Points Movement
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
//And in that light,I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#define fi first
#define se second
int a[1000003];
pair<int,int> b[1000003],tmp[1000003];
bool cmp(pair<int,int> A,pair<int,int> B)
{
	if(A.fi!=B.fi) return A.fi<B.fi;
	return A.se>B.se;
}
int l[1000003],r[1000003];
int f[1000003][2][2];
//left point move l/r first
//right point move l/r first
signed main()
{
	for(int T=read();T--;)
	{
		int n=read()+1,o=read();
		a[1]=-1e12;
		for(int i=2; i<=n; ++i) a[i]=read();
		a[++n]=1e12;
		sort(a+1,a+n+1);
		for(int i=1; i<=o; ++i) 
		{
			b[i].fi=read(),b[i].se=read();
			int L=lower_bound(a+1,a+n+1,b[i].fi)-a,
			R=upper_bound(a+1,a+n+1,b[i].se)-a;
			if(L<R) --i,--o;
		}
		sort(b+1,b+o+1,cmp);
		int m=0;
		for(int i=1; i<=o; ++i)
		{
			while(m&&tmp[m].se>=b[i].se) --m;
			++m,tmp[m]=b[i];
		}
		for(int i=1; i<=m; ++i) b[i]=tmp[i];
		for(int i=1; i<=n; ++i) l[i]=r[i]=0;
		for(int i=1,pos=0; i<=m; ++i)
		{
			int x=lower_bound(a+1,a+n+1,b[i].fi)-a;
			if(!l[x]) l[x]=r[x]=i;
			else r[x]=i;
		}
		for(int i=2; i<=n; ++i)
		{
			for(int p=0; p<=1; ++p)
				for(int q=0; q<=1; ++q)
					f[i][p][q]=1e18;
			for(int p=0; p<=1; ++p)
				for(int q=0; q<=1; ++q)
					for(int rr=0; rr<=1; ++rr)
					if(!l[i])
					{
						f[i][q][rr]=min(f[i-1][p][q^1],f[i][q][rr]);
					}
					else
					{
						for(int t=l[i]+1; t<=r[i]; ++t)
						{
							f[i][q][rr]=min(f[i][q][rr],
							f[i-1][p][q^1]+(q+1)*(b[t-1].fi-a[i-1])
							+(rr+1)*(a[i]-b[t].se));
						}
						f[i][q][rr]=min(f[i][q][rr],
						f[i-1][p][q^1]+(rr+1)*(a[i]-b[l[i]].se));
						f[i][q][rr]=min(f[i][q][rr],
						f[i-1][p][q^1]+(q+1)*(b[r[i]].fi-a[i-1]));
					}
		}
		
		int Ans=1e18;
		for(int p=0; p<=1; ++p)
		for(int q=0; q<=1; ++q)
		Ans=min(Ans,f[n][p][q]);
		printf("%lld\n",Ans);
	}
	return 0;
}