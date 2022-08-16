#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e3 + 5, INF = 2147483647;

int a[N], ctr[N];

int main()
{
	int n, m;
	cin >> n >> m;

	int ans = n/m, change = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		
		if (a[i] <= m)
			ctr[a[i]]++;
	}

	for (int i = 1; i <= m; ++i)
	{
		change += max(0, ans - ctr[i]);
	}

	int j = 1;

	for (int i = 0; i < n; ++i)
	{
		while (ctr[j] >= ans and j <= m)
			++j;

		if (j > m)
			break;

		if (a[i] <= m and ctr[a[i]] <= ans)
			continue;

		if (a[i] <= m)
			ctr[a[i]]--;

		a[i] = j;
		ctr[j]++;
	}

	//cout << ctr[1] << ' ' << ctr[2] << endl;
	cout << ans << ' ' << change << '\n';

	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
}