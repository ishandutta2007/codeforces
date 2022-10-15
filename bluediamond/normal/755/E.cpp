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
	if (k == 2 && n >= 5) {
		cout << n - 1 << "\n";
		for (int i = 1; i < n; i++) cout << i << " " << i + 1 << "\n";
		return 0;
	}
	if (k == 3 && n >= 4) {
		cout << (n - 2) * (n - 3) / 2 + 2 << "\n";
		for (int i = 1; i <= n - 2; i++) for (int j = i + 1; j <= n - 2; j++) cout << i << " " << j << "\n";
		cout << n - 2 << " " << n - 1 << "\n";
		cout << n - 1 << " " << n << "\n";
		return 0;
	}
	cout << "-1\n";
}