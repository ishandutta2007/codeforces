#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
int n, a[10009], p;
int main() {
	cin >> n; for (int i = 0; i < n; i++) { cin >> p; a[p]++; }
	for (int i = 1; i <= 100; i++) {
		for (int j = i + 1; j <= 100; j++) {
			if (a[i] == a[j] && a[i] + a[j] == n) {
				cout << "YES" << endl; cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}