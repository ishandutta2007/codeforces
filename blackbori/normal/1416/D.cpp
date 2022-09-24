#include <bits/stdc++.h>

using namespace std;
using pii = pair <int, int>;

struct segtree{
	pii T[606060];
	int sz = 1 << 18;

	void update(int i, int x)
	{
		i += sz; T[i] = pii(x, i - sz);
		for(i >>= 1; i; i >>= 1){
			T[i] = max(T[i << 1], T[i << 1 | 1]);
		}
	}

	int query(int l, int r)
	{
		pii ret(-1, 0);

		l += sz; r += sz;
		for(; l <= r; ){
			if(l & 1) ret = max(ret, T[l]);
			if(~r & 1) ret = max(ret, T[r]);
			l = l + 1 >> 1; r = r - 1 >> 1;
		}

		update(ret.second, 0);

		return ret.first;
	}
} S;

vector <pii> T[404040];
int A[202020], U[303030], V[303030];
int P[404040], L[404040], R[404040];
int Q1[505050], Q2[505050];
bool C[303030], chk[404040];
int D[22][404040], X[404040];
int n, m, q, k, cnt;

int find(int u) { return u == P[u]? u : P[u] = find(P[u]); }

void dfs(int u)
{
	L[u] = cnt + 1;
	if(u <= n) cnt ++;
	for(auto &[v, x]: T[u]){
		if(!L[v]){
			D[0][v] = u; X[v] = x;
			dfs(v);
		}
	}
	R[u] = cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, i, j, u, v;

	cin >> n >> m >> q;

	iota(P, P + n + n + 10, 0);

	for(i = 1; i <= n; i ++){
		cin >> A[i];
	}

	for(i = 1; i <= m; i ++){
		cin >> U[i] >> V[i];
	}

	for(i = 1; i <= q; i ++){
		cin >> Q1[i] >> Q2[i];
		if(Q1[i] == 2) C[Q2[i]] = 1;
	}

	k = n;
	for(i = 1; i <= m; i ++){
		if(!C[i]){
			u = find(U[i]); v = find(V[i]);
			if(u != v){
				k ++;
				T[k].emplace_back(u, q + 1);
				T[k].emplace_back(v, q + 1);
				P[u] = P[v] = k;
			}
		}
	}

	for(i = q; i >= 1; i --){
		if(Q1[i] == 1) continue;
		t = Q2[i];
		u = find(U[t]); v = find(V[t]);
		if(u != v){
			k ++;
			T[k].emplace_back(u, i);
			T[k].emplace_back(v, i);
			P[u] = P[v] = k;
		}
	}

	for(i = k; i >= 1; i --){
		if(!L[i]) dfs(i);
	}

	for(i = 1; i <= 18; i ++){
		for(j = 1; j <= k; j ++){
			D[i][j] = D[i - 1][D[i - 1][j]];
		}
	}

	for(i = 1; i <= n; i ++){
		S.update(L[i], A[i]);
	}

	for(i = 1; i <= q; i ++){
		if(Q1[i] == 2) continue;
		t = Q2[i];
		if(X[t] >= i){
			for(j = 18; j >= 0; j --){
				if(X[D[j][t]] >= i) t = D[j][t];
			}
			for(; X[t] >= i; ) t = D[0][t];
		}
		cout << S.query(L[t], R[t]) << "\n";
	}

	return 0;
}