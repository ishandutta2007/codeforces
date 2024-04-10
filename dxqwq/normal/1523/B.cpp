// Problem: B. Lord of the Values
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//If I can prove that everyone is wrong......
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
int a[1000003];
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	for(int i=1; i<=n; ++i)
    	a[i]=read();
    	printf("%lld\n",n*3);
    	for(int i=1; i<=n; i+=2) for(int j=1; j<=3; ++j)
    	{
    		printf("1 %lld %lld\n",i,i+1);
    		printf("2 %lld %lld\n",i,i+1);
    	}
    }
	return 0;
}