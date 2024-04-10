#include<iostream>
#include<algorithm>
using namespace std;
int n, a[120000];
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n); int c = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > c)c++;
	}
	cout << c + 1 << endl;
	return 0;
}