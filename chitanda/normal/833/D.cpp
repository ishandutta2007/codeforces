#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 100100, B = 100002;
struct edge{
	int v, w, c;
	edge() {}
	edge(int v, int w, int c) : v(v), w(w), c(c) {}
};
int root, tot_size;
int size[maxn];
bool done[maxn];
vector<edge>g[maxn];
int n, ans = 1, anss = 1;
int tag[2][maxn * 2], idx;
pair<int, int> c[2][maxn * 2];

vector<int> v1, v2;
vector<int> s1, s2;
void getroot(int t, int fa){
	size[t] = 1;
	int tmax = 0;
	for(auto e : g[t]){
		int v = e.v;
		if(v != fa && !done[v]){
			getroot(v, t);
			size[t] += size[v];
			tmax = max(tmax, size[v]);
		}
	}
	tmax = max(tmax, tot_size - size[t]);
	if(tmax <= tot_size / 2) root = t;
}

inline int pow(int a, int b){
	int res = 1;
	for(; b; b >>= 1, a = (ll)a * a % M)
		if(b & 1) res = (ll)res * a % M;
	return res;
}

pair<int, int> ask(int x, int k){
	if(x < 0) return mkp(0, 1);
	int res1 = 0, res2 = 1;
	for(; x; x -= x & -x) 
		if(tag[k][x] == idx) res1 += c[k][x].fi, res2 = (ll)res2 * c[k][x].se % M;
	return mkp(res1, res2);
}

void add(int x, int k, int v){
	for(; x <= 2 * n; x += x & -x)
		if(tag[k][x] == idx) ++c[k][x].fi, c[k][x].se = (ll)c[k][x].se * v % M;
		else tag[k][x] = idx, c[k][x].fi = 1, c[k][x].se = v;
}

void dfs(int t, int fa, int val, int a, int b){
	int v1 = 2 * a - b, v2 = 2 * b - a;
	auto t1 = ask(n - v1 - 1, 0), t2 = ask(n - v2 - 1, 1);
	ans = (ll)ans * t1.se % M * pow(val, t1.fi) % M;
	ans = (ll)ans * t2.se % M * pow(val, t2.fi) % M;
	for(auto e : g[t]){
		int v = e.v, w = e.w, c = e.c;
		if(done[v] || v == fa) continue;
		if(c)	dfs(v, t, (ll)val * w % M, a + 1, b);
		else dfs(v, t, (ll)val * w % M, a, b + 1);
	}
}

void dfs2(int t, int fa, int val, int a, int b){
	int v1 = 2 * a - b, v2 = 2 * b - a;
	add(v1 + n, 0, val);
	add(v2 + n, 1, val);
	for(auto e : g[t]){
		int v = e.v, w = e.w, c = e.c;
		if(done[v] || v == fa) continue;
		if(c)	dfs2(v, t, (ll)val * w % M, a + 1, b);
		else dfs2(v, t, (ll)val * w % M, a, b + 1);
	}
}

void work(int now){
	idx++;
	add(n, 0, 1); add(n, 1, 1);
	for(auto e : g[now]){
		int v = e.v, w = e.w, c = e.c;
		if(done[v]) continue;
		if(c) dfs(v, now, w, 1, 0), dfs2(v, now, w, 1, 0);
		else dfs(v, now, w, 0, 1), dfs2(v, now, w, 0, 1);
	}

	getroot(root, 0); //get new size
	done[now] = 1;
	for(auto e : g[now]){
		int v = e.v;
		if(!done[v]){
			tot_size = size[v];
			getroot(v, 0);
			work(root);
		}
	}
}

void dfs(int t, int fa){
	size[t] = 1;
	for(auto e : g[t]){
		int v = e.v, w = e.w;
		if(v == fa) continue;
		dfs(v, t);
		size[t] += size[v];
		anss = (ll)anss * pow(w, int((ll)size[v] * (n - size[v]) % (M - 1))) % M;
	}
}

int main(){
	scanf("%d", &n);
	tot_size = n;
	for(int i = 1; i < n; ++i){
		static int u, v, w, c;
		scanf("%d%d%d%d", &u, &v, &w, &c);
		g[u].pb(edge(v, w, c));
		g[v].pb(edge(u, w, c));
	}
	getroot(1, 0);
	work(root);
	dfs(1, 0);
	anss = (ll)anss * pow(ans, M - 2) % M;
	printf("%d\n", anss);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}