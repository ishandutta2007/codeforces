#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[300005],vv[300005];
int p[300005],P[300005],ne[300005];
int ind[300005];
int S[300005],E[300005],cc;
int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
void merge(int x,int y){p[find(y)]=find(x);}
void dfs(int N){
	S[N]=++cc;
	for(int next:v[N]){
		if(find(N)!=find(next))vv[find(N)].pb(find(next));
		dfs(next);
	}
	E[N]=cc;
}
int vis[300005];
bool Cycle(int N) {
	if (vis[N]) {
		if (vis[N] == -1) {
			return 1;
		}
		return 0;
	}
	vis[N] = -1;
	for (int next : vv[N]) {
		if (Cycle(next)) {
			return 1;
		}
	}
	vis[N] = 1;
	return 0;
}

int tree[300005];
int n,k;
void upd(int i, int c){
	while (i <= n){
		tree[i] += c;
		i += (i&-i);
	}
}
int sum(int i){
	int c = 0;
	while (i > 0){
		c += tree[i];
		i -= (i&-i);
	}
	return c;
}
int main(){
	scanf("%d%d",&n,&k);
	iota(p,p+n+1,0);
	fup(i,1,n,1){
		scanf("%d",P+i);
		if(P[i])v[P[i]].pb(i);
	}
	fup(i,1,k,1){
		int x,y;
		scanf("%d%d",&x,&y);
		ne[x]=y;
		if(find(x)==find(y))return !printf("0\n");
		merge(x,y);
	}
	fup(i,1,n,1)if(P[i]==0)dfs(i);
	fup(i,1,n,1){
		if(find(i)!=i)continue;
		int now=i;
		while(now!=0){
			if(sum(E[now])-sum(S[now]-1))return !printf("0\n");
			upd(S[now],1);
			now=ne[now];
		}
		now=i;
		while(now!=0){
			upd(S[now],-1);
			now=ne[now];
		}
	}
	fup(i,1,n,1){
		COMPRESS(vv[i]);
		for(int j:vv[i])ind[j]++;
	}
	fup(i,1,n,1){
		if(!vis[find(i)] && Cycle(find(i)))return !printf("0\n");
	}
	queue<int> q;
	fup(i,1,n,1){
		if(find(i)!=i)continue;
		if(ind[i]==0)q.push(i);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int now=x;
		while(now!=0){
			printf("%d ",now);
			now=ne[now];
		}
		for(int next:vv[x]){
			ind[next]--;
			if(ind[next]==0){
				q.push(next);
			}
		}
	}
}