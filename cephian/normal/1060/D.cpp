#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const int N = 1e5+5;
int l[N], r[N], n;


int main() {
	fio;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> l[i] >> r[i];
	sort(l, l+n);
	sort(r, r+n);
	ll ans = n;
	for(int i = 0; i < n; ++i)
		ans += max(l[i], r[i]);
	cout << ans << "\n";
}