#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int n;
int a[50];
int b[50];

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	sort(b,b+n);
	int j = 0;
	for(int i = 0; i < n; ++i) {
		if(i == 0 || b[i] != b[i-1]) {
			a[j++] = b[i];
		}
	}
	for(int i = 2; i < j; ++i) {
		if(a[i-1] == a[i]-1 && a[i-2] == a[i]-2) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}