#include <iostream>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, INF = 2147483647;

int main()
{
	int n;
	cin >> n;

	int l[N], r[N], tl = 0, tr = 0;

	for (int i = 1; i <= n; ++i)
	{
		cin >> l[i] >> r[i];
		tl += l[i];
		tr += r[i];
	}

	int ans = abs(tl-tr), p = 0;

	for (int i = 1; i <= n; ++i)
	{
		tl += r[i] - l[i];
		tr += l[i] - r[i];
		
		if (abs(tl-tr) > ans)
		{
			ans = abs(tl-tr);
			p = i;
		}

		tl += l[i] - r[i];
		tr += r[i] - l[i];
	}

	cout << p;
}