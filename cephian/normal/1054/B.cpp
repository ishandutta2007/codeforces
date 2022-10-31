#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;


int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int m = -1;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if(a > m+1) {
			cout << i+1 << "\n";
			return 0;
		}
		m = max(m, a);
	}	
	cout << "-1\n";

}