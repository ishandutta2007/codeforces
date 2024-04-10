#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> V(51,0);
	int mi = 50;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++V[x];
		mi = min(mi, x);
	}
	if (V[mi] > n/2) cout << "Bob" << endl;
	else cout << "Alice" << endl;
}