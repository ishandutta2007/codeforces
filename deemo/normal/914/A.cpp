#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

bool ok(int x) {
	if (x < 0) return true;
	if (x < 2) return false;
	for (int i = 1; i * i <= x; i++)
		if (i * i == x)
			return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin >> n;
	int ans = -1e9;
	while (n--) {
		int x; cin >> x;
		if (ok(x))
			ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}