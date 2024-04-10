#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, m;
int from[MAXN], to[MAXN], w[MAXN], id[MAXN];
int s_t[MAXN], f_t[MAXN], sz;
vector<int> adj[MAXN];
int seg[MAXN<<2], d[MAXN];

bool cmp(int e1, int e2){return w[e1] < w[e2];}

void water(int v, int b, int e, int pos){
	if (e - b == 1){
		seg[v] = d[b];
		return;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		water(v<<1, b, mid, pos);
	else
		water(v<<1^1, mid, e, pos);
	seg[v] = max(seg[v<<1], seg[v<<1^1]);
}

int get(int v, int b, int e, int l, int r){
	if (l <= b && e <= r) return seg[v];
	if (r <= b || e <= l) return 0;

	int mid = b+e>>1;
	return max(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> from[i] >> to[i] >> w[i], from[i]--, to[i]--, adj[from[i]].push_back(i);
	for (int v = 0; v < n; v++)
		sort(adj[v].begin(), adj[v].end(), cmp);
	for (int v = 0; v < n; v++){
		s_t[v] = sz;
		for (int e:adj[v])
			id[e] = sz++;
		f_t[v] = sz;
	}
	int ans = 0;
	for (int e = m-1; ~e; e--){
		int v = to[e];
		int lo = 0, hi = (int)adj[v].size() + 1;
		while (hi-lo>1){
			int mid = hi+lo>>1;
			if (w[adj[v][mid-1]] <= w[e])
				lo = mid;
			else
				hi = mid;
		}
		d[id[e]] = 1 + get(1, 0, sz, s_t[v] + lo, f_t[v]);
	
		water(1, 0, sz, id[e]);
		ans = max(ans, d[id[e]]);
	}
	cout << ans << "\n";
	return 0;
}