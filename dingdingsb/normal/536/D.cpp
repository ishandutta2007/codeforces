// Problem: CF536D Tavas in Kansas
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF536D
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=2e3+10;
namespace Dij{
	vector<pair<int,int>>e[N];
	void add(int u,int v,int w){
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	long long dis[N];bool vis[N];
	void work(int s){
		priority_queue<pair<long long,int>>q;
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		dis[s]=0;q.push({0,s});
		while(q.size()){
			int u=q.top().second;q.pop();
			if(vis[u])continue;vis[u]=1;
			for(auto [v,w]:e[u])if(dis[v]>dis[u]+w){
				assert(!vis[v]);
				dis[v]=dis[u]+w;
				q.push({-dis[v],v});
			}
		}
	}
}
using Dij::dis;
int n,m,s,t;
int p[N];
vector<long long>num;
int d1[N],d2[N];
int c1,c2;
template<class T>
struct Sum___{
	T s[N][N];
	T*operator[](const int x){return s[x];}
	void init(){
		for(int i=1;i<=c1;i++)
			for(int j=1;j<=c2;j++)
				s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	}
	T qry(int x1,int y1,int x2,int y2){
		return s[x2][y2]+s[x1-1][y1-1]-s[x2][y1-1]-s[x1-1][y2];
	}
};
Sum___<int>cnt;
Sum___<long long>val;
long long f[2][N][N];
signed main(){
	read(n,m,s,t);
	for(int i=1;i<=n;i++)read(p[i]);
	for(int i=1;i<=m;i++){
		int u,v,w;read(u,v,w);
		Dij::add(u,v,w);
	}
	Dij::work(s);
	for(int i=1;i<=n;i++)num.push_back(dis[i]);
	sort(num.begin(),num.end());num.resize(unique(num.begin(),num.end())-num.begin());
	for(int i=1;i<=n;i++)d1[i]=lower_bound(num.begin(),num.end(),dis[i])-num.begin()+1;
	c1=num.size();
	num.clear();
	Dij::work(t);
	for(int i=1;i<=n;i++)num.push_back(dis[i]);
	sort(num.begin(),num.end());num.resize(unique(num.begin(),num.end())-num.begin());
	for(int i=1;i<=n;i++)d2[i]=lower_bound(num.begin(),num.end(),dis[i])-num.begin()+1;
	c2=num.size();
	for(int i=1;i<=n;i++)
		cnt[d1[i]][d2[i]]++,
		val[d1[i]][d2[i]]+=p[i];
	cnt.init();val.init();
	for(int i=c1;i;i--)
		for(int j=c2;j;j--){
			if(cnt.qry(i,j,i,c2))f[0][i][j]=max(f[0][i+1][j],f[1][i+1][j])+val.qry(i,j,i,c2);
			else f[0][i][j]=f[0][i+1][j];
			if(cnt.qry(i,j,c1,j))f[1][i][j]=min(f[0][i][j+1],f[1][i][j+1])-val.qry(i,j,c1,j);
			else f[1][i][j]=f[1][i][j+1];
		}
	if(f[0][1][1]<0)puts("Cry");
	else if(f[0][1][1]==0)puts("Flowers");
	else puts("Break a heart");
}