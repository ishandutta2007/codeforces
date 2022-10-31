#include <bits/stdc++.h>
using namespace std;
long long n, m, k, s, h;
int main()
{
	cin >> n >> m >> k;
	if (k < n)
	{
		cout << k + 1 << " " << 1 << endl;
		return 0;
	}
	s = k - n + 1, m--;
	h = (s - 1) / m + 1;
	if (h % 2 == 1) cout << n + 1 - h << " " << 1 + s % (2 * m) << endl;
	else cout << n + 1 - h << " " << m + 2 - (s - m) % (2 * m) << endl;
	return 0;
}