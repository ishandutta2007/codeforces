#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, k;
	cin >> n >> k;
	while(k--) {
		if(n%10 == 0) n/= 10;
		else  --n;
	}
	cout << n << "\n";

}