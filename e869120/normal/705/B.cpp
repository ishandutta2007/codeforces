#include<iostream>
using namespace std;
long long n, cnt, a;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a; cnt += a - 1;
		cout << 2 - (cnt % 2) << endl;
	}
	return 0;
}