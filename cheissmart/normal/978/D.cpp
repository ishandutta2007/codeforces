#include <bits/stdc++.h>
#define inf 2147483647

using namespace std;

int a[100087];

int main()
{
	int n, ans = inf;
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	if(n == 1) {
		cout << 0 << endl;
		return 0;
	}
	for(int k = a[1] - a[0] - 2; k <= a[1] - a[0] + 2; k++) {
		for(int op = -1; op <= 1; op++) {
			int ct = 0, last = a[0] + op;
			if(op != 0) ct++;
			for(int i=1;i<n;i++, last += k) {
				if(a[i] - last - k > 1 || a[i] - last - k < -1) {
					ct = inf;
					break;
				} else if(a[i] - last != k)
					ct++;
			}
			ans = min(ans, ct);
		}
	}
	cout << (ans == inf ? -1 : ans) << endl;
}