#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n, k;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= 1000; i++) {
		if ((i*n) % 10 == 0 || (i*n) % 10 == k) { cout << i << endl; break; }
	}
	return 0;
}