#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int a, b;
	cin >> a >> b;
	int diff = abs(a-b);
	int amv = diff/2;
	int bmv = diff - amv;
	cout << amv*(amv+1)/2 + bmv*(bmv+1)/2 << endl;
	return 0;
}