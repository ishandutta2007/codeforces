#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)	
	
		
using namespace std;

const int nax = 1e5 + 111;
const int mod = 1e9 + 7;
const int pod = (1 << 17);

int n;
int a[nax];

int maxi[2 * pod];
int d[2 * pod];

void add1(int u, int c) {
	u += pod;
	maxi[u] = c;
	u /= 2;
	while(u) {
		maxi[u] = max(maxi[2 * u], maxi[2 * u + 1]);
		u /= 2;
	}
}

int naj(int x, int y, int u = 1, int l = 0, int r = pod - 1) {
	if(x <= l && r <= y)
		return maxi[u];
	int m = (l + r) / 2;
	int w = 0;
	if(x <= m)
		w = naj(x, y, 2 * u, l, m);
	if(m < y)
		w = max(w, naj(x, y, 2 * u + 1, m + 1, r));
	return w;
}

void add2(int x, int y, int c, int u = 1, int l = 0, int r = pod - 1) {
	if(x > y)
		return;
	if(x <= l && r <= y) {
		d[u] = min(d[u], c);
		return;
	}
	int m = (l + r) / 2;
	if(x <= m)
		add2(x, y, c, 2 * u, l, m);
	if(m < y)
		add2(x, y, c, 2 * u + 1, m + 1, r);
}
	
int query(int l, int r) {
	if(l > r)
		return 0;
	return naj(l, r);
}

int main() {		
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d", a + i);
		add1(i, a[i]);
	}
	FOR(i, 1, 2 * pod - 1)
		d[i] = mod;
	FOR(i, 1, n) {
		int L = 1;
		int R = i - 1;
		bool ok = 0;
		if(query(L, R) > a[i] * 2) {
			ok = 1;
			while(L < R) {
				int M = (L + R + 1) / 2;
				if(query(M, i - 1) > a[i] * 2)
					L = M;
				else
					R = M - 1;
			}
		//	cout << i << " " << L << endl;
			add2(1, L, i + 1);
			add2(L + 1, n, n + i + 1);
		}
		L = i + 1;
		R = n;
		if(ok == 0 && query(L, R) > a[i] * 2) {
			ok = 1;
			while(L < R) {
				int M = (L + R + 1) / 2;
				if(query(M, n) > a[i] * 2)
					L = M;
				else
					R = M - 1;
			}
			add2(1, i, n + i + 1);
			add2(i + 1, L, n + i + 1);
			add2(L + 1, n, 2 * n + 1 + i);
		}
	}
	
	FOR(i, 1, pod - 1) {
		d[2 * i] = min(d[2 * i], d[i]);
		d[2 * i + 1] = min(d[2 * i + 1], d[i]);
	}
	
	FOR(i, 1, n) {
		if(d[pod + i] == mod)
			printf("-1 ");
		else
			printf("%d ", d[pod + i] - i - 1);
	}
	
			
		
	
	
	
				
	return 0;
}