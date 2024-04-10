#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n; cin >> n;
	for (int i = 0; i <= 850; i++) {
		for (int j = 0; j <= 8500; j++) {
			int D = i * 1234567 + j * 123456;
			if (D > n)continue;
			if ((n - D) % 1234 == 0) { cout << "YES" << endl; return 0; }
		}
	}
	cout << "NO" << endl;
	return 0;
}