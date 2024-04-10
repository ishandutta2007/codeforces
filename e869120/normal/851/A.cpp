#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<functional>
using namespace std;
int n, k, t, cnt;
int main() {
	cin >> n >> k >> t;
	for (int i = 1; i <= n; i++) {
		if (i <= t && t < i + k)cnt++;
	}
	cout << cnt << endl;
	return 0;
}