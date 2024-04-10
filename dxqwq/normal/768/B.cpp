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
int g(int x)
{
	if(x<=1) return 1;
	return g(x/2)*2+1;
}
int f(int n,int l,int r)
{
	if(l>r) return 0;
	if(n==0) return 0;
	if(n==1) return 1;
	int x=g(n/2),res=0;
	if(r<=x) return f(n/2,l,r);
	else if(r==x+1) return f(n/2,l,x)+n%2;
	else if(l<=x+1) return n%2+f(n/2,l,x)+f(n/2,1,r-x-1);
	else return f(n/2,l-x-1,r-x-1);
}
signed main()
{
	int n=read(),l=read(),r=read();
	printf("%lld\n",f(n,l,r));
	return 0;
}