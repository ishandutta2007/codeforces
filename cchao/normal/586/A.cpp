#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a[110], ans = 0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		ans += a[i];
		if(i >= 2 and a[i] and !a[i-1] and a[i - 2])
			ans++;
	}
	cout << ans << endl;
		
	return 0;
}