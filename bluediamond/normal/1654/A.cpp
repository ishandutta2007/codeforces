#include <iostream>
#include <vector> 
#include <cassert> 
#include <functional> 
#include <algorithm> 

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, total = 0;
		cin >> n;
		vector<int> a(n);
		for (auto& x : a) {
			cin >> x;
		}
		function<void()> proc = [&]() {
			int Index = max_element(a.begin(), a.end()) - a.begin();
			total += a[Index];
			a[Index] = 0;
		};
		proc();
		proc();
		cout << total << "\n";
	}
}