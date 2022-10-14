// Problem: F. Attack on Red Kingdom
// Contest: Codeforces - Educational Codeforces Round 83 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1312/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
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
int sdt,len;
int f[100003][4];
void init(int x,int y,int z)
{
	unordered_map<unsigned,int> mp;
	mp[0]=0;
	bool F=0;
	for(int i=5; i<=1000; ++i)
	{
		unsigned s=0;
		bool vis[5];
		memset(vis,0,sizeof(vis)),
		f[i][0]=f[i][1]=f[i][2]=0;
		vis[f[i-x][0]]=vis[f[i-y][1]]=vis[f[i-z][2]]=1;
		while(vis[f[i][0]]) ++f[i][0];
		memset(vis,0,sizeof(vis)),
		vis[f[i-x][0]]=vis[f[i-z][2]]=1;
		while(vis[f[i][1]]) ++f[i][1];
		memset(vis,0,sizeof(vis)),
		vis[f[i-x][0]]=vis[f[i-y][1]]=1;
		while(vis[f[i][2]]) ++f[i][2];
		f[i][3]=(f[i][0]<<4)+(f[i][1]<<2)+f[i][2];
		for(int j=i-4; j<=i; ++j) 
		s=(s<<6)+f[j][3];
		if(mp.find(s)!=mp.end())
		{
			sdt=mp[s],len=i-4-mp[s];
			F=1;
			break;
		}
		mp[s]=i-4;
	}
	if(!F)
	{
		puts("cmllcmllcmllcelestefst cmllcmllcmllcmllcmllcmllcmllcmllcmllcmllcmllcmllcmllcmllcmllcmllcmll,cmll,cmllcmllcmllcmllcmllcmllcmll!!cmll");
	}
	return ;
}
int solve(int x)
{
	if(x<sdt) return x;
	return sdt+(x-sdt)%len;
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),x=read(),y=read(),z=read();
		init(x,y,z);
		int c[4],s=0;
		c[0]=c[1]=c[2]=c[3]=0;
		for(int i=1,G,A,B,C; i<=n; ++i)
			G=read()+4,
			A=f[solve(G-x)][0],   
			B=f[solve(G-y)][1],
			C=f[solve(G-z)][2],
			G=f[solve(G)  ][0],
			++c[A^G],++c[B^G],++c[C^G],s^=G;
		printf("%lld\n",c[s]);
	}
    return 0;
}