#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
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
typedef vector<db> Vd;
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

const int MAXN = 1428;
struct edg{ int pos, cap, rev, cost; };
vector<edg> gph[MAXN];
void clear(){ for(int i=0; i<MAXN; i++) gph[i].clear(); }
void add_edge(int s, int e, int x, int c){
	gph[s].push_back({e, x, (int)gph[e].size(), c});
	gph[e].push_back({s, 0, (int)gph[s].size()-1, -c});
}
int phi[MAXN], inque[MAXN], dist[MAXN];
void prep(int src, int sink){
	memset(phi, 0x3f, sizeof(phi));
	memset(dist, 0x3f, sizeof(dist));
	queue<int> que;
	que.push(src);
	inque[src] = 1;
	while(!que.empty()){
		int x = que.front();
		que.pop();
		inque[x] = 0;
		for(auto &i : gph[x]){
			if(i.cap > 0 && phi[i.pos] > phi[x] + i.cost){
				phi[i.pos] = phi[x] + i.cost;
				if(!inque[i.pos]){
					inque[i.pos] = 1;
					que.push(i.pos);
				}
			}
		}
	}
	for(int i=0; i<MAXN; i++){
		for(auto &j : gph[i]){
			if(j.cap > 0) j.cost += phi[i] - phi[j.pos];
		}
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push(pair<int,int>(0, src));
	dist[src] = 0;
	while(!pq.empty()){
		auto l = pq.top();
		pq.pop();
		if(dist[l.second] != l.first) continue;
		for(auto &i : gph[l.second]){
			if(i.cap > 0 && dist[i.pos] > l.first + i.cost){
				dist[i.pos] = l.first + i.cost;
				pq.push(pair<int,int>(dist[i.pos], i.pos));
			}
		}
	}
}
bool vis[MAXN];
int ptr[MAXN];
int dfs(int pos, int sink, int flow){
	vis[pos] = 1;
	if(pos == sink) return flow;
	for(; ptr[pos] < gph[pos].size(); ptr[pos]++){
		auto &i = gph[pos][ptr[pos]];
		if(!vis[i.pos] && dist[i.pos] == i.cost + dist[pos] && i.cap > 0){
			int ret = dfs(i.pos, sink, min(i.cap, flow));
			if(ret != 0){
				i.cap -= ret;
				gph[i.pos][i.rev].cap += ret;
				return ret;
			}
		}
	}
	return 0;
}
int match(int src, int sink, int sz){
	prep(src, sink);
	for(int i=0; i<sz; i++) dist[i] += phi[sink] - phi[src];
	int ret = 0;
	while(true){
		memset(ptr, 0, sizeof(ptr));
		memset(vis, 0, sizeof(vis));
		int tmp = 0;
		while((tmp = dfs(src, sink, 1e9))){
			ret += dist[sink] * tmp;
			memset(vis, 0, sizeof(vis));
		}
		tmp = 1e9;
		for(int i=0; i<sz; i++){
			if(!vis[i]) continue;
			for(auto &j : gph[i]){
				if(j.cap > 0 && !vis[j.pos]){
					tmp = min(tmp, (dist[i] + j.cost) - dist[j.pos]);
				}
			}
		}
		if(tmp > 1e9 - 200) break;
		for(int i=0; i<sz; i++){
			if(!vis[i]) dist[i] += tmp;
		}
	}
	return ret;
}
char s[105];
int a[100],cnt[26];
int cc=27;
int main(){
	int n;
	scanf("%d%s",&n,s);
	fup(i,0,n-1,1)scanf("%d",a+i);
	fup(i,0,n-1,1)cnt[s[i]-'a']++;
	fup(i,0,25,1){
		add_edge(0,i+1,cnt[i],0);
		fup(j,0,n/2-1,1){
			add_edge(i+1,cc,1,0);
			add_edge(cc,1327+j,1,s[j]==('a'+i)?-a[j]:0);
			add_edge(cc,1327+n-1-j,1,s[n-1-j]==('a'+i)?-a[n-1-j]:0);
			cc++;
		}
	}
	fup(i,0,n-1,1)add_edge(1327+i,1427,1,0);
	printf("%d\n",-match(0,MAXN-1,MAXN));
}