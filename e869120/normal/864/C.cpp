#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
long long a, b, f, k, D, c = 0, ret = 0; vector<long long>E;
int main() {
	cin >> a >> b >> f >> k; D = b;
	E.push_back(0);
	for (long long i = 0; i < k; i++) {
		long long C = 1LL * i*a + f; if (i % 2 == 1)C += (a - f) - f;
		E.push_back(C);
	}
	E.push_back(k*a);
	for (int i = 0; i < E.size() - 1; i++) {
		if (E[i + 1] - E[i] > b) { b = D; ret++; }
		b -= (E[i + 1] - E[i]); if (b < 0) { cout << "-1" << endl; return 0; }
	}
	cout << ret << endl;
	return 0;
}