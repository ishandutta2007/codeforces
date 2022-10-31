#include <bits/stdc++.h>
using namespace std;

int g(int a, int b) {
	return max(a*b, a+b);
}

int f(int a, int b, int c) {
	return max(g(a*b, c), g(a+b, c));
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << max(f(a,b,c), f(b,c,a)) << endl;
	return 0;
}