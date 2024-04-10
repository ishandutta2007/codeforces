#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

const int K = (1 << 18) - 1;

int n;
int a[K + 5];
LL ans = 0;
int ile[K + 5];

int p[K + 5];		

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

int unia(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return 0;
	int sz = (p[x] == -1 ? ile[x] : 1) + (p[y] == -1 ? ile[y] : 1) - 1;
	p[x] += p[y];
	p[y] = x;
	return sz;
}	

int main() {	
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", a + i);
		ile[a[i]]++;
		ans -= a[i];
	}
	ile[0]++;
	
	rep(i, 0, (1 << 18)) p[i] = -1;
	
	per(i, 0, (1 << 18) - 1) {
		for (int j = i;; j = ((j - 1) & i)) {
			if (ile[j] && ile[i ^ j] && (j >= (i ^ j)))
				ans += (LL) i * unia(j, (i ^ j));
			if (!j) break;
		}
	}
	printf ("%lld", ans);
	
	return 0;
}