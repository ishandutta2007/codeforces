#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

vector<pii> factorize(int x) {
	vector<pii> ret;
	for(int i = 2; i * i <= x; i++) {
		if(x % i) continue;
		if(!ret.size() || ret.back().first != i) ret.emplace_back(i, 1);
		else ret.back().second++;
		x /= i;
	}
	if(x > 1) {
		if(!ret.size() || ret.back().first != x) ret.emplace_back(x, 1);
		else ret.back().second++;
	}
	return ret;
}

bool is_composite(int x) {
	vector<pii> v = factorize(x);
	if(v.size() >= 2) return true;
	return v.size() == 1 && v[0].second > 1;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int x, d; scanf("%d%d", &x, &d);
		int tmp = x, cnt = 0;
		while(1) {
			if(tmp % d) break;
			tmp /= d; cnt++;
		}
		if(cnt == 1) { puts("NO"); continue; }
		vector<pii> v = factorize(d);
		if(v.size() >= 2) {
			if(cnt >= 3) { puts("YES"); continue; }
			if(is_composite(tmp)) puts("YES");
			else puts("NO");
			continue;
		}

		int p, k; tie(p, k) = v[0];
		tmp = x; cnt = 0;
		while(1) {
			if(tmp % p) break;
			tmp /= p; cnt++;
		}

		bool ans = false;
		for(int i = 1; i <= cnt / k; i++) {
			if(cnt > i * (2 * k - 1)) continue;
			if(i < cnt / k) { ans = true; break; }
			if(k == 1) {
				if(is_composite(tmp)) ans = true;
				break;
			}
			if(cnt - k * i >= 2) ans = true;
			else if(cnt - k * i) {
				if(tmp != 1) ans = true;
			}
			else {
				if(is_composite(tmp)) ans = true;
			}
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}