#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 5e5 + 10;

int n, a[MAXN], q, seg[MAXN<<2];

void plant(int v, int b, int e) {
	if (e - b == 1) {
		seg[v] = a[b];
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	seg[v] = __gcd(seg[v<<1], seg[v<<1^1]);
}

void water(int v, int b, int e, int pos) {
	if (e - b == 1) {
		seg[v] = a[b];
		return;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		water(v<<1, b, mid, pos);
	else
		water(v<<1^1, mid, e, pos);
	seg[v] = __gcd(seg[v<<1], seg[v<<1^1]);
}

int get(int v, int b, int e, int l, int r, int cur = 0) {
	if (l <= b && e <= r)
		return __gcd(seg[v], cur);
	if (r <= b || e <= l)
		return cur;

	int mid = b + e >> 1;
	cur = get(v<<1^1, mid, e, l, r, cur);
	return get(v<<1, b, mid, l, r, cur);
}

int getPos(int v, int b, int e, int l, int x, int cur = 0) {
	if (e - b == 1) {
		if (__gcd(cur, a[b]) % x == 0)
			return e;
		return b;
	}

	int mid = b + e >> 1;
	if (l >= mid)
		return getPos(v<<1^1, mid, e, l, x, cur);
	int t = get(v<<1, b, mid, l, mid, cur);
	if (t % x == 0)
		return getPos(v<<1^1, mid, e, l, x, t);
	return getPos(v<<1, b, mid, l, x, cur);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	plant(1, 0, n);

	scanf("%d", &q);
	while (q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int l, r, x; scanf("%d %d %d", &l, &r, &x), l--;
			bool ok = false;

			int pos = getPos(1, 0, n, l, x);
			if (pos >= r)
				ok = true;
			else {
				int temp = a[pos];
				a[pos] = x;
				water(1, 0, n, pos);
				if (get(1, 0, n, l, r) == x)
					ok = true;
				a[pos] = temp;
				water(1, 0, n, pos);
			}
			if (ok)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else {
			int pos, x; scanf("%d %d", &pos, &x), pos--;
			a[pos] = x;
			water(1, 0, n, pos);
		}
	}
	return 0;
}