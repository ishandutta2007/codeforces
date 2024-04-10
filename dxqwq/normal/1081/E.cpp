// Problem: E. Missing Numbers
// Contest: Codeforces - Avito Cool Challenge 2018
// URL: https://codeforces.com/contest/1081/problem/E
// Memory Limit: 256 MB
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
int a[1000003];
int ans[1000003];
void print(int n)
{
	for(int i=1; i<=n; i++) printf("%lld ",ans[i]);
	return ;
}
signed main()
{
	int c=0;
    int n=read(),m=n/2;
    for(int i=1,lst=0; i<=m; i++) 
    {
    	a[i]=read();
    	int X=0,Y=0,qwq=-1;
    	int j=1;
    	for(; j*j<=a[i]; ++j) ;
    	for(; j>=1; --j)if(a[i]%j==0)
    	{
    		int x=j,y=a[i]/x;
    		if((x&1)!=(y&1)) continue;
    		int a=(x+y)>>1,b=(y-x)>>1;
    		x=b,y=a;
    		if(x<=lst) continue;
    		qwq=0,X=x,Y=y;
    		break;
    	}
    	//printf("%lld %lld\n",X,Y);
    	if(qwq==-1)
    	{
    		puts("No");
    		return 0;
    	}
    	ans[++c]=X*X-lst*lst;
    	ans[++c]=Y*Y-X*X;
    	lst=Y;
    }
    puts("Yes");
    print(n);
	return 0;
}