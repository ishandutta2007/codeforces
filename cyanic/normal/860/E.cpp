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

const int N=500005;
int fa[N][20],p[N],d[N],stk[N];
ll val[N],f[N],res;
vi e[N],id[N];
int n,rt,top;

int lca(int a,int b){
	if(d[b]>d[a]) swap(a,b);
	per(j,19,0){
		if(d[fa[a][j]]>=d[b]){
			a=fa[a][j];
		}
	}
	if(a==b) return a;
	per(j,19,0){
		if(fa[a][j]!=fa[b][j]){
			a=fa[a][j];
			b=fa[b][j];
		}
	}
	return fa[a][0];
}
void dfs(int u){
	id[d[u]].pb(u);
	fa[u][0]=p[u];
	rep(j,1,19){
		fa[u][j]=fa[fa[u][j-1]][j-1];
	}
	for(auto v:e[u]){
		d[v]=d[u]+1;
		dfs(v);
	}
}
void doit(int u){
	if(top){
		int t=lca(stk[top],u);
		int sum=0;
		while(top&&d[stk[top]]>=d[t]){
			sum+=val[top];
			res-=val[top]*d[stk[top]];
			top--;
		}
		stk[++top]=t;
		val[top]=sum;
		res+=val[top]*d[stk[top]];
	}
	f[u]+=res;
	stk[++top]=u;
	val[top]=1;
	res+=val[top]*d[stk[top]];
}
void solve(int u){
	for(auto v:e[u]){
		f[v]+=d[u]+f[u];
		solve(v);
	}
}

int main(){
	read(n);
	rep(i,1,n){
		read(p[i]);
		if(p[i]) e[p[i]].pb(i);
		else rt=i;
	}
	d[rt]=1,dfs(rt);
	for(int i=1;id[i].size();i++){
		top=res=0;
		for(int k=0;k<id[i].size();k++) doit(id[i][k]);
		top=res=0;
		for(int k=(int)id[i].size()-1;~k;k--) doit(id[i][k]);
	}
	solve(rt);
	rep(i,1,n) printf("%lld ",f[i]);
	puts("");
	return 0;
}