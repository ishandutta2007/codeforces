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
// 403 -> 404
#define int long long

const int N = (int)1e5 + 7;
int n;
int m;
int c[N];
int w[N];
int full[N];
int x[N];
int y[N];

int rep(int x) {
	x %= 100;
	if (x < 0) x += 100;
	return x;
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

	cin >> n >> m;
	int cost = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		full[i] = c[i] / 100;
		c[i] = rep(c[i]);

		x[i] = full[i];
		y[i] = c[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
		
	priority_queue<pair<int, int>> pq;

	for (int _ = 1; _ <= n; _++) {
		if (c[_]) {
			m -= c[_];
			pq.push({ -w[_] * rep(-c[_]), _ });
			while (m < 0) {
				assert(!pq.empty());
				auto it = pq.top();
				pq.pop();
				int i = it.second;
				x[i]++;
				y[i] = 0;
				cost -= it.first;
				m += 100;
			}

		}
	}
	cout << cost << "\n";
	for (int i = 1; i <= n; i++) {
		cout << x[i] << " " << y[i] << "\n";
	}
}