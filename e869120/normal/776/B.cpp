#include<iostream>
#include<vector>
using namespace std;
int col[120000], n; bool used[120000];
vector<int>G[120000];
int main() {
	cin >> n;
	if (n == 1) { cout << "1" << endl; cout << "1" << endl; return 0; }
	if (n == 2) { cout << "1" << endl; cout << "1 1" << endl; return 0; }
	cout << "2" << endl;
	for (int i = 2; i <= n + 1; i++) {
		if (i >= 3)cout << ' ';
		bool OK = true;
		for (int j = 2; j*j <= i; j++) {
			if (i%j == 0)OK = false;
		}
		if (OK == true)cout << "1";
		else cout << "2";
	}
	cout << endl;
	return 0;
}