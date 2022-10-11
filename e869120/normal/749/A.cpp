#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int main() {
	cin >> n;
	if (n % 2 == 0) {
		cout << n / 2 << endl;
		for (int i = 0; i < n / 2; i++) {
			if (i)cout << ' ';
			cout << "2";
		}
	}
	if (n % 2 == 1) {
		cout << (n - 1) / 2 << endl;
		for (int i = 0; i < (n - 3) / 2; i++) {
			if (i)cout << ' ';
			cout << "2";
		}
		if (n >= 5)cout << " ";
		cout << "3";
	}
	cout << endl;
	return 0;
}