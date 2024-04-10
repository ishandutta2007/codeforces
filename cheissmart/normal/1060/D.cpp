#include <bits/stdc++.h>

using namespace std;

int a[100001], b[100001];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i] >> b[i];
	sort(a, a+n);
	sort(b, b+n);
	long long ans = n;
	for(int i=0;i<n;i++)
		ans += max(a[i], b[i]);
	cout << ans << endl;
}