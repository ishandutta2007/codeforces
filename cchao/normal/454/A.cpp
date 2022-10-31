#include <bits/stdc++.h>
using namespace std;

void f(int a, int b) {
	int c = (b - a) / 2;
	for(int i = 0; i < c; ++i) cout << '*';
	for(int i = 0; i < a; ++i) cout << 'D';
	for(int i = 0; i < c; ++i) cout << '*';
	cout << endl;
}

int main() {
	int n; cin >> n;
	int a = n / 2, b = n / 2 + 1;
	for(int i = 1; i <= a; ++i) f(i*2-1, n);
	for(int i = b; i >= 1; --i) f(i*2-1, n);
	return 0;
}