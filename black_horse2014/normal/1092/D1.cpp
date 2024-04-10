#include <bits/stdc++.h>
using namespace std;

const int N = 220000;
int a[N];

int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	int n; cin >> n;
	vector<int> O;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] &= 1;
		if (!O.empty() && O.back() == a[i]) O.pop_back();
		else O.push_back(a[i]);
	}
	if (O.size() >= 2) cout << "NO" << endl;
	else cout <<"YES"<<endl;
	return 0;
}