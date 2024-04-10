#include <iostream>

using namespace std;
typedef long long ll;

ll f(int n, int k) {
	if(n <= 1) return 0;
	if(k == 0) return 0;
	return f(n-2,k-1) + 2*n-3;
}

int main() {
	ios::sync_with_stdio(0);
	int n,k;
	cin >> n >> k;
	cout << f(n,k) << endl;

	return 0;
}