/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 3e5 + 10, inf = 1e9;

vector<char> inp[N], b[N], temp[N];

int solve(vector<char> *a, int n, int m, vector<char> letters);
int fill_cost(vector<char> &a, vector<char> &b, char A, char G, int m);
void transpose(vector<char> *a, int n, int m);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		inp[i].resize(m + 1);
		for (int j = 1; j <= m; ++j) {
			cin >> inp[i][j];
			// cout << inp[i][j] << endl;
		}
		// cout << endl;
	}
	vector<char> letters = {'A', 'C', 'G', 'T'};
	int best = inf, tr = -1;
	vector<char> best_perm;
	do {
		int cur = solve(inp, n, m, letters);
		if (cur < best) {
			best = cur;
			tr = 0;
			best_perm = letters;
		}
		transpose(inp, n, m);
		cur = solve(inp, m, n, letters);
		if (cur < best) {
			best = cur;
			tr = 1;
			best_perm = letters;
		}
		transpose(inp, m, n);
	} while (next_permutation(letters.begin(), letters.end()));
	if (tr) {
		transpose(inp, n, m);
		swap(n, m);
	}
	solve(inp, n, m, best_perm);
	if (tr) {
		transpose(b, n, m);
		swap(n, m);
	}
	// cout << best << endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << b[i][j];
		}
		cout << '\n';
	}
}

int solve(vector<char> *a, int n, int m, vector<char> letters) {
	char A = letters[0], G = letters[1];
	char C = letters[2], T = letters[3];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		b[i].resize(m + 1);
		swap(A, C);
		swap(G, T);
		int w1 = fill_cost(a[i], b[i], A, G, m);
		int w2 = fill_cost(a[i], b[i], G, A, m);
		if (w1 < w2) {
			fill_cost(a[i], b[i], A, G, m);
		}
		ans += min(w1, w2);
	}
	return ans;
}

int fill_cost(vector<char> &a, vector<char> &b, char A, char G, int m) {
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		swap(A, G);
		b[i] = A;
		if (a[i] != b[i]) {
			++ans;
		}
	}
	return ans;
}

void transpose(vector<char> *a, int n, int m) {
	for (int i = 1; i <= m; ++i) {
		a[i].resize(n + 1);
		temp[i].resize(n + 1);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			temp[j][i] = a[i][j];
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			a[i][j] = temp[i][j];
		}
	}
}