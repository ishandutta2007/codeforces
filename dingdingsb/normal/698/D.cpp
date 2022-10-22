// Problem: CF698D Limak and Shooting Points
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF698D
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
const int N=1e3+10,M=10;
int k,n;vector<int>p[M][N];
struct vec{
	int x,y;
	vec(int x=0,int y=0):x(x),y(y){}
	vec operator+(const vec&rhs)const{return vec(x+rhs.x,y+rhs.y);}
	vec operator-(const vec&rhs)const{return vec(x-rhs.x,y-rhs.y);}
}a[M],b[N];
int cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
int dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
int vis[M],g[N],tim,cnt,tot;
int id[M];
bool check(int x){
	++tot;
	if(tot>k)return false;
	if(p[id[tot]][x].size()==0)return g[x]=tim,true;
	int _=tot;
	for(auto to:p[id[_]][x]){
		if(g[to]!=tim)if(!check(to))return false;
	}
	return g[x]=tim,true;
}
bool dfs(int now,int to){
	if(now>k){
		tim++;tot=0;
		return check(to);
	}
	for(int i=1;i<=k;i++)if(!vis[i]){
		vis[i]=1;
		id[now]=i;
		if(dfs(now+1,to))return true;
		vis[i]=0;
	}return false;
}
signed main(){
	read(k,n);
	for(int i=1;i<=k;i++)read(a[i].x,a[i].y);
	for(int i=1;i<=n;i++)read(b[i].x,b[i].y);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			for(int w=1;w<=n;w++)
				if(j!=w){
					if(cross(b[j]-a[i],b[w]-b[j])==0&&dot(a[i]-b[j],b[w]-b[j])<0)
						//printf("%d->%d->%d\n",i,j,w),
						p[i][w].push_back(j);
				}
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		if(dfs(1,i))ans++;
	}
	printf("%d",ans);
}