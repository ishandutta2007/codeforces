#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

pair<int, int> p[200005];
int a[200005];

int mx[200005 << 2], mi[200005 << 2];
int add[200005 << 2];

void pushUp(int l, int r, int rt) {
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
	mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
	mx[rt] = 0;
	mi[rt] = 0;
	add[rt] = 0;
	if (l == r) {
	} else {
		int mid = (l + r) >> 1;
		build(l, mid, rt << 1);
		build(mid + 1, r, rt << 1 | 1);
	}
}

void pushDown(int l, int r, int rt) {
	if (add[rt]) {
		add[rt << 1] += add[rt];
		mx[rt << 1] += add[rt];
		mi[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		mx[rt << 1 | 1] += add[rt];
		mi[rt << 1 | 1] += add[rt];
		add[rt] = 0;
	}
}

void Add(int l, int r, int rt, int ql, int qr, int val) {
	if (ql <= l && r <= qr) {
		add[rt] += val;
		mx[rt] += val;
		mi[rt] += val;
	} else {
		int mid = (l + r) >> 1;
		pushDown(l, r, rt);
		if (ql <= mid) Add(l, mid, rt << 1, ql, qr, val);
		if (mid < qr) Add(mid + 1, r, rt << 1 | 1, ql, qr, val);
		pushUp(l, r, rt);
	}
}

int queryMax(int l, int r, int rt, int ql, int qr) {
	if (ql <= l && r <= qr) return mx[rt];
	else {
		pushDown(l, r, rt);
		int mid = (l + r) >> 1;
		int ret = -1e9;
		if (ql <= mid) ret = max(ret, queryMax(l, mid, rt << 1, ql, qr));
		if (mid < qr) ret = max(ret, queryMax(mid + 1, r, rt << 1 | 1, ql, qr));
		return ret;
	}
}


int queryMin(int l, int r, int rt, int ql, int qr) {
	if (ql <= l && r <= qr) return mi[rt];
	else {
		pushDown(l, r, rt);
		int mid = (l + r) >> 1;
		int ret = 1e9;
		if (ql <= mid) ret = min(ret, queryMin(l, mid, rt << 1, ql, qr));
		if (mid < qr) ret = min(ret, queryMin(mid + 1, r, rt << 1 | 1, ql, qr));
		return ret;
	}
}

int ans[200005];

int cal(int x) {
	if (x < 0) return -x - 1;
	else return x;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		p[i].second = i;
		scanf("%d", &p[i].first);
		a[i] = p[i].first;
	}
	sort(p + 1, p + 1 + n);
	build(1, n, 1);
	for (int i = 1;i <= n;i++) {
		Add(1, n, 1, i, i, i);
	}
	for (int i = 1;i <= n;i++) {
		int pos = p[i].second;
		int mxL = 0;
		int miL = 0;
		if (pos > 1) {
			mxL = max(mxL, queryMax(1, n, 1, 1, pos - 1));
			miL = min(miL, queryMin(1, n, 1, 1, pos - 1));
		}
		int miR = queryMin(1, n, 1, pos, n);
		int mxR = queryMax(1, n, 1, pos, n);
		int ret = max(cal(miR - mxL), cal(mxR - miL));
		ans[pos] = max(ans[pos], ret / 2);
		if (i == n || p[i].first != p[i + 1].first) {
			int j = i;
			while (j >= 1 && p[j].first == p[i].first) j--;
			for (int x = j + 1;x <= i;x++)
				Add(1, n, 1, p[x].second, n, -2);
			for (int x = j + 1;x <= i;x++) {
				pos = p[x].second;
				mxL = 0;
				miL = 0;
				if (pos > 1) {
					mxL = max(mxL, queryMax(1, n, 1, 1, pos - 1));
					miL = min(miL, queryMin(1, n, 1, 1, pos - 1));
				}
				miR = queryMin(1, n, 1, pos, n);
				mxR = queryMax(1, n, 1, pos, n);
				int ret1 = max(cal(miR - mxL), cal(mxR - miL));
				ans[pos] = max(ans[pos], ret1 / 2);
			}
		}
	}
	for (int i = 1;i <= n;i++) printf("%d ", ans[i]);
	puts("");
	return 0;
}