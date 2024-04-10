#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int pow2[103];
int dfs(int l,int r,int dep,int x,int y)
{
	if(dep<0)
	{
		if(r-l==0) return x;
	if(r-l==1) return y;
	if(r-l==2) return x^y;
	}
	if(l+3LL*pow2[dep-2]>r) return dfs(l,r,dep-2,x,y);
	else if(l+6LL*pow2[dep-2]>r) return dfs(l+3LL*pow2[dep-2],r,dep-2,x+pow2[dep-2],y+2*pow2[dep-2]);
	else if(l+9LL*pow2[dep-2]>r) return dfs(l+6LL*pow2[dep-2],r,dep-2,x+2*pow2[dep-2],y+3*pow2[dep-2]);
	else return dfs(l+9LL*pow2[dep-2],r,dep-2,x+3*pow2[dep-2],y+pow2[dep-2]);
}
signed main()
{
	pow2[0]=1;
	for(int i=1; i<=60; i++) pow2[i]=pow2[i-1]<<1;
	int T=read();
	while(T--)
	{
		long long k=read();
		if(k<=3)
		{
			printf("%lld\n",k);
			continue;
		}
		int dep=0;
		long long now=1,tot=1;
		while(tot*3<k) dep+=2,now<<=2,tot+=now;
		tot-=now;
		printf("%lld\n",dfs(tot*3+1,k,dep,pow2[dep],pow2[dep+1]));
	}
	return 0;
}