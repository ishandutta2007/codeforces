#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	ios::sync_with_stdio(false);
	long long n; cin >> n;
	long long now = 1, ans = 1;
	for (int i = 1; i <= 5; i++)
		now = now * (n + 5 - i) / i;
	ans *= now; now = 1;
	for (int i = 1; i <= 3; i++)
		now = now * (n + 3 - i) / i;
	ans *= now;
	cout << ans << endl;
	return 0;
}