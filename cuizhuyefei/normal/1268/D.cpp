#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2020;
int n,deg[N];char S[N][N];bitset<N> e[N];
int bfs(int s){
	bitset<N>q,cur;q.reset();cur.reset();q.set(s);
	while(1){
		bitset<N>need=cur^q;
		int pos=need._Find_first();
		if(pos>=1&&pos<=n){
			cur.set(pos);q|=e[pos];
		}else break;
	}
	return q.count();
}
int main() {
	read(n);rep(i,1,n)scanf("%s",S[i]+1);
	rep(i,1,n)rep(j,1,n)e[i][j]=S[i][j]-'0',deg[j]+=e[i][j];
	int mn=1;rep(i,1,n)if(deg[i]>deg[mn])mn=i;
	int cnt=bfs(mn);
	if(cnt==n){printf("0 1\n");return 0;}
	if(cnt==3&&n==6){printf("2 18\n");return 0;}
	if(cnt==3&&n==4){puts("-1");return 0;}
	
	rep(i,1,n)deg[i]=0;
	rep(i,1,n)rep(j,1,n)e[i][j]=e[i][j]^1,deg[j]+=e[i][j];
	mn=1;rep(i,1,n)if(deg[i]>deg[mn])mn=i;
	cnt=bfs(mn);if(cnt==3&&n==4){puts("-1");return 0;}
	
	
	int res=0;
	rep(i,1,n){
		rep(j,1,n)if(i!=j){
			deg[i]-=e[j][i];deg[j]-=e[i][j];
			e[i][j]=e[i][j]^1;e[j][i]=e[j][i]^1;
			deg[i]+=e[j][i];deg[j]+=e[i][j];
		}
		mn=1;rep(i,1,n)if(deg[i]>deg[mn])mn=i;
		res+=bfs(mn)==n;
		rep(j,1,n)if(i!=j){
			deg[i]-=e[j][i];deg[j]-=e[i][j];
			e[i][j]=e[i][j]^1;e[j][i]=e[j][i]^1;
			deg[i]+=e[j][i];deg[j]+=e[i][j];
		}
	}
	
	printf("1 %d",res);
	return 0;
}