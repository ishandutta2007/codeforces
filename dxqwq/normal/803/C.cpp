// Problem: C. Maximal GCD
// Contest: Codeforces - Educational Codeforces Round 20
// URL: https://codeforces.com/contest/803/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
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

signed main()
{
	int n=read(),m=read();
	if(m>1000000||n<m*(m+1)/2)
	{
		puts("-1");
		return 0;	
	}
	int g=m*(m+1)/2;
	int G=1,L=n;
	for(int i=1; i<=100000; i++)
	if(n%i==0)
	{
		if(n/i>=g)if(i>G){
		G=i;
		L=n/i;}
		if(i>=g)
		{
			if(n/i>G){
			G=n/i;
			L=i;}
		}
	}
	for(int i=1; i<m; i++)
	printf("%lld ",i*G),L-=i;
	printf("%lld\n",L*G);
    return 0;
}