#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, a[250000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	int s = 0;
	for (int i = 0; i <= n; i++) {
		if (a[i] == 0) { if (s % 2 == 1) { cout << "NO" << endl; return 0; } s = 0; }
		s += a[i];
	}
	cout << "YES" << endl;
	return 0;
}