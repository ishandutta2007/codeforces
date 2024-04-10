// Problem: D2. Frequency Problem (Hard Version)
// Contest: Codeforces - Codeforces Round #683 (Div. 1, by Meet IT)
// URL: https://codeforces.com/contest/1446/problem/D2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[200003],fir[400003];
int cnt[200003],ccnt[200003];
const int B=450;
void ins(int x){--ccnt[cnt[x]],++cnt[x],++ccnt[cnt[x]];}
void del(int x){--ccnt[cnt[x]],--cnt[x],++ccnt[cnt[x]];}
int main(){
	int n=read(),ans=0,d=0;
	for(int i=1; i<=n; ++i) ++cnt[a[i]=read()];
	for(int i=1; i<=n; ++i) (cnt[i]>cnt[d])&&(d=i);
	for(int i=1; i<=n; ++i) if(i!=d&&cnt[i]>B)
	{
		memset(fir,-1,sizeof(fir));
		fir[n]=0;
		for(int j=1,s=0; j<=n; ++j)
			s+=(a[j]==i)-(a[j]==d),
			(~fir[n+s])?ans=max(ans,j-fir[n+s]):fir[n+s]=j;
	}
	for(int i=1; i<=B; ++i)
	{
		memset(cnt,0,sizeof(cnt)),memset(ccnt,0,sizeof(ccnt));
		int l=1,r=0;
		while(r<n)
		{
			ins(a[++r]);
			while(cnt[a[r]]>i) del(a[l++]);
			(ccnt[i]>1)&&(ans=max(ans,r-l+1));
		}
	}
	printf("%d\n",ans);
	return 0;
}