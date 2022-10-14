// Problem: B. Maximum Sum of Digits
// Contest: Codeforces - Codeforces Round #513 by Barcelona Bootcamp (rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1060/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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

signed main()
{
   	int n=read();
   	if(n<=9)
   	{
   		printf("%lld\n",n);
   		return 0;
   	}
   	int x=9,sum=9;
   	while(x*10+9<=n) x=x*10+9,sum+=9;
	int t=n-x;
	while(t) sum+=t%10,t/=10;
	printf("%lld\n",sum);
	return 0;
}