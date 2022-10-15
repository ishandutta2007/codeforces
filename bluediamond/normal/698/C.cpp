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

typedef long double ld;

const int N = 20;
const ld eps = 1e-14;
int n;
int k;
ld p[N];
ld dp[1 << N];
ld sol[N];

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

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> p[i];

	int cntz = 0;
	for (int i = 0; i < n; i++) {
		cntz += (p[i] < eps);
	}
	
	if (cntz > n - k) {
		// cntnz <= k
		for (int i = 0; i < n; i++) {
			if (p[i] < eps) cout << "0"; else cout << "1";
			cout << " ";
		}
		cout << "\n";
		return 0;
	}

	dp[0] = 1;

	for (int mask = 0; mask < (1 << n); mask++) {
		vector<int> yes, no;
		for (int i = 0; i < n; i++) if (mask & (1 << i)) yes.push_back(i); else no.push_back(i);
		if ((int)yes.size() > k) continue;
		if ((int)yes.size() == k) {
			for (auto& i : yes) sol[i] += dp[mask];
			
			continue;
		}
		assert((int)yes.size() < k);
		ld sum = 0;
		for (auto& i : no) {
			sum += p[i];
		}
		
		for (auto& i : no) {
			dp[mask + (1 << i)] += dp[mask] * p[i] / sum;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << fixed << setprecision(6) << sol[i] << " ";
	}
	cout << "\n";
}