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
vector<pii> e[N];
int lea[N],add[N],n,a,b,c,rt;
vi A,B,C;

void push(int a,int b,int c){
	if(a!=b&&c){
		A.pb(a),B.pb(b),C.pb(c);
	}
}

void pre(int u,int fa){
	lea[u]=u;
	for(auto v:e[u])
		if(v.fi!=fa){
			pre(v.fi,u);
			lea[u]=lea[v.fi];
		}
}

void dfs(int u,int fa){
	if(e[u].size()==2&&fa){
		pii x=e[u].front();
		pii y=e[u].back();
		if(y.fi==fa)swap(x,y);
		if(x.se!=y.se){
			puts("NO");
			exit(0);
		}
		dfs(y.fi,u);
		return;
	}
	int x=0,y=0;
	for(auto v:e[u])
		if(v.fi!=fa){
			if(!x)x=lea[v.fi];
			y=lea[v.fi];
		}
	for(auto v:e[u])
		if(v.fi!=fa){
			int X=lea[v.fi];
			int Y=(x==X?y:x);
			int need=v.se-add[X];
			push(rt,X,need);
			push(X,Y,need);
			push(Y,rt,-need);
			add[X]+=need;
			dfs(v.fi,u);
		}
}

int main(){
	read(n);
	rep(i,1,n-1){
		read(a),read(b),read(c),c/=2;
		e[a].pb(mp(b,c));
		e[b].pb(mp(a,c));
	}
	if(n==2){
		printf("YES\n1\n%d %d %d\n",a,b,c*2);
		return 0;
	}
	rep(i,1,n)
		if(e[i].size()==1)rt=i;
	pre(rt,0);
	push(rt,lea[rt],e[rt].back().se*2);
	add[lea[rt]]+=e[rt].back().se;
	dfs(e[rt].back().fi,rt);
	puts("YES");
	printf("%d\n",(int)A.size());
	REP(i,A.size())
		printf("%d %d %d\n",A[i],B[i],C[i]);

	return 0;
}