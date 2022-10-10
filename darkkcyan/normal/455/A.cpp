#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;
int arr[maxn] = {0}, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int a, i = 0; i < n; ++i) cin >> a, ++ arr[a];
	long long a[2];
	a[0] = 0;
	a[1] = arr[1];
	
	for (int i = 2; i < maxn; ++i) {
		a[i & 1] = max(a[i & 1] + (long long) arr[i] * i, a[!(i & 1)]);
	}
	cout << a[(maxn - 1) & 1];
	return 0;
}