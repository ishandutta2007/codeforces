#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

pii A[202020];
vector<int> x;
vector<int> y;
int N;

int T[4 * 202020];

void upd(int idx, int s, int e, int p) {
	if(e < s || p < s || e < p) return;
	if(s == e) { T[idx] = 1; return; }
	int m = s + e >> 1;
	upd(idx * 2, s, m, p);
	upd(idx * 2 + 1, m + 1, e, p);
	T[idx] = T[idx * 2] + T[idx * 2 + 1];
}

int get(int idx, int s, int e, int p, int q) {
	if(e < s || q < p || q < s || e < p) return 0;
	if(p <= s && e <= q) return T[idx];
	int m = s + e >> 1;
	return get(idx * 2, s, m, p, q) + get(idx * 2 + 1, m + 1, e, p, q);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d", &A[i].second, &A[i].first);
		y.push_back(A[i].first);
		x.push_back(A[i].second);
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	y.erase(unique(y.begin(), y.end()), y.end());

	for(int i = 1; i <= N; i++) {
		A[i].first = lower_bound(y.begin(), y.end(), A[i].first) - y.begin() + 1;
		A[i].second = lower_bound(x.begin(), x.end(), A[i].second) - x.begin() + 1;
	}

	sort(A + 1, A + N + 1);
	reverse(A + 1, A + N + 1);

	ll ans = 0;
	ll xsz = x.size();

	int p = 1;
	while(p <= N) {
		int t = p;
		vector<int> v;
		while(p <= N && A[p].first == A[t].first) {
			upd(1, 1, xsz, A[p].second);
			v.push_back(A[p].second);
			p++;
		}
		ll s = get(1, 1, xsz, 1, xsz);
		ans += s * (s + 1) / 2;

		reverse(v.begin(), v.end());
		
		s = get(1, 1, xsz, 1, v[0] - 1);
		ans -= s * (s + 1) / 2;

		s = get(1, 1, xsz, v.back() + 1, xsz);
		ans -= s * (s + 1) / 2; 

		for(int i = 1; i < v.size(); i++) {
			s = get(1, 1, xsz, v[i - 1] + 1, v[i] - 1);
			ans -= s * (s + 1) / 2;
		}
	}

	printf("%lld\n", ans);

	return 0;
}