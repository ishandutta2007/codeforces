#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m, c, a[MAXN], b[MAXN], p[MAXN], g[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i], p[i + 1] = (p[i] + b[i]) % c;

	for (int i = 0; i + m <= n; i++)
		g[i]++, g[i + m]--;
	int sm = 0;
	for (int i = 0; i < n; i++){
		sm += g[i];
		int pos = m-1;
		if (i < m - 1)
			pos -= (m - 1) - i;
		a[i] = (a[i] + (p[pos + 1] - p[pos + 1 - sm] + c)) % c;
	}
		
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}