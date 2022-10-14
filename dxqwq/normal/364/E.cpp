// Problem: E. Empty Rectangles
// Contest: Codeforces - Codeforces Round #213 (Div. 1)
// URL: https://codeforces.com/problemset/problem/364/E
// Memory Limit: 512 MB
// Time Limit: 12000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
ll ans=0;
char s[2503][2503];
int n=read(),m=read(),k=read();
int u[2503][8],d[2503][8];
//i-th 1 in this row/column
void solve(int x1,int x2,int y1,int y2)
{
	if(x1==x2&&y1==y2)
	{
		ans+=(s[x1][y1]=='1')==k;
		return ;
	}
	if(x2-x1>y2-y1)
	{
		int mid=(x1+x2)>>1;
		solve(x1,mid,y1,y2),solve(mid+1,x2,y1,y2);
		for(int i=y1; i<=y2; ++i)
		{
			u[i][0]=mid,d[i][0]=mid+1;
			for(int j=1; j<=k+1; ++j) u[i][j]=x1-1;
			for(int j=1; j<=k+1; ++j) d[i][j]=x2+1;
			for(int j=mid,t=0; t<=k&&j>=x1; --j)
				(s[j][i]=='1')&&(u[i][++t]=j);
			for(int j=mid+1,t=0; t<=k&&j<=x2; ++j)
				(s[j][i]=='1')&&(d[i][++t]=j);
		}
		for(int l=y1; l<=y2; ++l)
		{
			int cu[8],nu[8],cd[8],nd[8];
			cu[0]=nu[0]=mid,cd[0]=nd[0]=mid+1;
			for(int i=1; i<=k+1; ++i) cu[i]=x1-1;
			for(int i=1; i<=k+1; ++i) cd[i]=x2+1;
			for(int r=l; r<=y2; ++r)
			{
				for(int j=1,p1=1,p2=1; j<=k+1; ++j)
					nu[j]=cu[p1]>=u[r][p2]?cu[p1++]:u[r][p2++];
				for(int j=1,p1=1,p2=1; j<=k+1; ++j)
					nd[j]=cd[p1]<=d[r][p2]?cd[p1++]:d[r][p2++];
				swap(nu,cu),swap(nd,cd);
				for(int j=0; j<=k; ++j)
					ans+=(cu[j]-cu[j+1])*(cd[k-j+1]-cd[k-j]);
			}
		}		
	}
	else
	{
		int mid=(y1+y2)>>1;
		solve(x1,x2,y1,mid),solve(x1,x2,mid+1,y2);
		for(int i=x1; i<=x2; ++i)
		{
			u[i][0]=mid,d[i][0]=mid+1;
			for(int j=1; j<=k+1; ++j) u[i][j]=y1-1;
			for(int j=1; j<=k+1; ++j) d[i][j]=y2+1;
			for(int j=mid,t=0; t<=k&&j>=y1; --j)
				(s[i][j]=='1')&&(u[i][++t]=j);
			for(int j=mid+1,t=0; t<=k&&j<=y2; ++j)
				(s[i][j]=='1')&&(d[i][++t]=j);
		}
		for(int l=x1; l<=x2; ++l)
		{
			int cu[8],nu[8],cd[8],nd[8];
			cu[0]=nu[0]=mid,cd[0]=nd[0]=mid+1;
			for(int i=1; i<=k+1; ++i) cu[i]=y1-1;
			for(int i=1; i<=k+1; ++i) cd[i]=y2+1;
			for(int r=l; r<=x2; ++r)
			{
				for(int j=1,p1=1,p2=1; j<=k+1; ++j)
					nu[j]=cu[p1]>=u[r][p2]?cu[p1++]:u[r][p2++];
				for(int j=1,p1=1,p2=1; j<=k+1; ++j)
					nd[j]=cd[p1]<=d[r][p2]?cd[p1++]:d[r][p2++];
				swap(nu,cu),swap(nd,cd);
				for(int j=0; j<=k; ++j)
					ans+=(cu[j]-cu[j+1])*(cd[k-j+1]-cd[k-j]);
			}
		}		
	}
	return ;
}
signed main()
{
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	solve(1,n,1,m);
	printf("%lld\n",ans);
	return 0;
}