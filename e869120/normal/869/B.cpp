#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
long long a, b, c = 1;
int main() {
	cin >> a >> b;
	for (long long i = a + 1; i <= b; i++) {
		c *= i; c %= 10; if (c == 0)break;
	}
	cout << c << endl;
	return 0;
}