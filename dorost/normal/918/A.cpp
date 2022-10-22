#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int fib[25];
bool mark[1005];
int main() {
	int n;
	cin >> n;
	fib[1] = 1;
	fib[2] = 2;
	for (int i = 3; i <= 20; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		mark[fib[i]] = true;
	}
	mark[1] = mark[2] = true;
	for (int i = 1; i <= n; i++) {
		if (mark[i]) {
			cout << 'O';
		}
		else {
			cout << 'o';
		}
	}
	return 0;
}