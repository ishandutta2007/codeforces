#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1005;
int sz[N],n,a,b,rt,best=N,now,delta;
vector<pii> sn;
vi e[N];

void dfs(int u,int fa){
	int now=0;
	sz[u]=1;
	for(auto v:e[u])
		if(v!=fa){
			dfs(v,u);
			sz[u]+=sz[v];
			now=max(now,sz[v]);
		}
	now=max(now,n-sz[u]);
	if(now<best){
		best=now;
		rt=u;
	}
}

void sdf(int u,int fa){
	sz[u]=1;
	for(auto v:e[u])
		if(v!=fa){
			sdf(v,u);
			sz[u]+=sz[v];
		}
	if(fa==rt)sn.pb(mp(u,sz[u]));
}

void print(int u,int fa,int las=0){
	printf("%d %d %d\n",fa,u,(now+=delta)-las);
	int f=now;
	for(auto v:e[u])
		if(v!=fa)print(v,u,f);
}

int main(){
	read(n);
	rep(i,1,n-1){
		read(a),read(b);
		e[a].pb(b),e[b].pb(a);
	}
	dfs(1,0);
	sdf(rt,0);
	int sum=0,p=-1,best=0,S=0;
	sort(sn.begin(),sn.end(),[&](pii a,pii b){
		return a.se<b.se;
	});
	REP(i,sn.size()){
		sum+=sn[i].se;
		if((sum+1)*(n-sum)>best){
			p=i;
			best=(sum+1)*(n-sum);
			S=sum;
		}
	}
	delta=1,now=0;
	rep(i,0,p)
		print(sn[i].fi,rt);
	delta=S+1,now=0;
	for(int i=p+1;i<sn.size();i++)
		print(sn[i].fi,rt);
	return 0;
}