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
const ll MAXN=1e4+10,INF=1e16;
int n,k,l,a[MAXN],s[MAXN],b[MAXN];
int pos[MAXN],tot;
queue<int>q;
ll dis[50][MAXN];
ll f[(1<<22)+10];
vector<int>e[MAXN];
void bfs(int s,ll* dis){
	rep(i,1,n+1)dis[i]=INF;
	dis[s]=0;q.push(s);
	while(q.size()){
		int u=q.front();q.pop();
		for(auto v:e[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;q.push(v);
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&l);
	rep(i,1,k){
		int tmp;scanf("%d",&tmp);
		a[tmp]=1;
	}
	rep(i,1,l)scanf("%d",&b[i]);
	rep(i,1,n+1)s[i]=a[i]^a[i-1];
	rep(i,1,n+1){
		if(s[i]){
			pos[++tot]=i;
		} 
	}
	rep(i,1,l){
		rep(j,1,n){
			if(j+b[i]<=n+1){
				e[j].pb(j+b[i]);
				e[j+b[i]].pb(j);
			}
		}
	}
	rep(i,1,tot){
		bfs(pos[i],dis[i]);
	}	
	f[0]=0;
	rep(i,1,(1<<tot)-1){
		ll& ret=f[i];ret=INF;
		rep(j,1,tot)rep(k,j+1,tot){
			if(!(i>>(j-1)&1))continue;
			if(!(i>>(k-1)&1))continue;
			ll val=dis[j][pos[k]];
			ret=Min(ret,val+f[i^(1<<(j-1))^(1<<(k-1))]);
		}
	}
	if(f[(1<<tot)-1]>=INF)printf("-1");
	else printf("%lld ",f[(1<<tot)-1]);
	return 0;
}