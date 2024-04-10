#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	typedef long long LL;
	vector<LL> M(n), R(n);
	for(auto &it : M) cin >> it;
	for(auto &it : R) cin >> it;
	LL G = 1;
	for(auto &it : M) G = G / __gcd(G, it) * it;

	vector<bool> v(G);

	for(int i = 0; i < n; ++i) {
		R[i] = R[i] % M[i];
		if(R[i] < 0) R[i] += M[i];
		for(int j = R[i]; j < G; j += M[i]) v[j] = true;
	}
	int cnt = 0;
	for(int i = 0; i < G; ++i)
		cnt += v[i];
	printf("%.12f\n", 1.0 * cnt / G);

	return 0;
}