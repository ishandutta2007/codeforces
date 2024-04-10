//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int n,m;
int f[70][2][2][2];
int dfs(int x,int y,int z,int w)
{
	if(x==63) return (y==1)&&(z==1)&&(w==0);
	if(~f[x][y][z][w]) return f[x][y][z][w];
	int A=(n>>x)&1,B=(m>>x)&1;
	return f[x][y][z][w]=(
		dfs(x+1,max(A,y),z^((B+w)&1),B+w>1)+
		dfs(x+1,min(A,y),z^((B+w)&1),B+w>0)
	);
}
signed main()
{
	for(int T=read(); T--;)
	{
		m=read();
		n=read()-1;
		memset(f,-1,sizeof(f));
		printf("%lld\n",dfs(0,1,0,0));
	}
	return 0;
}