// Problem: E. Prime Gift
// Contest: Codeforces - Codeforces Round #456 (Div. 2)
// URL: https://codeforces.com/contest/912/problem/E
// Memory Limit: 256 MB
// Time Limit: 3500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int x[13],y[13];
vector<int> a,b;
int cnt1=0,cnt2=0;
void dfs1(int cur,int X,int lim)
{
	if(X>lim)
	{
		++cnt1;
		a.push_back(cur);
		return ;
	}
	__uint128_t now=cur,t=1000000000000000000ll;
	while(now<=t)
	{
		dfs1((int)now,X+1,lim);
		now=now*x[X];
	} 
	return ;
}
void dfs2(int cur,int Y,int lim)
{
	if(Y>lim)
	{
		++cnt2;
		b.push_back(cur);
		return ;
	}
	__uint128_t now=cur,t=1000000000000000000ll;
	while(now<=t)
	{
		dfs2((int)now,Y+1,lim);
		now=now*y[Y];
	} 
	return ;
}
signed main()
{
 	int n=read(),xx=n>>1,yy=n-xx;
 	if(n==1)
 	{
 		int A=read(),k=read();
 		int ans=1;
 		for(int i=1; i<k; i++) ans=ans*A;
 		printf("%lld\n",ans);
 		return 0;
 	}
 	for(int i=1; i<=xx; i++) x[i]=read();
 	for(int i=1; i<=yy; i++) y[i]=read();
	int k=read();
	if(k==1)
	{
		puts("1");
		return 0;
	}
	dfs1(1,1,xx);
	dfs2(1,1,yy);
	sort(a.begin(),a.end()),sort(b.begin(),b.end());
	int l=2,r=1000000000000000000ll,ans=1000000000000000000ll;
	--r;
	while(l<=r)
	{
		int mid=(l+r)>>1,cnt=0;
		for(int i=0,j=cnt2-1; i<cnt1; i++)
		{
			if(a[i]>mid) break;
			__uint128_t xxxlove_me_is_the_truth=a[i],MID=mid;
			while(xxxlove_me_is_the_truth*b[j]>MID)
			{
				--j;
				if(j<0) break;
			}
			if(j<0) break;
			cnt+=j+1;
		}
		if(cnt>=k) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}