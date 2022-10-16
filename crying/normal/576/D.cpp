#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
const int MAXN=160,INF=1.5e9;
int n,m,ans=INF;
int dis[MAXN],vis[MAXN];
struct Edge{
	int u,v,w,tag;
	bool operator<(const Edge& e2)const{return w<e2.w;} 
}edge[MAXN];
int first[MAXN],next[MAXN],tot;
struct Matrix{
	bitset<MAXN>val[MAXN];
	int n,m;
	void reset(int n,int m){
		this->n=n;this->m=m;
	}
	Matrix power(int n){
		if(n==1)return (*this);
		Matrix tmp=power(n/2);tmp=tmp*tmp;
		if(n&1)tmp=tmp*(*this);return tmp;
	}
	void operator=(const Matrix& m2){
		reset(m2.n,m2.m);
		rep(i,1,n)rep(j,1,m)val[i][j]=m2.val[i][j];
	}
	Matrix operator*(const Matrix& m2)const{
		Matrix ret;ret.reset(n,m2.m);rep(i,1,ret.n)rep(j,1,ret.m)ret.val[i][j]=0;
		rep(i,1,ret.n){
			rep(j,1,ret.m){
				if(val[i][j])ret.val[i]|=m2.val[j];
			}
		}
		return ret;
	}
}f,A;
queue<int>q;
void bfs(){
	while(q.size()){
		int u=q.front();q.pop();
		for(int j=first[u];j;j=next[j]){
			if(edge[j].tag==0)continue;
			int v=edge[j].v;if(vis[v])continue;
			vis[v]=1;dis[v]=dis[u]+1;
			q.push(v);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);}
	sort(edge+1,edge+1+m);
	rep(i,1,m){next[++tot]=first[edge[i].u];first[edge[i].u]=tot;}
	f.reset(1,n);A.reset(n,n);f.val[1][1]=1;
	rep(i,1,m){
		int d=edge[i].w-edge[i-1].w;
		if(d)f=f*A.power(d);
		edge[i].tag=1;
		A.val[edge[i].u][edge[i].v]=1;
		rep(j,1,n){vis[j]=0;dis[j]=INF;}	
		while(q.size())q.pop();
		rep(j,1,n){
			if(f.val[1][j]==1){
				q.push(j);
				vis[j]=1;dis[j]=0;
			}
		}
		bfs();
		if(dis[n]!=INF)ans=Min(ans,edge[i].w+dis[n]);
	}
	if(ans==INF)return printf("Impossible\n"),0;
	printf("%d\n",ans);
	return 0;
}