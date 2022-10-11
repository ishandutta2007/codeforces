#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#pragma warning(disable:4996)
long long n, k, l[3000000], r[3000000], s[3000000], mod = 1000000007; vector<long long>P; vector<pair<long long, long long>>G;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &l[i], &r[i]); l[i] += mod; r[i] += mod;
		P.push_back(l[i]); P.push_back(r[i]);
	}
	sort(P.begin(), P.end());
	for (int i = 0; i < n; i++) {
		l[i] = lower_bound(P.begin(), P.end(), l[i]) - P.begin();
		r[i] = lower_bound(P.begin(), P.end(), r[i] + 1) - P.begin(); r[i]--;
		s[l[i]]++; s[r[i]]--;
	}
	for (int i = 1; i <= P.size(); i++)s[i] += s[i - 1];
	long long t = -1;
	for (int i = 0; i < P.size(); i++) {
		if (s[i] >= k && t == -1)t = P[i];
		if (s[i] < k && t != -1) { G.push_back(make_pair(t, P[i])); t = -1; }
	}
	cout << G.size() << endl;
	for (int i = 0; i < G.size(); i++)printf("%lld %lld\n", G[i].first - mod, G[i].second - mod);
	return 0;
}