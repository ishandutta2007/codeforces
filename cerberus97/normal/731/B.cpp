#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

int main()
{
	int n, a[N];
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}



	for (int i = 0; i < n; ++i)
	{
		if (i+1 < n and a[i] % 2)
		{
			if (a[i+1] > 0)
			{
				--a[i];
				--a[i+1];
			}
		}

		if (a[i] % 2)
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
}