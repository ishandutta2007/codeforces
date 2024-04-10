#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

long long pows(long long a, long long b) {
	long long x = 1; for (int i = 0; i < b; i++) { x *= a; }
	return x;
}

long long isdivisor(long long x, long long d) {
	long long M = 1500000000LL;
	if (d == 3) M = 1500000LL;
	if (d == 4) M = 40000LL;

	long long cl = 1, cr = M, cm, maxn = 0;
	for (int i = 0; i < 40; i++) {
		cm = (cl + cr) / 2;
		long long E = pows(cm, d);
		if (E <= x) { maxn = max(maxn, cm); cl = cm; }
		else { cr = cm; }
	}
	if (pows(maxn, d) != x) return -1;
	return maxn;
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long N, A[509];
vector<pair<long long, int>>vec; vector<long long>E[509], G;
map<long long, long long>Map;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i]; bool flag = false;
		for (int j = 0; j < vec.size(); j++) {
			if (vec[j].first == A[i]) { flag = true; vec[j].second++; }
		}
		if (flag == false) vec.push_back(make_pair(A[i], 1));
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			long long EE = gcd(vec[i].first, vec[j].first);
			if (EE >= 2) { E[i].push_back(EE); E[j].push_back(EE); }
		}
	}
	long long C = (1LL << 61);
	for (int i = 0; i < vec.size(); i++) {
		sort(E[i].begin(), E[i].end());
		E[i].erase(unique(E[i].begin(), E[i].end()), E[i].end());
		long long A1 = isdivisor(vec[i].first, 4);
		long long A2 = isdivisor(vec[i].first, 3);
		long long A3 = isdivisor(vec[i].first, 2);

		if (A1 >= 1) { Map[A1] += 4LL * vec[i].second; G.push_back(A1); }
		else if (A2 >= 1) { Map[A2] += 3LL * vec[i].second; G.push_back(A2); }
		else if (A3 >= 1) { Map[A3] += 2LL * vec[i].second; G.push_back(A3); }
		else {
			for (int j = 0; j < E[i].size(); j++) { Map[E[i][j]] += 1LL * vec[i].second; G.push_back(E[i][j]); }
			for (int j = 0; j < 2 - (int)(E[i].size()); j++) { Map[C] += 1LL * vec[i].second; G.push_back(C); C++; }
		}
	}
	sort(G.begin(), G.end());
	G.erase(unique(G.begin(), G.end()), G.end());

	long long ans = 1, mod = 998244353;
	for (int i = 0; i < G.size(); i++) { ans *= (Map[G[i]] + 1LL); ans %= mod; }
	cout << ans << endl;
	return 0;
}