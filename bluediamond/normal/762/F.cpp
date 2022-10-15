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

const int N = 1000 + 7;
int n;
vector<int> g[N];

int nsmall;
vector<int> gsmall[N];

map<string, vector<string>> kids_of;
map<string, int> dp[N];

string dfs_small(int a, int p = -1) {
	vector<string> kids;
	for (auto& b : gsmall[a]) {
		if (b == p) continue;
		kids.push_back(dfs_small(b, a));
	}
	sort(kids.begin(), kids.end());
	string sol = "(";
	for (auto& kid : kids) {
		sol += kid;
	}
	sol += ")";
	if (!kids_of.count(sol)) {
		kids_of[sol] = kids;
	}
	return sol;
}

int print = 0;

void dfs(int a, int p = -1) {
	{
		vector<int> kids;
		for (auto& b : g[a]) {
			if (b == p) continue;
			kids.push_back(b);
			dfs(b, a);
		}
		g[a] = kids;
	}
	for (auto& itERator : kids_of) {
		string s = itERator.first;
		vector<string> kids = itERator.second;
		if (s == "()") {
			dp[a][s] = 1;
			continue;
		}
		int y = (int)kids.size();
		vector<int> cnt(1 << y, 0);
		cnt[0] = 1;
		for (auto& b : g[a]) {
			vector<int> ncnt(1 << y, 0);

			for (auto& it : dp[b]) {
				string t = it.first;
				int coef = it.second;
				if (!coef) continue;
				for (int cur = 0; cur < (1 << y); cur++) {
					for (int i = 0; i < y; i++) {
						if (cur & (1 << i)) continue;
						if (t == kids[i]) {
							addup(ncnt[cur + (1 << i)], mul(cnt[cur], coef));
							break;
						}
					}
				}
			}

			for (int i = 0; i < (1 << y); i++) {
				cnt[i] = add(ncnt[i], cnt[i]);
			}
		}
		int coef = cnt[(1 << y) - 1];
		if (!coef) continue;
		dp[a][s] = coef;
		if ((int)s.size() == 2 * nsmall) {
			addup(print, coef);
		}
	}
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


	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cin >> nsmall;
	for (int i = 1; i < nsmall; i++) {
		int a, b;
		cin >> a >> b;
		gsmall[a].push_back(b);
		gsmall[b].push_back(a);
	}

	if (nsmall == 1) {
		cout << n << "\n";
		return 0;
	}

	for (int i = 1; i <= nsmall; i++) {
		dfs_small(i);
	}
	dfs(1);
	cout << print << "\n";
}