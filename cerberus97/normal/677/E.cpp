/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 5, D = 8, mod = 1e9 + 7;

int dir[D][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}}; //Clockwise from left to bottom-left
char s[N][N];
int mx[N][N][D] = {0};
double sum[N][N][D] = {0};

ll fastModExp(ll x, ll e, ll m);

int main()
{
	fast_cin();
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> (s[i] + 1);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int d = 0; d < 4; ++d)
			{
				sum[i][j][d] = sum[i + dir[d][0]][j + dir[d][1]][d];
				if (s[i][j] != '0')
				{
					mx[i][j][d] = 1 + mx[i + dir[d][0]][j + dir[d][1]][d];
					sum[i][j][d] += log10(s[i][j] - '0');
				}
			}
		}
	}

	for (int i = n; i >= 1; --i)
	{
		for (int j = n; j >= 1; --j)
		{
			for (int d = 4; d < 8; ++d)
			{
				sum[i][j][d] = sum[i + dir[d][0]][j + dir[d][1]][d];
				if (s[i][j] != '0')
				{
					mx[i][j][d] = 1 + mx[i + dir[d][0]][j + dir[d][1]][d];
					sum[i][j][d] += log10(s[i][j] - '0');
				}
			}
		}
	}

	double best = 0;
	int bestRadius = 1, bestDir = 0;
	pii bestCentre = {1,1};
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int st = 0; st < 2; ++st)
			{
				int r = n;
				for (int k = st; k < D; k += 2)
					r = min(r, mx[i][j][k]);

				if (r)
				{
					double temp = -3*log10(s[i][j]-'0');
					for (int k = st; k < D; k += 2)
						temp += sum[i][j][k] - sum[i + r*dir[k][0]][j + r*dir[k][1]][k];

					if (temp > best)
					{
						best = temp;
						bestCentre = {i, j};
						bestRadius = r;
						bestDir = st;
					}
				}
			}
		}
	}

	ll ans = (s[bestCentre.first][bestCentre.second] - '0');
	for (int k = bestDir; k < D; k += 2)
	{
		int i = bestCentre.first, j = bestCentre.second;
		for (int r = 1; r < bestRadius; ++r)
		{
			i += dir[k][0];
			j += dir[k][1];
			ans = (ans * (s[i][j]-'0')) % mod;
		}
	}

	cout << ans;
}	

ll fastModExp(ll x, ll e, ll m)
{
	ll res = 1;
	x %= m;

	while (e)
	{
		if (e % 2)
			res = (res * x) % mod;

		e /= 2;
		x = (x * x) % mod;
	}

	return res;
}