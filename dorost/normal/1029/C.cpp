/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

struct seg {
	int l, r;
};

seg to_seg(int l, int r) {
	seg x;
	x.l = l;
	x.r = r;
	return x;
}

void read(seg& seg1) {
	cin >> seg1.l >> seg1.r;
}

const int N = 301234;
seg a[N], pre[N], suf[N];

seg inter(seg seg1, seg seg2) {
	int f = max(seg1.l, seg2.l), s = min(seg1.r, seg2.r);
	if (s < f) {
		return to_seg(0, 0);
	}
	return to_seg(f, s);
}

int len(seg seg1) {
	return seg1.r - seg1.l;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		read(a[i]);
	pre[0] = a[0];
	suf[n - 1] = a[n - 1];
	for (int i = 1; i < n; i++) {
		pre[i] = inter(pre[i - 1], a[i]);
	}
	for (int i = n - 2; i >= 0; i--) {
		suf[i] = inter(suf[i + 1], a[i]);
	}
	int mx = max(len(pre[n - 2]), len(suf[1]));
	for (int i = 1; i < n - 1; i++) {
		mx = max(mx, len(inter(pre[i - 1], suf[i + 1])));
	}
	cout << mx;
}