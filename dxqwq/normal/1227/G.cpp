// Problem: CF1227G Not Same
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1227G
// Memory Limit: 250 MB
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
pair<int,int> a[5003];
int f[5003][5003];
bool cmp(pair<int,int> A,pair<int,int> B)
{
	return A.first>B.first;
}
signed main()
{
	int n=read();
	for(int i=0; i<n; ++i) a[i]=make_pair(read(),i);
	sort(a,a+n,cmp);
	printf("%d\n",n+1);
	for(int ii=0; ii<n; ++ii)
	{ 
		int i=a[ii].first,I=a[ii].second;
		for(int j=0; j<i; ++j) f[(ii+j)%(n+1)][I]=1;
	}
	for(int i=0; i<=n; ++i,puts("")) for(int j=0; j<n; ++j) printf("%d",f[i][j]);
	return 0;
}