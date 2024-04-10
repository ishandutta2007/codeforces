// Problem: B. Something with XOR Queries
// Contest: Codeforces - Codeforces Round #440 (Div. 1, based on Technocup 2018 Elimination Round 2)
// URL: https://codeforces.com/contest/871/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
bitset<10003> vis;
int a[10003],b[10003];
int A[10003],B[10003];
signed main()
{
	int n=read();
	if(n==1)
	{
		puts("!");
		puts("1");
		puts("0");
		return 0;
	}
	for(int i=0; i<n; ++i) 
	printf("? %d %d\n",i,0),fflush(stdout),a[i]=read();
	for(int i=0; i<n; ++i) 
	printf("? %d %d\n",0,i),fflush(stdout),b[i]=read();
	int C=0,s=0;
	for(int i=0; i<n; ++i)
	{
		vis.reset();
		for(int j=0; j<n; ++j) vis[a[i]^a[j]]=1;
		bool F=1;
		for(int j=0; j<n; ++j) if(vis[j]==0) F=0;
		if(!F) continue;
		int S=a[0]^a[i];
		vis.reset();
		for(int j=0; j<n; ++j) vis[b[j]^S]=1;
		for(int j=0; j<n; ++j) if(vis[j]==0) F=0;
		if(!F) continue;
		//++C,s=i;
		for(int j=0; j<n; ++j) A[j]=a[j]^a[i];
		for(int j=0; j<n; ++j) B[j]=b[j]^S;
		for(int j=0; j<n; ++j) if(B[A[j]]!=j) F=0;
		if(!F) continue;
		++C,s=i;
	}
	puts("!");
	printf("%d\n",C);
	for(int i=0; i<n; ++i) printf("%d ",a[i]^a[s]);puts("");
	return 0;
}