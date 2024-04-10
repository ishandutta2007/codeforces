#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 
#include <numeric> 

bool home = true;
using namespace std;
// 404 -> 405

typedef long long ll;

const int M = (int)1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= M) {
		return a - M;
	}
	if (a < 0) {
		return a + M;
	}
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

int get(int x_want, vector<int> ys) {
	int dim = (int)ys.size();
	vector<int> fact(dim + 1, 1), ifact(dim + 1);
	for (int i = 1; i <= dim; i++) fact[i] = mul(fact[i - 1], i);
	ifact[dim] = dv(1, fact[dim]);
	for (int i = dim - 1; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);

	assert((int)ys.size() == dim);
	int prodall = 1;
	for (int i = 0; i < dim; i++) {
		mulup(prodall, add(x_want, -i));
	}

	int sol = 0;
	for (int i = 0; i < dim; i++) {
		int x = 1, y = 1;

		x = ifact[i];
		y = ifact[dim - 1 - i];
		if ((dim - i) % 2 == 0) {
			mulup(y, M - 1);
		}
		addup(sol, dv(mul(ys[i], mul(prodall, mul(x, y))), add(x_want, -i)));
	}
	return sol;
}

signed main() {
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


	int n, k;
	cin >> n >> k;
	if (k == 0) {
		cout << n << "\n";
		return 0;
	}
	vector<int> ys(k + 2);
	for (int j = 0; j < k + 2; j++) {
		ys[j] = pw(j, k);
	}
	for (int j = 1; j < k + 2; j++) {
		addup(ys[j], ys[j - 1]);
	}
	if (n < k + 2) {
		cout << ys[n] << "\n";
		return 0;
	}
	int sol = get(n, ys);
	if (home) assert(sol == 295063419);
	cout << sol << "\n";
}