// Problem: CF704D Captain America
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF704D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC target("avx,avx2")
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}

const int inf=2e9;
template<const int N,const int M>
class Flow{
	private:
	int head[N],ver[M],nxt[M],val[M],tot;
	void adde(int u,int v,int w){++tot;ver[tot]=v;nxt[tot]=head[u];val[tot]=w;head[u]=tot;}
	void add(int u,int v,int w){//printf("%d->%d %d\n",u,v,w);
		adde(u,v,w);adde(v,u,0);}
	int W[N],dis[N];
	bool bfs(int s,int t){
		//memcpy(cur,head,sizeof head);
		for(int i=1;i<=n;i++)dis[i]=inf;dis[s]=1;
		queue<int>q;q.push(s);
		while(q.size()){
			int u=q.front();q.pop();
			for(int i=head[u];i;i=nxt[i])if(val[i]&&dis[ver[i]]==inf){
				int v=ver[i];
				dis[v]=dis[u]+1;
				q.push(v);
				if(v==t)return true;
			}
		}return false;
	}
	int dfs(int s,int t,int u,int flow){
		if(u==t)return flow;
		int rest=flow;
		for(int i=head[u];i&&rest;i=nxt[i]){
			int v=ver[i];
			if(dis[v]==dis[u]+1&&val[i]){
				int tmp=dfs(s,t,v,min(rest,val[i]));
				rest-=tmp,val[i]-=tmp,val[i^1]+=tmp;
				if(!tmp)dis[v]=0;
			}
		}
		//if(rest==0)dis[u]=-1;
		return flow-rest;
	}
	int dinic(int s,int t){
		int ans=0;
		while(bfs(s,t))while(int sth=dfs(s,t,s,inf))
			ans+=sth;
		return ans;
	}
	int n;
	public:
	int calc(int s,int t,int num,vector<tuple<int,int,int,int>>E){
		n=num;
		tot=1;memset(W,0,sizeof W);
		for(auto [u,v,low,up]:E){
			//printf("%d->%d [%d,%d]\n",u,v,low,up);
			W[u]-=low;W[v]+=low;
			add(u,v,up-low);
		}
		add(t,s,inf);
		int _s=++n,_t=++n,sum=0;
		for(int i=1;i<=n;i++)
			if(W[i]>0)add(_s,i,W[i]),sum+=W[i];
			else add(i,_t,-W[i]);
		if(dinic(_s,_t)!=sum)return -1;
		return dinic(s,t);
	}
	map<pair<int,int>,int>chk(){//0
		map<pair<int,int>,int>mp;
		for(int u=1;u<=n;u++){
			for(int i=head[u];i;i=nxt[i]){
				int v=ver[i];
				if(!val[i])mp[{u,v}]++;
			}
		}return mp;
	}
};
Flow<210000,1410000>G;
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
const int N=1e5+10;
int n,m;int cnt;
int r,b;bool flag;
map<int,tuple<int,int,int,int>>X,Y;
//<id,,,>
int x_[N],y_[N];
signed main(){
	read(n,m);
	read(r,b);if(r>b)swap(r,b),flag=1;
	vector<tuple<int,int,int,int>>E;
	for(int i=1;i<=n;i++){
		int x,y;read(x,y);x_[i]=x,y_[i]=y;
		if(X.find(x)==X.end())
			X[x]={++cnt,0,0,inf};
		if(Y.find(y)==Y.end())
			Y[y]={++cnt,0,0,inf};
		get<1>(X[x])++;get<1>(Y[y])++;
		E.push_back({get<0>(X[x]),get<0>(Y[y]),0,1});
	}
	for(int i=1;i<=m;i++){
		int op,l,d;
		read(op,l,d);
		if(op==1){
			if(X.find(l)==X.end())continue;
			int c=get<1>(X[l]);
			d=min(d,c);
			int L=c-d+1>>1,R=c+d>>1;
			chkmx(get<2>(X[l]),L);
			chkmn(get<3>(X[l]),R);
		}else{
			if(Y.find(l)==Y.end())continue;
			int c=get<1>(Y[l]);
			d=min(d,c);
			int L=c-d+1>>1,R=c+d>>1;
			chkmx(get<2>(Y[l]),L);
			chkmn(get<3>(Y[l]),R);
		}
	}
	int s=++cnt,t=++cnt;
	for(auto [x,AA]:X){
		auto [id,c,l,r]=AA;
		if(l>r)return puts("-1"),0;
		E.push_back({s,id,l,r});
	}
	for(auto [y,AA]:Y){
		auto [id,c,l,r]=AA;
		if(l>r)return puts("-1"),0;
		E.push_back({id,t,l,r});
	}
	int ans=G.calc(s,t,cnt,E);
	if(ans==-1)return puts("-1"),0;
	write(1ll*ans*r+1ll*(n-ans)*b);putchar('\n');
	auto _=G.chk();
	for(int i=1;i<=n;i++){
		int x=get<0>(X[x_[i]]),y=get<0>(Y[y_[i]]);
		if(_[{x,y}])putchar("rb"[flag]),_[{x,y}]--;
		else putchar("br"[flag]);
	}
}