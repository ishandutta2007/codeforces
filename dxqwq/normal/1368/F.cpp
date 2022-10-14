// Problem: F. Lamps on a Circle
// Contest: Codeforces - Codeforces Global Round 8
// URL: https://codeforces.com/problemset/problem/1368/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003],cnt;
bool vis[100003];
signed main(){
	int n=read();
	if(n<=3) puts("0"),exit(0);
	int x=1;
	while(x*x<n) ++x;
	for(int i=1; i<=n; ++i) ((i-1)%x)&&(a[++cnt]=i);
	while(1)
	{
		printf("%d ",x);
		for(int i=1;i<=x;i++)
			printf("%d ",a[cnt]),vis[a[cnt--]]=1;
		puts("");
		fflush(stdout);
		int y=read();
		for(int i=0; i<x; i++)
			(vis[(y+i-1)%n+1])&&(a[++cnt]=(y+i-1)%n+1,vis[(y+i-1)%n+1]=0);
		if(x>cnt)break;
	}
	puts("0");
	fflush(stdout);
	return 0;
}