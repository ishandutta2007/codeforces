// Problem: A. Theatre Square
// Contest: Codeforces - Codeforces Beta Round #1
// URL: https://codeforces.com/problemset/problem/1/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
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
signed main()
{
    int n=read(),m=read(),k=read();
    n=(n-1)/k+1;
    m=(m-1)/k+1;
    printf("%lld\n",n*m);
	return 0;
}