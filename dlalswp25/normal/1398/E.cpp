#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int Q;

set<int> L, H;
ll sum = 0;

set<int> X, Y;

void reg(int k) {
	while(H.size() < k) {
		auto it = --L.end();
		sum += *it;
		H.insert(*it);
		L.erase(it);
	}
	while(H.size() > k) {
		sum -= *H.begin();
		L.insert(*H.begin());
		H.erase(H.begin());
	}
}

int main() {
	scanf("%d", &Q);

	ll tot = 0;
	while(Q--) {
		int t, d; scanf("%d%d", &t, &d);
		tot += d;

		if(t) {
			if(d > 0) Y.insert(d);
			else Y.erase(-d);
		}
		else {
			if(d > 0) X.insert(d);
			else X.erase(-d);
		}

		if(d > 0) {
			if(!L.size() || *(--L.end()) < d) { sum += d; H.insert(d); }
			else L.insert(d);
		}
		else {
			if(H.find(-d) != H.end()) {
				sum += d;
				H.erase(H.find(-d));
			}
			else {
				L.erase(L.find(-d));
			}
		}

		// printf("L : "); for(int i : L) printf("%d ", i); puts("");
		// printf("H : "); for(int i : H) printf("%d ", i); puts("");

		ll tmp = 0;

		int x = X.size(), y = Y.size();

		if(!y) { printf("%lld\n", tot); continue; }

		if(!x) reg(y - 1);
		else {
			reg(y);

			int my = *Y.begin();
			int mx = *(--X.end());
			if(my > mx) {
				tmp = mx - my;
			}
		}

		// printf("L : "); for(int i : L) printf("%d ", i); puts("");
		// printf("H : "); for(int i : H) printf("%d ", i); puts("");

		// printf("%lld\n", tmp);

		printf("%lld\n", tot + sum + tmp);
	}

	return 0;
}