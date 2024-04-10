#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef complex<double> Complex;
#define fi first
#define se second
#define pb push_back
#define ins insert
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
const int N = 200022;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int T = 1099999;
int cnt[T];
int siz[N], a[N], tim, tag[N], ban[N];
vector<int> adj[N];
LL tmp[N], ans[N];
char st[N];
void predfs(int v, int fa) {
	siz[v] = 1;
	for(int y : adj[v]) {
		if(y != fa) {
			predfs(y, v);
			siz[v] += siz[y];
		}
	}
}
void collect(int v, int msk, auto & vec) {
	vec.push_back(msk);
	for(int y : adj[v])
		if(!ban[y] && siz[y] < siz[v]) 
			collect(y, msk ^ a[y], vec);
}
void add(LL & v, LL delta) {
	if(tag[&v - tmp] != tim) {
		tag[&v - tmp] = tim;
		v = 0;
	}
	v += delta;
}
LL C = 0;
void compute(int v, int msk) {
	for(int y : adj[v]) {
		if(!ban[y] && siz[y] < siz[v]) {
			compute(y, msk ^ a[y]);
			add(tmp[v], tmp[y]);
		}
	}
	for(int j(0); j < LOG; j++) {
		add(tmp[v], cnt[msk ^ (1 << j)]);
		C += cnt[msk ^ (1 << j)];
	}
	add(tmp[v], cnt[msk]);
	C += cnt[msk];
	ans[v] += tmp[v];
}

void dvcq(int c) {
	int s = siz[c];
	if(s == 1) return;
	vector<vector<int> > v;

	for(;;) {
		bool f = true;
		for(int y : adj[c])
			if(!ban[y])
				if(siz[y] > s / 2) {
					siz[c] -= siz[y];
					siz[y] += siz[c];
					c = y;
					f = false;
				}
		if(f) break;
	}
	ban[c] = 1;
	v.clear();
	++tim;
	C = 0;
	for(int y : adj[c]) {
		if(!ban[y]) {
			v.push_back(vector<int>());
			collect(y, a[y], v.back());
		}
	}
	for(auto & vec : v) 
		for(int i : vec) 
			cnt[i ^ a[c]]++;
	int i = 0;
	cnt[a[c]]++;
	//printf("c = %d:\n", c);
	for(int y : adj[c]) {
		if(!ban[y]) {
			for(int j : v[i]) {
				cnt[j ^ a[c]]--;
				if(((j ^ a[c]) & -(j ^ a[c])) == (j ^ a[c])) C++;
			}
			compute(y, a[y]);
			for(int j : v[i]) cnt[j ^ a[c]]++;
			i++;
		}
	}
	cnt[a[c]]--;
	ans[c] += C / 2;
	for(auto & vec : v) 
		for(int i : vec) 
			cnt[i ^ a[c]]--;
	for(int y : adj[c]) {
		if(!ban[y]) {
			dvcq(y);
		}
	}
}
int main() {
	int n;
	n = getInt();
//n = 200000;
	for(int i(1); i < n; i++) {
		int x = getInt(), y = getInt();
//int x = rand() % i + 1, y = i + 1;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	scanf("%s", st);
//for(int i(0); i < n; i++) st[i] = 'a' + rand() % 20;
	for(int i(1); i <= n; i++) {
		a[i] = 1 << (st[i - 1] - 'a');
	}
	predfs(1, 0);
	dvcq(1);
	for(int i(1); i <= n; i++) {
		printf("%I64d%c", 1 + ans[i], i == n ? '\n' : ' ');
	}
}