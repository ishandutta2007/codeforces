#include <bits/stdc++.h>

using namespace std;

int a[1000001], b[1000001];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	sort(a, a+n);
	sort(b, b+n);
	long long ans = 0;
	for(int i=n-1, j=n-1;i>=0 || j>=0;) {
		if(a[i] > b[j] || j < 0) {
			ans += a[i];
			i--;
		} else {
			j--;
		}
		if(b[j] > a[i] || i < 0) {
			ans -= b[j];
			j--;
		} else {
			i--;
		}
	}
	cout << ans << endl;
}