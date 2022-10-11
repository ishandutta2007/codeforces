#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int main() {
	cin >> n;
	for (int i = n; i >= 1; i--) {
		if (n%i == 0 && (n / i) >= i) {
			cout << i << ' ' << n / i << endl; break;
		}
	}
	return 0;
}