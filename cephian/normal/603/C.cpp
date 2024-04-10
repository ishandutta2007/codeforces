#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int solve(int a) {
	if(a == 1) return 1;
	if(a == 2) return 0;
	if(a == 3) return 1;
	if(a == 4) return 2;
	if(a%2 == 1) return 0;
	int k = solve(a/2);
	if(k == 1) return 2;
	return 1;
}

int evn_solve(int a) {
	if(a == 1) return 1;
	if(a == 2) return 2;
	if(a%2 == 1) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int grundy = 0;
	for(int x : a) {
		if(k % 2 == 0) {
			grundy ^= evn_solve(x);
		} else {
			grundy ^= solve(x);
		}
	}

	if(grundy == 0) cout << "Nicky\n";
	else cout << "Kevin\n";
}