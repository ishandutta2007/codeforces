#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
long long b[maxn], bit1[maxn], bit2[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> b[i];
	long long ans = 0;
	for (int i = n; i >= 1; i--) {
		long long x = 0;
		for (int j = i; j >= 1; j -= j & (-j)) x += bit1[j];
		long long y = 0;
		for (int j = i; j >= 1; j -= j & (-j)) y += bit2[j];
		long long rval = x + y * i;
		if (rval < b[i]) {
			int L = min(k, i);
			long long t = (b[i] - rval + L - 1) / L;
			ans += t;
			int st = i - L + 1;
			for (int j = st; j <= n; j += j & (-j)) bit1[j] += t * (-st + 1);
			for (int j = st; j <= n; j += j & (-j)) bit2[j] += t;
		}
	}
	cout << ans << endl;
}