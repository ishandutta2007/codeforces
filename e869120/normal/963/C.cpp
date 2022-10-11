#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#pragma warning (disable: 4996)

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long N, h[1 << 18], w[1 << 18], c[1 << 18], sx[1 << 18], sy[1 << 18], r;
vector<long long>X, Y;
map<pair<long long, long long>, long long>Map;

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld%lld%lld", &h[i], &w[i], &c[i]);
		X.push_back(h[i]);
		Y.push_back(w[i]);
		r = gcd(r, c[i]);
		Map[make_pair(h[i], w[i])] = c[i];
	}
	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	sort(Y.begin(), Y.end()); Y.erase(unique(Y.begin(), Y.end()), Y.end());

	if ((long long)(X.size())*(long long)(Y.size()) != N) {
		cout << "0" << endl;
		return 0;
	}

	long long E1 = 0;
	for (int i = 0; i < Y.size(); i++) E1 = gcd(E1, Map[make_pair(X[0], Y[i])]);
	for (int i = 0; i < Y.size(); i++) sy[i] = Map[make_pair(X[0], Y[i])] / E1;

	long long E2 = 0;
	for (int i = 0; i < X.size(); i++) E2 = gcd(E2, Map[make_pair(X[i], Y[0])]);
	for (int i = 0; i < X.size(); i++) sx[i] = Map[make_pair(X[i], Y[0])] / E2;

	for (int i = 0; i < X.size(); i++) {
		for (int j = 0; j < Y.size(); j++) {
			if (r*sx[i] * sy[j] != Map[make_pair(X[i], Y[j])]) {
				cout << "0" << endl;
				return 0;
			}
		}
	}

	int cnt = 0;
	for (long long i = 1; i*i <= r; i++) {
		if (r%i != 0) continue;
		cnt++;
		if (i != r / i) cnt++;
	}
	cout << cnt << endl;
	return 0;
}