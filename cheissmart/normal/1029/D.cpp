#include <bits/stdc++.h>

using namespace std;

int a[200001], m[11][200001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	int p10[11]={1};		
	for(int j=1;j<=10;j++)
		p10[j]=10LL*p10[j-1]%k;
	for(int i=0;i<n;i++)
		for (int j = 1; j <= 10; j++)
			m[j][i]= a[i] * 1LL * p10[j] % k;
	for(int j = 1; j <= 10; j++)
		sort(m[j], m[j]+n); 
	long long ans = 0;
	for(int i=0;i<n;i++) {
		if((1ll * a[i] * p10[to_string(a[i]).size()] + a[i]) % k == 0)
			ans--;
		int* v = m[to_string(a[i]).size()];
		int b = (-a[i] % k + k) % k;
		ans += upper_bound(v, v+n, b) - lower_bound(v, v+n, b);
	} 
	cout << ans << endl;
}