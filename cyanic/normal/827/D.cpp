#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n):i++)
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

const int N=200005;
struct edge{
	int u,v,w,id;
	friend bool operator < (edge a,edge b){
		return a.w<b.w;
	}
}e[N];
int pa[N],fa[N],f[N][20],mx[N][20],d[N],ans[N],n,m;
map<pii,int> ID,W;
vi t[N];

int getpa(int x){
	return pa[x]==x?x:pa[x]=getpa(pa[x]);
}

void dfs(int u){
	f[u][0]=fa[u];
	mx[u][0]=W[mp(fa[u],u)];
	rep(j,1,19){
		f[u][j]=f[f[u][j-1]][j-1];
		mx[u][j]=max(mx[u][j-1],mx[f[u][j-1]][j-1]);
	}
	for(auto v:t[u]){
		if(v==fa[u]) continue;
		fa[v]=u,d[v]=d[u]+1;
		dfs(v);
	}
}

int main(){
	read(n),read(m);
	rep(i,1,m){
		read(e[i].u),read(e[i].v);
		read(e[i].w),e[i].id=i;
	}
	sort(e+1,e+m+1);
	rep(i,1,n) pa[i]=i;
	rep(i,1,m){
		int a=getpa(e[i].u);
		int b=getpa(e[i].v);
		if(a!=b){
			pa[a]=b;
			int x=e[i].u,y=e[i].v;
			t[x].pb(y),t[y].pb(x);
			ID[mp(x,y)]=e[i].id;
			ID[mp(y,x)]=e[i].id;
			W[mp(x,y)]=e[i].w;
			W[mp(y,x)]=e[i].w;
			ans[e[i].id]=-1;
			e[i].id=0;
		}
	}
	d[1]=1,dfs(1);
	rep(i,1,m){
		if(!e[i].id) continue;
		int x=e[i].u,y=e[i].v;
		if(d[y]>d[x]) swap(x,y);
		int res=0;
		per(j,19,0){
			if(d[f[x][j]]>=d[y]){
				res=max(res,mx[x][j]);
				x=f[x][j];
			}
		}
		per(j,19,0){
			if(f[x][j]!=f[y][j]){
				res=max(res,mx[x][j]);
				res=max(res,mx[y][j]);
				x=f[x][j],y=f[y][j];
			}
		}
		if(x!=y){
			res=max(res,mx[x][0]);
			res=max(res,mx[y][0]);
		}
//		printf("## %d %d %d %d\n",e[i].id,e[i].u,e[i].v,res);
		ans[e[i].id]=res-1;
	}
	rep(i,1,n) pa[i]=i;
	rep(i,1,m){
		if(!e[i].id) continue;
		int x=e[i].u,y=e[i].v;
		x=getpa(x),y=getpa(y);
		while(x!=y){
			if(d[y]>d[x]) swap(x,y);
			ans[ID[mp(x,fa[x])]]=e[i].w-1;
			pa[x]=getpa(fa[x]),x=getpa(x);
		}
	}
	rep(i,1,m) printf("%d ",ans[i]);
	puts("");
	return 0;
}