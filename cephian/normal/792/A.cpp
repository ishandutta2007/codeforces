#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200005;
int a[N];

int main() {
	int n;
	cin >> n;
	for(int i =0; i < n; ++i)
		cin >> a[i];
	sort(a,a+n);
	int mn = 0x7fffffff;
	for(int i = 1; i < n; ++i) {
		mn = min(mn,abs(a[i]-a[i-1]));
	}
	int ans = 0;
	for(int i = 1; i < n; ++i) {
		ans += abs(a[i]-a[i-1]) == mn;
	}
	cout << mn << " " << ans << "\n";
	return 0;
}