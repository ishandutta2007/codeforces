#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
unsigned long long power[20], AA;
unsigned long long solve(unsigned long long x) {
	x++;
	unsigned long long ret = 0, f[19];
	for (int i = 0; i < 19; i++) { f[i] = (x / power[i]) % 10; }
	for (int i = 18; i >= 0; i--) {
		unsigned long long B = 0, c = 0;
		while (x >= power[i]) { x -= power[i]; B += power[i]; ret += power[i] * c; c++; }
		for (int j = 18; j > i; j--)ret += f[j] * B;
		for (int j = i - 1; j >= 0; j--)ret += 45ULL * (B / 10ULL);
	}
	return ret;
}
unsigned long long sum(unsigned long long U) {
	string B = to_string(U);
	unsigned long long D = 0;
	for (int i = 0; i < B.size(); i++)D += (B[i] - '0');
	return D;
}
pair<unsigned long long, unsigned long long>solves(unsigned long long A) {
	unsigned long long L = 0, R = (3ULL << 56), M, minx = (1ULL << 60);
	for (int i = 0; i < 60; i++) {
		M = (L + R) / 2;
		unsigned long long V = solve(M);
		if (V < A) { L = M; }
		else { R = M; minx = min(minx, M); }
	}
	vector<unsigned long long>E; unsigned long long Q = solve(minx);
	for (int i = 0; i <= 20000; i++)E.push_back(solve(i));
	for (unsigned long long i = minx; i <= minx + 20000; i++) {
		int pos1 = lower_bound(E.begin(), E.end(), Q - A) - E.begin();
		if (pos1 < E.size() && E[pos1] == Q - A) {
			return make_pair(pos1 + 1, i);
		}
		Q += sum(i + 1);
	}
	return make_pair(0, 0);
}
int main() {
	cin >> AA; power[0] = 1; for (int i = 1; i < 20; i++)power[i] = power[i - 1] * 10ULL;
	unsigned long long BB = AA;
	while (BB <= (7ULL << 61)) {
		pair<unsigned long long, unsigned long long>V = solves(BB);
		if (V.first != 0ULL) { cout << V.first << " " << V.second << endl; break; }
	}
	return 0;
}