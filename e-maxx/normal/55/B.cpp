#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


long long ans = (long long) 1E18;

char op[3];

void brute (vector<long long> v, int cur) {
	if (cur == 3)
		ans = min (ans, v[0]);
	else
		for (size_t i=0; i<v.size(); ++i)
			for (size_t j=0; j<i; ++j) {
				vector<long long> to = v;
				long long num = (op[cur]=='+') ? v[i]+v[j] : v[i]*v[j];
				to[j] = num;
				to.erase (to.begin() + i);
				brute (to, cur+1);
			}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	vector<long long> a (4);
	for (int i=0; i<4; ++i)
		cin >> a[i];
	for (int i=0; i<3; ++i)
		cin >> op[i];

	brute (a, 0);

	cout << ans;

}