#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	ios::sync_with_stdio(false);
	long long ans = 1, n;
	cin >> n;
	for (int i = 1; i <= 5; i++)
		ans = ans * (n - i + 1);
	for (int i = 1; i <= 5; i++)
		ans = ans * (n - i + 1) / i;
	cout << ans << endl;
	return 0;
}