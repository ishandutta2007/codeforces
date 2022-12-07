#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
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

VPi v[200001];
vector<Vi> SCC;
int num[200001], low[200001], sn[200001];
bool chk[200001];
ll len[200001],G[200001];
Vi st;
int cnt, SN;
void dfs(int n){
	chk[n] = 1;
	st.pb(n);
	num[n] = ++cnt;
	low[n] = cnt;
	for (auto [next,cost] : v[n]){
		if (num[next] == 0){
			dfs(next);
			low[n] = min(low[n], low[next]);
		}
		else if (chk[next])
			low[n] = min(low[n], num[next]);
	}
	if (num[n] == low[n]){
		Vi scc;
		while (!st.empty()){
			int x = st.back();
			st.pop_back();
			sn[x] = SN;
			chk[x] = 0;
			scc.push_back(x);
			if (n == x)
				break;
		}
		SCC.push_back(scc);
		SN++;
	}
}
void cal(int N){
	int r=SCC[N][0];
	queue<int> q;
	q.push(r);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto [y,cost]:v[x]){
			if(chk[y] || sn[x]!=sn[y])continue;
			len[y]+=len[x]+cost;
			q.push(y);
			chk[y]=1;
		}
	}
	for(int x:SCC[N]){
		for(auto [y,c]:v[x]){
			if(sn[x]==sn[y]){
				G[N]=gcd(G[N],len[x]+c-len[y]);
			}
		}
	}
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,m,1){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].pb({y,z});
	}
	fup(i,1,n,1)if(!num[i])dfs(i);
	fup(i,0,SN-1,1)cal(i);
	int q;
	scanf("%d",&q);
	while(q--){
		int x,s,t;
		scanf("%d%d%d",&x,&s,&t);
		x=sn[x];
		ll g=gcd(G[x],t);
		if(s%g==0)puts("YES");
		else puts("NO");
	}
}