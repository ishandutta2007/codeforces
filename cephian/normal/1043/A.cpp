#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	int k = -1;
	cin >> n;
	int eld = 0;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		k = max(a, k);
		eld += a;
	}
	while(n*k-eld <= eld){ 
		++k;
	}
	cout << k << "\n";
}