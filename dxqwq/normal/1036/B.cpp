// Problem: B. Diagonal Walking v.2
// Contest: Codeforces - Educational Codeforces Round 50 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1036/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int solve(int n,int m,int k)
{
 		if(max(n,m)>k)
 		{
 			return -1;
 		}	
 		if(abs(n-m)&1)
 		{
 			if(n<m) --m;
 			else --n;
 			--k;
 		}
 		int x=min(n,m)+(abs(n-m)/2)*2,z=k-max(n,m);
 		x+=(z>>1)*2;
 		if(z&1) return -1;
 		return x;
}
signed main()
{
 	for(int T=read();T--;)
 	{
 		int n=read(),m=read(),k=read();
printf("%lld\n",max(max(solve(n,m,k),max(solve(n-1,m,k-1),solve(n,m-1,k-1))),max(solve(n,m,k),max(solve(n+1,m,k-1),solve(n,m+1,k-1)))));
 	}   
	return 0;
}