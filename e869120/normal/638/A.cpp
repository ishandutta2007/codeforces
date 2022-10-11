#include<iostream>
using namespace std;
int n, a;
int main() {
	cin >> n >> a;
	if (a % 2 == 0)cout << (n - a) / 2 + 1 << endl;
	else cout << a / 2 + 1 << endl;
	return 0;
}