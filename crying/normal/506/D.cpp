#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
int n,m,q,lim; 
int u[MAXN],v[MAXN],w[MAXN],x[MAXN],y[MAXN];
set<int>S[MAXN];
set<int>query[MAXN];
map<int,int>num[MAXN];
vector<int>V[MAXN],fa[MAXN];
map<pi,int>ans;
int Find(int x,int y){
	if(fa[x][y]==y)return y;
	return fa[x][y]=Find(x,fa[x][y]);
} 
void Merge(int x,int a,int b){
	if(Find(x,a)==Find(x,b))return;
	fa[x][Find(x,a)]=Find(x,b);
}
void pre(){
	lim=sqrt(2*m)+1;
//	lim=0;
	rep(i,1,m){
		auto tmp=S[i];
		int cnt=0;
		while(tmp.size()){
			int u=*tmp.begin();tmp.erase(u);
			V[i].pb(u);
			fa[i].pb(cnt);
			num[u][i]=cnt;
			cnt++;
		}
	}
	rep(i,1,m){Merge(w[i],num[u[i]][w[i]],num[v[i]][w[i]]);}
	//<= lim
	rep(i,1,m){
		int sz=V[i].size();if(sz>lim)continue;
		rep(j,0,sz-1){
			rep(k,j+1,sz-1){
				int u=V[i][j],v=V[i][k];
				if(Find(i,num[u][i])==Find(i,num[v][i]))ans[mp(u,v)]++;
			}
		}
	}
	//> lim
	rep(i,1,m){
		int sz=V[i].size();if(sz<=lim)continue;
		//printf("color %d\n",i);
		rep(j,0,sz-1){
			int u=V[i][j];
			//printf("u:%d\n",u);
			for(auto v:query[u]){
				if(S[i].find(v)==S[i].end())continue;
			//	printf("v:%d\n",v);
				if(Find(i,num[u][i])==Find(i,num[v][i]))ans[mp(u,v)]++;
			}
		}
	} 
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		S[w[i]].is(u[i]);S[w[i]].is(v[i]);
	}
	scanf("%d",&q);
	rep(i,1,q){
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]>y[i])swap(x[i],y[i]);
		query[x[i]].is(y[i]);
	}
	pre(); // 
	rep(i,1,q){
		printf("%d\n",ans[mp(x[i],y[i])]);
	}
	return 0;
}