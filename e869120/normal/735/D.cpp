#include<iostream>
using namespace std;
bool prime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0)return false;
	}
	return true;
}
int main() {
	int n; cin >> n;
	if (n % 2 == 0) {
		if (n == 2)cout << "1" << endl;
		else cout << "2" << endl;
	}
	else {
		if (prime(n) == true)cout << "1" << endl;
		else if (prime(n - 2) == true)cout << "2" << endl;
		else cout << "3" << endl;
	}
	return 0;
}