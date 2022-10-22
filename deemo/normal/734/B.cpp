#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e6 + 10;

int a[10];
int ans;

int main(){
	cin >> a[2] >> a[3] >> a[5] >> a[6];
	for (int i = 0; i < MAXN; i++){
		if (min({a[2], a[5], a[6]}) < i)	continue;
		int ret = 0;
		ret = i*256;
		ret += 32 * min(a[2] - i, a[3]);

		ans = max(ans, ret);
	}
	cout << ans << "\n";
	return 0;
}