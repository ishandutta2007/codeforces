#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<bitset>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 10;
const int MAXM = 1e3 + 5;

int n, m, vec[MAXN];
int s_t[MAXN], f_t[MAXN], id[MAXN], tm;
int primes[MAXM], sz;
vector<int>	adj[MAXN];
bitset<MAXM> weed[4 * MAXN], zz, oo;
int nut[4 * MAXN];

void dfs(int v, int p = -1){
	id[tm] = v;
	s_t[v] = tm++;
	for (int u:adj[v])
		if (u != p)	dfs(u, v);
	f_t[v] = tm;
}

bool is_prime(int x){
	if (x < 2)	return	false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)	return	false;
	return	true;
}

void plant(int v = 1, int b = 0, int e = n){
	if (e - b == 1){
		weed[v][vec[id[b]]] = 1;
		return;
	}

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = weed[v<<1] | weed[v<<1^1];
}

void absorb(int v){
	nut[v] %= m;
	nut[v<<1] += nut[v];
	nut[v<<1^1] += nut[v];
	weed[v<<1] = ((weed[v<<1] << nut[v]) | (weed[v<<1] >> (m - nut[v]))) & oo;
	weed[v<<1^1] = ((weed[v<<1^1] << nut[v]) | (weed[v<<1^1] >> (m - nut[v]))) & oo;
	nut[v] = 0;
}

bitset<MAXM> smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	weed[v];
	if (r <= b || e <= l)	return	zz;

	int mid = (b + e)/ 2;
	absorb(v);
	return	smoke(v<<1, b, mid, l, r) | smoke(v<<1^1, mid, e, l, r);
}

void water(int v, int b, int e, int l, int r, int x){
	if (l <= b && e <= r){
		nut[v] += x;
		weed[v] = (weed[v] << x) | (weed[v] >> (m - x));
		weed[v] &= oo;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	absorb(v);
	water(v<<1, b, mid, l, r, x);
	water(v<<1^1, mid, e, l, r, x);
	weed[v] = weed[v<<1] | weed[v<<1^1];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	oo.flip();
	for (int i = m; i < MAXM; i++)	oo[i] = 0;
	for (int i = 0; i < n; i++)	cin >> vec[i], vec[i] %= m;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	for (int i = 1; i < m; i++)	
		if (is_prime(i))
			primes[sz++] = i;
	plant();
	
	int q;	cin >> q;
	while (q--){
		short type;	cin >> type;
		if (type == 2){
			int v, cnt = 0;	cin >> v;	v--;
			bitset<MAXM> bb = smoke(1, 0, n, s_t[v], f_t[v]);
			for (int i = 0; i < sz; i++)
				if (bb[primes[i]])	cnt++;
			cout << cnt << "\n";	
		}
		else{
			int v, x;	cin >> v >> x;	v--;	x %= m;
			water(1, 0, n, s_t[v], f_t[v], x);
		}
	}
	return	0;
}