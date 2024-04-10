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
 
using namespace std;

const int nax = 2e5 + 111;

int n;
pair <int, int> t[nax];

LL ans;

struct fen {
	LL f[nax];
	
	fen () {
		fill(f, f + nax, 0);
	}
	
	void add(int x, int c) {
		for (int i = x; i < nax; i += i & -i)
			f[i] += c;
	}
	
	LL pref(int x) {
		LL res = 0;
		for (int i = x; 0 < i; i -= i & -i)
			res += f[i];
		return res;
	}
	
	LL range(int l, int r) {
		return pref(r) - pref(l - 1);
	}
};
	
vector <int> val;

int pos(int x) {
	return (int) (lower_bound(val.begin(), val.end(), x) - val.begin()) + 1;
}

fen s1 = fen();
fen s2 = fen();
fen s3 = fen();
fen sum1 = fen();
fen sum2 = fen();
fen sum3 = fen();
 
int main() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", &t[i].fi);
	rep(i, 1, n) scanf ("%d", &t[i].se);
	rep(i, 1, n) val.pb(t[i].se);
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	
	sort(t + 1, t + n + 1);
	
	rep(i, 1, n) {
		int speed = t[i].se;
		int x = t[i].fi;
		
		if (speed < 0) {
			ans += (LL) s1.range(0, pos(speed)) * x - sum1.range(0, pos(speed));
			s1.add(pos(speed), 1);
			sum1.add(pos(speed), x);
		}
		if (speed == 0) {
			ans += (LL) s2.range(pos(speed), pos(speed)) * x - sum2.range(pos(speed), pos(speed));
			ans += (LL) s1.range(0, pos(speed)) * x - sum1.range(0, pos(speed));
			s2.add(pos(speed), 1);
			sum2.add(pos(speed), x);
		}
		if (speed > 0) {
			ans += (LL) s2.range(0, nax - 1) * x - sum2.range(0, nax - 1);
			ans += (LL) s3.range(0, pos(speed)) * x - sum3.range(0, pos(speed));
			ans += (LL) s1.range(0, nax - 1) * x - sum1.range(0, nax - 1);
			s3.add(pos(speed), 1);
			sum3.add(pos(speed), x);
		}
	}
	printf ("%lld\n", ans);
	
	return 0;
}