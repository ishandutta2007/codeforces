#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	//freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << "! 1" << endl;
		return 0;
	}

	vector<int> asks;

	for (int i = 0; i < k + 1; ++i) {
		cout << "? ";
		for (int j = 0; j <= k; ++j) {
			if (i==j) continue;
			cout << j+1 << " ";
		}
		cout << endl;
		int a, b;
		cin >> a >> b;
		asks.push_back(b);
	}

	sort(asks.begin(), asks.end(), greater<int>());
	for (int i = 0; i < asks.size(); ++i) {
		if (asks[i] != asks[0]) {
			cout << "! " << i << endl;
			return 0;
		}
	}

}