// Problem: D. Vasya and Arrays
// Contest: Codeforces - Educational Codeforces Round 50 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1036/problem/D
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
int a[1000003],b[1000003];
signed main()
{
 	int n=read(),m,sum1=0,sum=0;
 	for(int i=1; i<=n; i++) a[i]=read(),sum1+=a[i];   
	m=read();
	for(int i=1; i<=m; i++) b[i]=read(),sum+=b[i];
int x=1,y=1,A=a[1],B=b[1];
	if(sum1!=sum)
	{puts("-1");return 0;}
	int ans=0;
	while(x<=n&&y<=m)
	{
		if(A==B) ++x,++y,A=a[x],B=b[y],++ans;
		else if(A<B) ++x,A+=a[x];
		else ++y,B+=b[y];
	}
	printf("%lld\n",ans);
	return 0;
}