#include <iostream>
#define inf 1e9+5

using namespace std;

int a[300005], b[300005];

int main()
{
	int n, mx1 = -inf, mn1 = inf, mx2 = -inf, mn2 = inf, x, y;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i] >> b[i];
		if(a[i] > mx1 || (a[i] == mx1 && b[i] < mn1)) {
			mx1 = a[i];
			mn1 = b[i];
			x = i;
		}
		if(b[i] < mn2 || (b[i] == mn2 && b[i] > mx2)) {
			mx2 = a[i];
			mn2 = b[i];
			y = i;
		}
	}
	int l1, l2, mn = inf, mx = -inf;
	for(int i=0;i<n;i++) {
		if(i != x) {
			mx = max(mx, a[i]);
			mn = min(mn, b[i]);
		}
	}
	l1 = max(0, mn - mx);
	mn = inf, mx = -inf;
	for(int i=0;i<n;i++) {
		if(i != y) {
			mx = max(mx, a[i]);
			mn = min(mn, b[i]);
		}
	}
	l2 = max(0, mn - mx);
	cout << max(l1, l2) << endl;
}