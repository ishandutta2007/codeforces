// Problem: B. Serval and Toy Bricks
// Contest: Codeforces - Codeforces Round #551 (Div. 2)
// URL: https://codeforces.com/contest/1153/problem/B
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
int a[103];
int b[103];
int f[103][103];
int ans[103][103];
signed main()
{
 	int n=read(),m=read(),k=read();
 	for(int i=1; i<=m; i++) a[i]=read();
 	for(int i=1; i<=n; i++) b[i]=read();
 	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) f[i][j]=read();
 	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(f[i][j])
 	{
 		ans[i][j]=min(a[j],b[i]);
 	}
 	for(int i=1; i<=n; i++,puts("")) for(int j=1; j<=m; j++) printf("%d ",ans[i][j]);
	return 0;
}