#include<bits/stdc++.h>
#define ll long long
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline long long readll(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
long long n;
void nxt(int&x,int&y){if(y!=n) ++y;else {++x;y=x+1;}if(x==n) x=1;}
void cnt(ll m,int&x,int&y)
{
	if(m>n*(n-1)/2) {x=1;y=1;return;}
	ll a=0,b=0;
	while(a<m) {a+=n-1-b;++b;}
	a-=n-b;
	x=b;y=m-a+b;
}
signed main()
{
	int T=read();
	while(T--)
	{
		n=readll();
		long long l=read(),r=read(),x,y;
		cnt((l+1)/2,x,y);
		for(int t=l; t<=r; t++) if(t%2) printf("%lld ",x);else printf("%lld ",y),nxt(x,y);
		puts("");
	}
	return 0;
}