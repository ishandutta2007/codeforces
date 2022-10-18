

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

_ tc, n;

void reduce(vector<_> & c);
void as(_ x, _ y);
_ qr(_ x, _ y, _ z);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		vector<_> o = {1, 2, 3, 4};
		reduce(o);
		for(_ i = 5; i <= n; i += 2) {
			o.push_back(i);
			if(i+1 <= n) o.push_back(i+1);
			else {
				for(_ j = 1; j <= n; ++j) if(j != o[0] && j != o[1] && j != o[2]) {
					o.push_back(j);
					break;
				}
			}
			reduce(o);
		}
		as(o[0], o[1]);
	}

	return 0;
}

_ qr(_ x, _ y, _ z) {
	printf("? %lld %lld %lld\n", x, y, z);
	fflush(stdout);
	_ rv;
	scanf("%lld", &rv);
	return rv;
}

void as(_ x, _ y) {
	printf("! %lld %lld\n", x, y);
	fflush(stdout);
	return;
}

void reduce(vector<_> & c) {
	vector<_> rv;
	vector<_p> r;
	r.push_back(mp(qr(c[1], c[2], c[3]), 0));
	r.push_back(mp(qr(c[0], c[2], c[3]), 1));
	r.push_back(mp(qr(c[0], c[1], c[3]), 2));
	r.push_back(mp(qr(c[0], c[1], c[2]), 3));
	sort(r.begin(), r.end());
//	for(_p i : r) printf("r has %lld %lld\n", i.first, i.second);
	rv.push_back(c[r[0].second]);
	rv.push_back(c[r[1].second]);
	c = rv;
	return;
}