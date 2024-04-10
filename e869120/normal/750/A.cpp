#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int main() {
	cin >> n >> k; k = 240 - k; int cnt = 0, p = 0;
	for (int i = 1; i <= 100; i++) {
		if (5 * i + p > k)break; cnt++; p += 5 * i;
	}
	cout << min(n, cnt) << endl;
	return 0;
}