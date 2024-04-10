#include <iostream>
#include <vector> 
#include <cassert> 
#include <functional> 
#include <algorithm> 

bool home = true;
using namespace std;

typedef long long ll;

const int M = (int)1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= M) return a - M;
	if (a < 0) return a + M;
	return a;
}

int mul(int a, int b) {
	return a * (ll)b % M;
}

int pw(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) {
			r = mul(r, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return r;
}

int dv(int a, int b) {
	return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
	a = add(a, b);
}

void mulup(int& a, int b) {
	a = mul(a, b);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef ONLINE_JUDGE
	home = 0;
#endif
	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}

	int k, n, m;
	cin >> k >> n >> m;

	vector<pair<int, int>> s0(n), s1(m);
	vector<int> xs;

	for (auto& it : s0) cin >> it.first >> it.second;
	for (auto& it : s1) cin >> it.first >> it.second;

	{
		vector<int> allX;
		allX.push_back(1);
		allX.push_back(k + 1);
		for (auto& it : s0) {
			allX.push_back(it.first);
			allX.push_back(it.second + 1);
		}
		for (auto& it : s1) {
			allX.push_back(it.first);
			allX.push_back(it.second + 1);
		}
		sort(allX.begin(), allX.end());
		xs.push_back(allX[0]);
		for (int i = 1; i < (int)allX.size(); i++) {
			if (allX[i] != allX[i - 1]) {
				xs.push_back(allX[i]);
			}
		}
	}

	int chunks = (int)xs.size() - 1;
	vector<int> dp0(chunks + 1, 0);
	vector<int> dp1(chunks + 1, 0);
	int sum0 = 0, sum1 = 0, tot = 0;

	vector<int> max0(chunks + 1, 0), max1(chunks + 1, 0);

	for (auto& it : s0) {
		int chunkl = lower_bound(xs.begin(), xs.end(), it.first) - xs.begin() + 1;
		int chunkr = lower_bound(xs.begin(), xs.end(), it.second + 1) - xs.begin();

		max0[chunkr] = max(max0[chunkr], chunkl);

		assert(1 <= chunkl && chunkl <= chunkr && chunkr <= chunks);
	}

	for (auto& it : s1) {
		int chunkl = lower_bound(xs.begin(), xs.end(), it.first) - xs.begin() + 1;
		int chunkr = lower_bound(xs.begin(), xs.end(), it.second + 1) - xs.begin();

		max1[chunkr] = max(max1[chunkr], chunkl);

		assert(1 <= chunkl && chunkl <= chunkr && chunkr <= chunks);
	}

	dp0[0] = 1;
	sum0 = 1;
	tot = 1;

	int z0 = 0, z1 = 0;


	for (int chunk = 1; chunk <= chunks; chunk++) {
		int limit0 = max0[chunk], limit1 = max1[chunk], len = xs[chunk] - xs[chunk - 1], ways01 = add(pw(2, len), -2);
		int ant0 = sum0, ant1 = sum1;

		dp0[chunk] = mul(tot, ways01);
		addup(sum0, dp0[chunk]);

		for (int i = z0; i < limit1; i++) {
			addup(sum0, -dp0[i]);
			dp0[i] = 0;
		}

		for (int i = z1; i < limit0; i++) {
			addup(sum1, -dp1[i]);
			dp1[i] = 0;
		}

		z0 = max(0, max(z0, limit1 - 2));
		z1 = max(0, max(z1, limit0 - 2));

		if (limit1 <= chunk - 1) {
			addup(sum0, ant1);
			addup(dp0[chunk - 1], ant1);
		}
		if (limit0 <= chunk - 1) {

			addup(sum1, ant0);
			addup(dp1[chunk - 1], ant0);
		}

		tot = add(sum0, sum1);
	}
	cout << tot << "\n";
}