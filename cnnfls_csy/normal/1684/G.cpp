#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
#ifndef ONLINE_JUDGE
	FILE* _=freopen("1.in","r",stdin);
#endif
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
inline void read(long long &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int dis[1005],vis[1005],tot,cst,s=0,t=1001;
struct ii
{
	int y,z;
}e[3000005];
vector<int> bi[1005];
vector<int>::iterator hd[1005];
void init()
{
	int i;for(i=0;i<=t;i++)bi[i].clear();
	tot=0;
}
void add(int x,int y,int z)
{
	tot++;
	bi[x].push_back(tot*2-2);
	bi[y].push_back(tot*2-1);
	e[tot*2-2]=(ii){y,z};
	e[tot*2-1]=(ii){x,0};
}
bool bfs(int s,int t)
{
	queue<int> qx;memset(dis,0x3f,sizeof(dis));
	dis[s]=0;qx.push(s);
	while(!qx.empty()){
		int x=qx.front();qx.pop();
		ff(bi[x],it){
			if(e[*it].z&&dis[e[*it].y]>dis[x]+1){
				dis[e[*it].y]=dis[x]+1;
				qx.push(e[*it].y);
			}
		}
	}
	return dis[t]<dis[t+1];
}
int dfs(int x,int tt,int flw)
{
	if(!flw||x==tt) return flw;
	int ans=0;
	while(hd[x]!=bi[x].end()){
		vector<int>::iterator it=hd[x];
		if(e[*it].z&&dis[e[*it].y]==dis[x]+1){
			int t=dfs(e[*it].y,tt,min(flw,e[*it].z));
			flw-=t;ans+=t;e[*it].z-=t;e[(*it)^1].z+=t;
			if(!flw) return ans;
		}
		hd[x]++;
	}
	dis[x]=-1;
	return ans;
}
int dinic(int s,int t)
{
	int ans=0;
	while(bfs(s,t)){
		int i;fz0g(i,t) hd[i]=bi[i].begin();
		ans+=dfs(s,t,0x3f3f3f3f);
	}return ans;
}
int n,m,i,j,a[1005];
void solve()
{
	read(n);read(m);
//	fz1(i,n) if(i&1) a[i]=1; else a[i]=m/2-1;
	fz1(i,n)read(a[i]);
	fz1(i,n)if(a[i]*2>=m){
		puts("-1");return;
	}
	int num=0;
	fz1(i,n)if(a[i]*3>m){
		add(s,i,1);num++;
		fz1(j,n)if(a[i]*2+a[j]<=m&&__gcd(a[i],a[j])==a[j]){
			add(i,j,1);
		}
	}
	fz1(i,n) if(a[i]*3<=m) add(i,t,1);
	if(dinic(s,t)<num){
		puts("-1");
		return;
	}
	vector<pair<int,int> > ans;
	fz1(i,tot){
		if(e[i+i-2].y!=t&&e[i+i-1].y!=s&&e[i+i-1].z){
			vis[e[i+i-2].y]=vis[e[i+i-1].y]=1;
			ans.push_back(make_pair(a[e[i+i-1].y]+a[e[i+i-1].y]+a[e[i+i-2].y],a[e[i+i-1].y]+a[e[i+i-2].y]));
		}
	}
	fz1(i,n)if(!vis[i]){
		assert(a[i]*3<=m);
		ans.push_back(make_pair(a[i]*3,a[i]*2));
	}
	printf("%d\n",(int)ans.size());
	ff(ans,it) printf("%d %d\n",it->first,it->second);
}
int main()
{
	solve();
	return 0;
}