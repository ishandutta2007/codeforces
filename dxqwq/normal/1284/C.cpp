// Problem: C. New Year and Permutation
// Contest: Codeforces - Hello 2020
// URL: https://codeforces.com/contest/1284/problem/C
// Memory Limit: 1024 MB
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
int p;
int qp(int x,int y)
{
	int t=1;
	for(int q=x; y; y>>=1,q=q*q%p)
	{
		if(y&1) t=t*q%p;
	}
	return t;
}
int fac[1000003],ifac[1000003];
signed main()
{
	int n=read();
	p=read();
	fac[1]=1;
	int ans=0;
	for(int i=2; i<=1000000; i++)
	fac[i]=fac[i-1]*i%p;
	for(int i=1; i<=n; i++)
	{
		ans=(ans+fac[n+1-i]*fac[i]%p*(n+1-i)%p)%p;
	}
	cout<<ans<<endl;
    return 0;
}