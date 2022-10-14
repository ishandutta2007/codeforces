// Problem: D. Tree
// Contest: Codeforces - ICM Technex 2018 and Codeforces Round #463 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/contest/932/problem/D
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
int cnt=2;
int val[1000003];
int mx[400003][20];
int fa[400003][20];
int sum[400003][20];
signed main()
{
	val[1]=20000000000000000ll;
	for(int i=0; i<20; ++i) 
	fa[1][i]=fa[2][i]=1,mx[1][i]=20000000000000000ll,mx[2][i]=20000000000000000ll,
	sum[1][i]=20000000000000000ll,sum[2][i]=20000000000000000ll;
    for(int T=read(),x,y,op,lst=0; T--;)
    {
    	op=read(),x=read()^lst,y=read()^lst;
    	++x;
    	if(op==1)
    	{
    		val[++cnt]=y;
    		if(val[x]<y)
    		{
    			for(int i=19; i>=0; --i) if(mx[x][i]<y) x=fa[x][i];
    			x=fa[x][0];
    		}
    		fa[cnt][0]=x,sum[cnt][0]=val[fa[cnt][0]],mx[cnt][0]=val[fa[cnt][0]];
    		for(int i=1; i<20; ++i) 
    		fa[cnt][i]=fa[fa[cnt][i-1]][i-1],
    		mx[cnt][i]=max(mx[cnt][i-1],mx[fa[cnt][i-1]][i-1]),
    		sum[cnt][i]=sum[cnt][i-1]+sum[fa[cnt][i-1]][i-1];
    		//printf("%lld %lld %lld\n",fa[cnt][i],mx[cnt][i],sum[cnt][i]);
    	}
    	else
    	{
    		if(val[x]>y)
			{
				puts("0");
				lst=0;
				continue;
			}
			int ans=1;
			y-=val[x];
			for(int i=19; i>=0; --i) if(sum[x][i]<=y) y-=sum[x][i],ans+=(1ll<<i),x=fa[x][i];
			printf("%lld\n",lst=ans);
    	}
    }
	return 0;
}