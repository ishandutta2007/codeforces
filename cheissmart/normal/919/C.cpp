#include <bits/stdc++.h>

using namespace std;

int a[2005][2005], b[2005][2005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k, ans = 0;
	char c;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin >> c;
			a[i][j] += a[i][j-1] + (c == '*');
			b[i][j] += b[i-1][j] + (c == '*');
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m-k+1;j++)
			if(a[i][j+k-1] - a[i][j-1] == 0) ans++;
	for(int i=1;i<=n-k+1;i++)
		for(int j=1;j<=m;j++)
			if(b[i+k-1][j] - b[i-1][j] == 0) ans++;
	if(k == 1) ans /= 2;
	cout << ans << endl;
}