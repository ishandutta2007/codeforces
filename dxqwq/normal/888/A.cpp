// Problem: A. Local Extrema
// Contest: Codeforces - Educational Codeforces Round 32
// URL: https://codeforces.com/contest/888/problem/A
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
int a[1000003];
signed main()
{
	int n=read();
    for(int i=1; i<=n; i++) a[i]=read();
    int cnt=0;
    for(int i=2; i<n; i++){
    if(a[i-1]<a[i]&&a[i]>a[i+1]) ++cnt;
	if(a[i-1]>a[i]&&a[i]<a[i+1]) ++cnt;
	}
	printf("%d\n",cnt);return 0;
}