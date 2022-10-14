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
int l,r;
int count(int x)
{
	int cnt=0;
	for(int i=1; i<=x; i<<=1) if(i&x) ++cnt;
	return cnt;
}
int pmax(int x,int y)
{
	if(count(x)>=count(y)) return x;
	return y;
}
int dfs(long long t,long long x,int k)
{
	if(t>r||t+(x<<1)-1<l) return l;
	if(l<=t&&t+(x<<1)-1<=r) return t+(x<<1)-1;
	if(k==1)
	{
		if(t+1<=r) return t+1;
		else return t;
	}
	return pmax(dfs(t,x>>1,k-1),dfs(t+x,x>>1,k-1));
}
signed main()
{
	int T=read();
	while(T--)
	{
		l=read(),r=read();
		printf("%lld\n",dfs(0,1ll<<61,62));
	}
	return 0;
}