#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
long long qp(long long x)
{
	if(x==0) return 1LL;
	if(x==1) return 2LL;
	long long t=qp(x>>1);
	if(x&1) return t*t%998244353LL*2%998244353LL;
	return t*t%998244353LL;
}
int main()
{
	long long n=read()+read();
	cout<<qp(n);
	return 0;
}