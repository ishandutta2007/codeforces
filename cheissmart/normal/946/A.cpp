#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, ans = 0, t;
	cin >> n;
	while(n--) {
		cin >> t;
		ans += abs(t);
	}
	cout << ans << endl;
}