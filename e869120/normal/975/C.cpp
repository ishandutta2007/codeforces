#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

vector<long long>vec; long long n, s, Q, a[200009], q[200009];

int main() {
	cin >> n >> Q; long long G = 0;
	for (int i = 0; i < n; i++) { scanf("%lld", &a[i]); vec.push_back(G + a[i]); G += a[i]; }
	for (int i = 1; i <= Q; i++) {
		scanf("%lld", &q[i]);
		int pos1 = upper_bound(vec.begin(), vec.end(), (s + q[i])) - vec.begin();
		if (pos1 == vec.size()) { s = 0; pos1 = 0; }
		else { s += q[i]; }
		printf("%lld\n", 1LL * vec.size() - pos1);
	}
	return 0;
}