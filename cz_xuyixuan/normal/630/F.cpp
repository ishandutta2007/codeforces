#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	ios::sync_with_stdio(false);
	long long x; cin >> x;
	long long now = 1, ans = 0;
	for (int i = 1; i <= 4; i++)
		now = now * (x - i + 1) / i;
	for (int i = 5; i <= 7; i++) {
		now = now * (x - i + 1) / i;
		ans += now;
	}
	cout << ans << endl;
	return 0;
}