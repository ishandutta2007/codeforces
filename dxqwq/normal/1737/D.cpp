// Problem: D. Ela and the Wiring Wizard
// Contest: Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<pair<int,int> > e[1000003];
int d[503][503];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i) e[i].clear();
		for(int i=1; i<=n; ++i)
			memset(d[i],0x3f,sizeof(d[i]));
	    for(int i=1,x,y,z; i<=m; i++) 
	    	x=read(),y=read(),z=read(),
	    	d[x][y]=d[y][x]=1,
	    	e[x].push_back(make_pair(y,z)),
	    	e[y].push_back(make_pair(x,z));
	   	for(int i=1; i<=n; ++i) d[i][i]=0;
	   	for(int i=1; i<=n; ++i)
	   		for(int j=1; j<=n; ++j)
	   			for(int k=1; k<=n; ++k)
	   				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
	    int ans=1e18;
	    for(int i=1; i<=n; ++i)
	    	for(auto [j,k]:e[i])
	    	{
	    		ans=min(ans,(d[1][i]+d[j][n]+1)*k);
	    		for(int l=1; l<=n; ++l)
	    			ans=min(ans,(d[1][l]+d[l][n]
	    			+min(d[i][l],d[j][l])+2)*k);
	    	}
	    printf("%lld\n",ans);
	}
	return 0;
}