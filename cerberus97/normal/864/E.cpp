/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e2 + 10, T = 3000;

struct s {
	int t, d, p, ind;
	bool operator<(const s& rhs) const {
	    return this->d > rhs.d;
	}
} a[N];

vector <int> chosen;
int dp[N][T];
bool seen[N][T] = {0}, choice[N][T] = {0};

int solve(int i, int j);
void backtrack(int i, int j);

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].t >> a[i].d >> a[i].p;
		a[i].ind = i;
	}
	sort(a + 1, a + 1 + n);
	int ans = solve(n, 0);
	backtrack(n, 0);
	cout << ans << endl;
	cout << chosen.size() << endl;
	for (auto &i : chosen) {
		cout << i << ' ';
	}
}

int solve(int i, int j) {
	if (!i) {
		return 0;
	}
	if (seen[i][j]) {
		return dp[i][j];
	}
	seen[i][j] = true;
	dp[i][j] = solve(i - 1, j);
	if (j + a[i].t < a[i].d and solve(i - 1, j + a[i].t) + a[i].p > dp[i][j]) {
		dp[i][j] = solve(i - 1, j + a[i].t) + a[i].p;
		choice[i][j] = true;
	}
	return dp[i][j];
}

void backtrack(int i, int j) {
	if (!i) {
		return;
	}
	if (choice[i][j]) {
		chosen.pb(a[i].ind);
		backtrack(i - 1, j + a[i].t);
	}
	else {
		backtrack(i - 1, j);
	}
}