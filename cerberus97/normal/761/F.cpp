/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 5, K = 3e5 + 5, A = 26;
const ll INF = 1e18;

int a1[K], b1[K], a2[K], b2[K], val[K], temp1[A], temp2[A], ctr[N][N][A] = {0};
ll sum[N][N][A] = {0}, base[N][N] = {0};
char s[N][N], ch[K];

ll get_base(int x1, int y1, int x2, int y2);
ll get_sum(int x1, int y1, int x2, int y2, int v);

int main()
{
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;	

	for (int i = 1; i <= n; ++i)
		cin >> (s[i] + 1);

	for (int i = 1; i <= k; ++i)
	{
		cin >> a1[i] >> b1[i] >> a2[i] >> b2[i] >> ch[i];
		val[i] = ch[i] - 'a';

		ctr[a2[i]][b2[i]][val[i]]++;
		ctr[a2[i]][b1[i] - 1][val[i]]--;
		ctr[a1[i] - 1][b2[i]][val[i]]--;
		ctr[a1[i] - 1][b1[i] - 1][val[i]]++;
	}

	// cout << val[1];

	for (int v = 0; v < A; ++v)
		for (int i = n; i >= 0; --i)
			for (int j = m; j >= 0; --j)
				ctr[i][j][v] += ctr[i + 1][j][v] + ctr[i][j + 1][v] - ctr[i + 1][j + 1][v];

	// cout << ctr[1][1][1] << endl;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			int temp = k;
			for (int v = 0; v < A; ++v)
				temp -= ctr[i][j][v];

			ctr[i][j][s[i][j] - 'a'] += temp;

			temp1[0] = temp2[0] = 0;
			for (int v = 1; v < A; ++v)
			{
				temp1[v] = temp1[v - 1] + ctr[i][j][v - 1];
				temp2[v] = temp2[v - 1] + (v - 1) * ctr[i][j][v - 1];
				sum[i][j][v] += v*temp1[v] - temp2[v];
			}

			temp1[A - 1] = 0, temp2[A - 1] = 0;
			for (int v = A - 2; v >= 0; --v)
			{
				temp1[v] = temp1[v + 1] + (v + 1) * ctr[i][j][v + 1];
				temp2[v] = temp2[v + 1] + ctr[i][j][v + 1];
				sum[i][j][v] += temp1[v] - v*temp2[v];
			}

			base[i][j] = sum[i][j][s[i][j] - 'a'] + base[i - 1][j] + base[i][j - 1] - base[i - 1][j - 1];
			for (int v = 0; v < A; ++v)
				sum[i][j][v] += sum[i - 1][j][v] + sum[i][j - 1][v] - sum[i - 1][j - 1][v];
		}
	}

	// cout << ctr[1][1][1] << endl;

	ll ans = INF;
	for (int i = 1; i <= k; ++i)
	{
		ll temp = base[n][m] - get_base(a1[i], b1[i], a2[i], b2[i]) + get_sum(a1[i], b1[i], a2[i], b2[i], val[i]);
		ans = min(ans, temp);
	}

	cout << ans;
}

ll get_base(int x1, int y1, int x2, int y2)
{
	return base[x2][y2] - base[x2][y1 - 1] - base[x1 - 1][y2] + base[x1 - 1][y1 - 1];
}

ll get_sum(int x1, int y1, int x2, int y2, int v)
{
	return sum[x2][y2][v] - sum[x2][y1 - 1][v] - sum[x1 - 1][y2][v] + sum[x1 - 1][y1 - 1][v];
}