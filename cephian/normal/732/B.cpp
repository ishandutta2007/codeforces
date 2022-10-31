#include <iostream>

using namespace std;

int a[505];

int main() {
	ios::sync_with_stdio(0);
	int n,k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	a[0] = k;
	a[n+1] = k;
	int add = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i] + a[i-1] < k) {
			add += k - (a[i]+a[i-1]);
			a[i] += k - (a[i]+a[i-1]);
		}
	}
	cout << add << "\n";
	for(int i = 1; i <= n; ++i) {
		if(i-1) cout << " ";
		cout << a[i];
	}
	cout << "\n";
	return 0;
}