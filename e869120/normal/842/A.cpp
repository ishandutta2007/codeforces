#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
using namespace std;
long long a, b, c, d, e;
int main() {
	cin >> a >> b >> c >> d >> e;
	for (long long i = c; i <= d; i++) {
		if (a <= i*e && i*e <= b) { cout << "YES" << endl; return 0; }
	}
	cout << "NO" << endl;
	return 0;
}