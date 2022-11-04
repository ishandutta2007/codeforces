#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e5 + 5;

int T, n, a[N], b[N];

#define pii pair<int, int>
#define fs first
#define se second

int c[N];

multiset<pii> s;

int f[N], l[N], r[N];

int F(int x) {
	return f[x] == x ? x : (f[x] = (F(f[x])));
}

void bin(int x, int y) {
	if(F(x) != F(y)) {
		x = f[x], y = f[y];
		l[y] = min(l[y], l[x]);
		r[y] = max(r[y], r[x]);
		f[x] = y;
	}
}


int main() {
	for(scanf("%d", &T); T; T --) {
		scanf("%d", &n);
		s.clear();
		fo(i, 1, n) {
			scanf("%d", &a[i]);
			b[a[i]] = i;
		}
		fo(i, 1, n + 1) {
			f[i] = l[i] = r[i] = i;
		}
		fo(i, 1, n) s.insert(pii(1, i)), c[i] = 1;
		int ans = 1;
		fo(i, 1, n) {
			int x = b[i];
			if(c[x] < (*--s.end()).fs) {
				ans = 0;
				break;
			}
			s.erase(pii(c[x], x));
			int y = r[F(x + 1)];
			if(y <= n) s.erase(pii(c[y], y));
			bin(x, y);
			c[y] += c[x];
			if(y <= n) s.insert(pii(c[y], y));
		}
		pp("%s\n", ans ? "Yes" : "No");
	}
}