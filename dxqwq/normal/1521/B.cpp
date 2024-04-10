// Problem: B. Nastia and a Good Array
// Contest: Codeforces - Codeforces Round #720 (Div. 2)
// URL: https://codeforces.com/contest/1521/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int a[1000003];
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	for(int i=1; i<=n; ++i)
    	a[i]=read();	
    	int id=1;
    	
    	for(int i=2; i<=n; ++i) if(a[i]<a[id]) id=i;
    	if(id!=1)
    	{
    		printf("%lld\n",n);
    		printf("1 %lld %lld %lld\n",id,a[id],a[1]);
    		swap(a[1],a[id]);
    	}
    	else
	
	printf("%lld\n",n-1);
    	for(int i=2; i<=n; ++i) if(i%2==0) 
    	{
    		printf("1 %lld %lld %lld\n",i,a[1],a[1]+1);
    	}
    	else
    	{
    		printf("1 %lld %lld %lld\n",i,a[1],a[1]);
    	}
    }
	return 0;
}