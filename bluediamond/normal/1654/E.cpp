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

bool home = true;
using namespace std;

typedef long long ll;

const int C = (int)5e7;

struct myf {
	vector<int> f, ls;
	int unixtime;
	vector<int> inds;

	myf() :
		f(2 * C),
		ls(2 * C),
		unixtime(1) {
	}

	int getmaxAndClear() {
		int sol = 0;
		for (auto& x : inds) {
			sol = max(sol, f[x]);
		}
		unixtime++;
		inds.clear();
		return sol;
	}

	int& operator[](int i) {
		i += C;
		assert(0 <= i && i < 2 * C);
		if (ls[i] < unixtime) {
			ls[i] = unixtime;
			f[i] = 0;
			inds.push_back(i);
		}
		return f[i];
	}


} f;


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


	int n;
	cin >> n;
	vector<int> a(n);
	int sol = n;

	for (auto& x : a) {
		cin >> x;
	}
	function<int(int)> get_cost = [&](int d) {
		for (int i = 0; i < n; i++) {
			f[a[i] - d * i]++;
		}
		return n - f.getmaxAndClear();
	};

	for (int C = 0; C < 2; C++) {
		reverse(a.begin(), a.end());


		int rad = sqrt((int)1e5);
		for (int d = 0; d <= rad; d++) {
			sol = min(sol, get_cost(d));
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < min(n, i + rad); j++) {
				if ((a[i] - a[j]) % (i - j) == 0) {
					int x = (a[i] - a[j]) / (i - j);
					f[x]++;
				}
			}
			sol = min(sol, n - 1 - f.getmaxAndClear());
		}
	}
	cout << sol << "\n";
}