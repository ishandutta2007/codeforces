#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;
long long a, b, c, d, e[100008];
map<long long, int>M;
int main() {
	cin >> a >> b >> c >> d;
	for (int i = 0; i < d; i++) { scanf("%lld", &e[i]); M[e[i]] = 1; }
	int cnt = 0, cnt2 = 0; long long H = a; bool OK = true;
	while (a <= c && a >= -c) {
		cnt++;
		if (cnt >= 40000) {
			if (cnt2 >= 5000) { cout << "inf" << endl; OK = false; break; }
			else { cout << cnt2 << endl; OK = false; break; }
		}
		if (M[a] == 0)cnt2++;
		a *= b;
	}
	if (OK == true)cout << cnt2 << endl;
	return 0;
}