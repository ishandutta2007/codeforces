#include<bits/stdc++.h>
using namespace std;

void Main()
{
	int n; vector <int> a, b, tog;
	cin >> n;
	a.resize(n), b.resize(n), tog.resize(2*n+1);
	for(int i=0;i<n;i++) cin >> a[i], tog[a[i]] = i;
	for(int i=0;i<n;i++) cin >> b[i], tog[b[i]] = i;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 2*n-1;
	int Min = n;
	for (int i=0;i<n;i++)
		Min = min(Min, tog[a[i]]),
		ans = min(ans, tog[b[i]] + Min);
	cout << ans << endl;
}

int main()
{
	int T; cin >> T;
	while(T --) Main();
	return 0;
}