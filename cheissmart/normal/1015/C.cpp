#include <bits/stdc++.h>

using namespace std;

int a[100005], b[100005], c[100005];

int main()
{
	int n, m;
	long long no = 0, sum = 0;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> a[i] >> b[i];
		c[i] = a[i] - b[i];
		sum += a[i];
		no += b[i];
	}
	if(no > m) {
		cout << "-1" << endl;
		return 0;
	}
	sort(c, c+n);
	int ans = 0;
	for(int i=n-1;i>=0 && sum > m;i--) {
		sum -= c[i];
		ans++;
	}
	cout << ans << endl;
}