// Problem: F1. Guess the K-th Zero (Easy version)
// Contest: Codeforces - Codeforces Round #719 (Div. 3)
// URL: https://codeforces.com/contest/1520/problem/F1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int sum(int l,int r)
{
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int x=read();
	return r-l+1-x;
}
signed main()
{
	int n=read(),op=read();
	int l=1,r=n;
	int k=read(),ans=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(sum(1,mid)>=k) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("! %d\n",ans);
	return 0;
}