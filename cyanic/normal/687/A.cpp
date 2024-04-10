#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define clr(x) memset(x,0,sizeof x)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=100005;
int col[N],n,m,u,v;
vi e[N],ans[2];

void dfs(int u,int c){
	col[u]=c,ans[c].pb(u);
	for(auto v:e[u]){
		if(col[v]==c){
			puts("-1");
			exit(0);
		}
		if(col[v]==-1){
			dfs(v,c^1);
		}
	}
}

int main(){
	read(n),read(m);
	rep(i,1,m){
		read(u),read(v);
		e[u].pb(v),e[v].pb(u);
	}
	memset(col,-1,sizeof col);
	rep(i,1,n){
		if(col[i]!=-1) continue;
		dfs(i,0);
	}
	REP(t,2){
		printf("%d\n",SZ(ans[t]));
		for(auto x:ans[t]){
			printf("%d ",x);
		}
		puts("");
	}
	return 0;
}