#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

vvi G;
vi P;
vi M;
vi C;
const int N = 100010;
const int L = 25;

int D[N][L];
int F[N];

void fes(int x, int f = 0, int p = -1) {
	F[x] = f;
	int k = 0;
	while (p != -1) {
		D[x][k] = p;
		p = D[p][k];
		++k;
	}
	for (int i = 0; i < (int)G[x].size(); ++i) {
		int y = G[x][i];
		fes(y, f + 1, x);
	} 
}

int lca(int x, int y) {
	if (F[x] < F[y]) swap(x, y);
	int l = L -1;
	while (F[x] > F[y]) {
		int x1 = D[x][l];
		--l;
		if (x1 == -1 or F[x1] < F[y]) continue;
		x = x1;
	}
	l = L;
	while (l--) {
		int x1 = D[x][l];
		int y1 = D[y][l];
		if (x1 != y1) {
			x = x1;
			y = y1;
		}
	}
	if (x != y) x = D[x][0];
	return x;
}

int mare(int x) {
	if (M[x] == -1) return x;
	return M[x] = mare(M[x]);
}

int pare(int x) {
	if (P[x] == -1) return x;
	return P[x] = pare(P[x]);
}

int care(int x) {
	if (C[x] == -1) return x;
	return C[x] = care(C[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	P = M = C = vi(n, -1);
	memset(D, -1, sizeof(D));
	G = vvi(n);
	memset(F, -1, sizeof(F));
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		if (a == -1 or b == -1) continue;
		--a;
		C[care(i)] = care(a);
		if (b == 0) {
			G[a].push_back(i);
			P[pare(i)] = pare(a);
		}
		else {
			G[a].push_back(i);
			M[mare(i)] = mare(a);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (F[i] == -1) fes(i);
	}
	int q;
	cin >> q;
	while (q--) {
		int t, a, b;
		cin >> t >> a >>b;
		--a; --b;
		if (a == b or care(a) != care(b)) cout << "NO\n";
		else if (t == 1) {
			int x = lca(a, b);
			if (pare(a) == pare(b) and x == a) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
		else {
			int x = lca(a, b);
			if (mare(a) == mare(b) and x == a) cout << "YES\n";
			else if (mare(b) == mare(x) and pare(a) == pare(x) and x != b) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}