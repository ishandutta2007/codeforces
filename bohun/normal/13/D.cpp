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

const int nax = 550;

int n, m;
LL res;

struct pt {
	int x, y, z;
};

vector <pt> v;

pt sub(pt a, pt b) {
	pt c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z;
	return c;
}

LL wek(pt a, pt b) {
	return (LL) a.x * b.y - (LL) a.y * b.x;
}

int x, y;

int gao(pt a) {
	return (a.y > 0 || (a.y == 0 && a.x < 0));
}

bool cmp(pt a, pt b) {
	if (gao(a) != gao(b))
		return gao(a) < gao(b);
	return wek(a, b) < 0;
}

vector <pt> q;

int nas(int x) {
	return (x + 1) % ss(q);
}

void qw(pt a) {
	printf ("x = %d y = %d\n", a.x, a.y);
}

void solve(int ind) {
	q.clear();
	pt mid = v[ind];
	rep(i, 0, ss(v) - 1) {
		if (v[i].z == 1) q.pb(v[i]);
		else if (i > ind) q.pb(v[i]);
	}
	for (auto &it : q)
		it = sub(it, mid);
		
	sort(q.begin(), q.end(), cmp);
	
	rep(i, 0, ss(q) - 1) {
		if (q[i].z == 1) continue;
		bool jest = 0;
		pt d;
		
		int j = nas(i);
		while (i != j && !(wek(q[i], q[j]) > 0)) {
			if (q[j].z == 1) {
				if (!jest) {
					jest = 1;
					d = q[j];
				}
				else if (wek(sub(d, q[i]), sub(q[j], q[i])) < 0)
					d = q[j];
			}
			else {
				res += (!jest || !(wek(sub(q[j], q[i]), sub(d, q[i])) < 0));
			}
			j = nas(j);
		}
	}
}
	
	

int main() {	
	scanf ("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf ("%d%d", &x, &y);
		v.pb({x, y, 0});
	}
	rep(i, 1, m) {
		scanf ("%d%d", &x, &y);
		v.pb({x, y, 1});
	}
	
	for (int i = 0; i < ss(v); ++i)
		if (v[i].z == 0)
			solve(i);
	printf ("%lld\n", res);	
	
	return 0;
}