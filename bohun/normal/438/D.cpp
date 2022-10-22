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

const int nax = 1e5 + 11, pod = (1 << 17);

ll sum[2 * pod];
int maks[2 * pod];

void akt(int u) {
	maks[u] = max(maks[2 * u], maks[2 * u + 1]);
	sum[u] = sum[2 * u] + sum[2 * u + 1];
}

void mod(int x, int y, int c, int u = 1, int l = 0, int r = pod - 1) {
	if(maks[u] < c)
		return;
	if(l == r) {
		maks[u] %= c;
		sum[u] = maks[u];
		return;
	}
	int m = (l + r) / 2;
	if(x <= m)
		mod(x, y, c, 2 * u, l, m);
	if(m < y)
		mod(x, y, c, 2 * u + 1, m + 1, r);
	akt(u);
}

void ustaw(int x, int c, int u = 1, int l = 0, int r = pod - 1) {
	if(l == r) {
		maks[u] = sum[u] = c;
		return;
	}
	int m = (l + r) / 2;
	if(x <= m)
		ustaw(x, c, 2 * u, l, m);
	else
		ustaw(x, c, 2 * u + 1, m + 1, r);
	akt(u);
}

ll query(int x, int y, int u = 1, int l = 0, int r = pod - 1) {
	if(x <= l && r <= y)
		return sum[u];
	int m = (l + r) / 2;
	ll ans = 0;
	if(x <= m)
		ans += query(x, y, 2 * u, l, m);
	if(m < y)
		ans += query(x, y, 2 * u + 1, m + 1, r);
	return ans;
}

int n, m;
int type, a, b, c;

int main() {	
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) {
		scanf("%d", &a);
		maks[i + pod] = a;
		sum[i + pod] = a;
	}
	for(int i = pod - 1; 1 <= i; --i)
		akt(i);
	while(m--) {
		scanf("%d%d%d", &type, &a, &b);
		if(type == 1) 
			printf("%lld\n", query(a, b));
		if(type == 2) {
			scanf("%d", &c);
			mod(a, b, c);
		}
		if(type == 3) {
			ustaw(a, b);
		}
	}
		
	
	
	
	
	return 0;
}