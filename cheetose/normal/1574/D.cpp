#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321987654321
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int sz[10],n,m;
Vi v[10];
struct node {
	map<int,int>child;
};
vector<node> trie;
int init() {
	node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}
void add(int n, Vi &s, int i) {
	if (i == s.size()) return;
	int c = s[i];
	if (!trie[n].child.count(c)) {
		int next = init();
		trie[n].child[c] = next;
	}
	add(trie[n].child[c], s, i + 1);
}
ll ans;
int res[10],now[10];
void dfs(int node,int N,ll K){
	if(N==n)return;
	fdn(i,sz[N]-1,0,1){
		if(trie[node].child.count(i)){
			now[N]=i;
			dfs(trie[node].child[i],N+1,K+v[N][i]);
		}else{
			ll tmp=K+v[N][i];
			fup(j,N+1,n-1,1){
				tmp+=v[j].back();
			}
			if(tmp>ans){
				fup(j,0,N-1,1)res[j]=now[j];
				res[N]=i;
				fup(j,N+1,n-1,1)res[j]=v[j].size()-1;
				ans=tmp;
			}
			return;
		}
	}
}
int main(){
	init();
	scanf("%d",&n);
	fup(i,0,n-1,1){
		scanf("%d",sz+i);
		v[i].resize(sz[i]);
		for(int &x:v[i])scanf("%d",&x);
	}
	scanf("%d",&m);
	while(m--){
		Vi vv;
		fup(i,0,n-1,1){
			int x;
			scanf("%d",&x);
			--x;
			vv.pb(x);
		}
		add(0,vv,0);
	}
	dfs(0,0,0);
	fup(i,0,n-1,1)printf("%d ",res[i]+1);
}