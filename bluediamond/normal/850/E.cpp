#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 

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
		if (b & 1) r = mul(r, a);
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


void fft(int n, vector<int>& a, bool inv) {

	for (int l = 2; l <= (1 << n); l *= 2) {
		for (int i = 0; i < (1 << n); i += l) {
			for (int j = 0; j < l / 2; j++) {
				int x = a[i + j], y = a[i + l / 2 + j];
				a[i + j] = add(x, y);
				a[i + l / 2 + j] = add(x, -y);
			}
		}
	}

	if (inv) {
		int invn = dv(1, (1 << n));
		for (auto& x : a) {
			x = mul(x, invn);
		}
	}
}

vector<int> xor_convolution(int n, vector<int> a, vector<int> b) {
	fft(n, a, 0);
	fft(n, b, 0);

	vector<int> ret((1 << n), 0);
	for (int i = 0; i < (1 << n); i++) {
		ret[i] = mul(a[i], b[i]);
	}

	fft(n, ret, 1);
	return ret;
}

int n;
vector<int> results, coef;

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



	{
		string s_results;
		cin >> n >> s_results;
		
		results.resize((1 << n), 0);
		coef.resize((1 << n), 1);
		for (int i = 0; i < (1 << n); i++) {
			results[i] = s_results[i] - '0';
		}
		for (int i = 1; i < (1 << n); i++) {
			int j = i & (-i);
			coef[i] = 2 * coef[i - j];
		}
		for (int i = 0; i < (1 << n); i++) {
			int j = (1 << n) - 1 - i;
			if (i < j) {
				swap(coef[i], coef[j]);
			}
		}
	}


	int sol = 0;

	vector<int> convolution = xor_convolution(n, results, results);
	for (int i = 0; i < (1 << n); i++) {
		addup(sol, mul(convolution[i], coef[i]));
	}

	mulup(sol, 3);
	cout << sol << "\n";
}