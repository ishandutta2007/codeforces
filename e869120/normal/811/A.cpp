#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int a, b;
int main() {
	cin >> a >> b;
	for (int i = 1; i <= 100000; i++) {
		if (i % 2 == 1)a -= i; else b -= i;
		if (a < 0) { cout << "Vladik" << endl; break; }
		if (b < 0) { cout << "Valera" << endl; break; }
	}
	return 0;
}