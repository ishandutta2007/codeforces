#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

#define pii pair<int, int>
#define fi first
#define se second
#define si size()

const int inf = 1e9;

const int N = 3005;

int n, a0, b0;
int a[N], b[N];

multiset<pii> q[4];
multiset<pii> :: iterator it;

int ans;

void era(int x) {
	q[0].erase(pii(a[x], x));
	q[1].erase(pii(b[x], x));
}

int main() {
	scanf("%d %d %d", &n, &a0, &b0);
	fo(i, 1, n) scanf("%d", &a[i]);
	fo(i, 1, n) scanf("%d", &b[i]);
	fo(i, 1, n) {
		q[0].insert(pii(a[i], i));
		q[1].insert(pii(b[i], i));
	}
	while(a0 || b0) {
		int v1 = (*--q[0].end()).fi;
		if(a0 == 0) {
			if(q[2].si == 0) v1 = inf; else
				v1 += (*--q[2].end()).fi;
		}
		int v2 = (*--q[1].end()).fi;
		if(b0 == 0) {
			if(q[3].size() == 0) v2 = inf; else
				v2 += (*--q[3].end()).fi;
		}
		ans += max(v1, v2);
		if(v1 > v2) {
			int x = (*--q[0].end()).se;
			era(x);
			if(a0 == 0) {
				pii c = (*--q[2].end());
				q[2].erase(c);
				c.fi = a[c.se] - b[c.se];
				q[3].insert(c);
				b0 --;
			} else a0 --;
			q[2].insert(pii(b[x] - a[x], x));
		} else {
			int x = (*--q[1].end()).se;
			era(x);
			if(b0 == 0) {
				pii c = (*--q[3].end());
				q[3].erase(c);
				c.fi = b[c.se] - a[c.se];
				q[2].insert(c);
				a0 --;
			} else b0 --;
			q[3].insert(pii(a[x] - b[x], x));
		}
	}
	pp("%d\n", ans);
	for(it = q[2].begin(); it != q[2].end(); it ++)
		pp("%d ", (*it).se);
	hh;
	for(it = q[3].begin(); it != q[3].end(); it ++)
		pp("%d ", (*it).se);
	hh;
}