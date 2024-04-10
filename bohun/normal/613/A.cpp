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

const int N = 1e5 + 1000;

int n, x, y;
pair <int, int> t[N];

LD a, b;
LD pi = acos(-1);

LD dis(int x, int y) {
	return sqrtl((LD) (t[x].fi - t[y].fi) * (t[x].fi - t[y].fi) + (LD) (t[x].se - t[y].se) * (t[x].se - t[y].se));
}

LD wek(int a, int b, int c, int d) {
	return (LD) a * d - (LD) b * c;
}

int main() {	
	a = 1010100110011001;
	scanf ("%d%d%d", &n, &x, &y);
	rep(i, 1, n) {
		scanf ("%d%d", &t[i].fi, &t[i].se);
		t[i].fi -= x;
		t[i].se -= y;
		a = min(a, sqrtl((((LD)t[i].fi * t[i].fi) + ((LD)t[i].se * t[i].se))));
		b = max(b, sqrtl(((LD)t[i].fi * t[i].fi) + ((LD)t[i].se * t[i].se)));
	}
	rep(i, 1, n) {
		int j = i % n + 1;
		LD qw = abs(wek(-t[i].fi, -t[i].se, t[j].fi - t[i].fi, t[j].se - t[i].se));
		if (dis(i, 0) * dis(i, 0) < dis(j, 0) * dis(j, 0) + dis(i, j) * dis(i, j))
			if (dis(j, 0) * dis(j, 0) < dis(i, 0) * dis(i, 0) + dis(i, j) * dis(i, j))
				a = min(a, qw / dis(i, j));
		//cat(qw / dis(i, j));
	}
		
	printf ("%.10Lf\n", (b * b - a * a) * pi);
	
		
	return 0;
}