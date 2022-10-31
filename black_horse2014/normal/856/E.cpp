#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
using namespace std;
typedef long long LL;
#define FI(x) read(x)

const int SIZE = 1<<12;
char buf[SIZE], str[60];

int bi = SIZE, bn = SIZE;
int read(char *s) {
	while (bn) {
		for (; bi < bn && buf[bi] <= ' '; bi++);
		if (bi < bn) break;
		bn = fread(buf, 1, SIZE, stdin);
		bi = 0;
	}
	int sn = 0;
	while (bn) {
		for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
		if (bi < bn) break;
		bn = fread(buf, 1, SIZE, stdin);
		bi = 0;
	}
	s[sn] = 0;
	return sn;
}

bool read(int& x) {
	int n = read(str), bf = 0;
	if (!n) return 0;
	int i = 0; if (str[i] == '-') bf = 1, i++; else if (str[i] == '+') i++;
	for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
	if (bf) x = -x;
	return 1;
}

struct FR {
	int a, b;
	
	FR() {}
	FR(int x, int y) {
		int g = __gcd(x, y);
		x /= g, y /= g;
		if (y < 0) x = -x, y = -y;
		a = x, b = y;
	}
};

bool operator<(const FR& f1, const FR& f2) {
	return 1LL * f1.a * f2.b < 1LL * f2.a * f1.b;
}

bool operator==(const FR& f1, const FR& f2) {
	return f1.a == f2.a && f1.b == f2.b;
}

const int N = 500000+10;
int r, x[N], y[N];
FR ha[N], hb[N], ang1[N], ang2[N];
int t[N], a[N], b[N], ida[N], idb[N];

vector<int> VEC[N], vec[N];

void Add(int x, int y) {
	for (++x; x < N; x += x & -x) VEC[x].push_back(y);
}

void add(int x, int y, int val) {
	for (++x; x < N; x += x & -x) {
		int p = lower_bound(VEC[x].begin(), VEC[x].end(), y) - VEC[x].begin() + 1;
		for (; p < vec[x].size(); p += p & -p) {
			vec[x][p] += val;
		} 
	}
}

int get(int x, int y) {
	int ret = 0;
	for (++x; x; x -= x & -x) {
		int p = upper_bound(VEC[x].begin(), VEC[x].end(), y) - VEC[x].begin();
		for (; p; p -= p & -p) {
			ret += vec[x][p];
		}
	}
	return ret;
}

int main() {
	int n; FI(r), FI(n);
	int now = 1;
	for (int i = 0; i < n; i ++) {
		FI(t[i]);
		if (t[i] == 1) {
			FI(x[now]), FI(y[now]);
			++now;
		}
		if (t[i] == 2) {
			FI(a[i]);
		}
		if (t[i] == 3) {
			FI(a[i]), FI(b[i]);
		}
	}
	int han = 0, hbn = 0;
	for (int i = 1; i < now; i ++) {
		ang1[i] = FR(x[i] + r, y[i]);
		ang2[i] = FR(x[i] - r, y[i]);
		ha[han++] = ang1[i];
		hb[hbn++] = ang2[i];
	}

	sort(ha, ha + han);
	han = unique(ha, ha + han) - ha;

	sort(hb, hb + hbn);
	hbn = unique(hb, hb + hbn) - hb;

	for (int i = 1; i < now; i ++) {
		ida[i] = han - 1 - (lower_bound(ha, ha + han, ang1[i]) - ha);
		idb[i] = hbn - 1 - (lower_bound(hb, hb + hbn, ang2[i]) - hb);
	}

	for (int i = 1; i < now; i ++) Add(ida[i], idb[i]);
	for (int i = 0; i < N; i ++) {
		sort(VEC[i].begin(), VEC[i].end());
		vec[i].resize(VEC[i].size() + 1);
	}

	now = 1;
	for (int i = 0; i < n; i ++) {
		if (t[i] == 1) {
			add(ida[now], idb[now], 1);
			++now;
		}
		if (t[i] == 2) {
			add(ida[a[i]], idb[a[i]], -1);
		}
		if (t[i] == 3) {
			int xmin, ymin, xmax, ymax;
			xmin = ida[a[i]], xmax = ida[b[i]];
			ymin = idb[a[i]], ymax = idb[b[i]];

			if (xmin > xmax) swap(xmin, xmax);
			if (ymin > ymax) swap(ymin, ymax);
			
			int xid = han - 1 - xmin, yid = hbn - 1 - ymax;

			if (FR(0, 1) < ha[xid] && hb[yid] < FR(0, 1)) {
				FR tem1 = ha[xid], tem2 = FR(hb[yid].b, -hb[yid].a);
				if (tem2 < tem1) {
					puts("NO");
					continue;
				}
			}
			
			int ret = get(N - 2, ymax) - get(xmin - 1, ymax);
			if (ret > 2) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}