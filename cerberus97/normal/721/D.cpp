#include <iostream>
#include <cstdlib>
#include <set>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

ll a[N];
bool neg[N];

int main()
{
	int n, k, x;
	cin >> n >> k >> x;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	bool isNeg = false, isZero = false;

	for (int i = 0; i < n; ++i)
	{
		if (a[i] < 0)
		{
			isNeg = !isNeg;
			neg[i] = true;
		}

		else if (a[i] == 0)
			isZero = true;
	}

	if (isZero)
	{
		isZero = false;

		for (int i = 0; i < n; ++i)
		{
			if (a[i] == 0)
			{
				if (!k)
				{
					isZero = true;
					break;
				}

				--k;

				if (isNeg)
					a[i] += x;

				else
				{
					a[i] -= x;
					neg[i] = true;
					isNeg = true;
				}
			}
		}

		
	}

	set <pll> s;

	for (int i = 0; i < n; ++i)
		s.insert({abs(a[i]), i});

	while (k--)
	{
		pll cur = *(s.begin());
		s.erase(s.begin());

		if (!isNeg)
		{
			if (cur.first < x)
			{
				isNeg = true;

				if (cur.first)
					neg[cur.second] = !neg[cur.second];

				else
					neg[cur.second] = true;
			}

			cur.first = abs(cur.first - x);

			if (neg[cur.second] and cur.first == 0)
				isNeg = true;

			s.insert(cur);
		}

		else
		{
			if (cur.first == 0)
				neg[cur.second] = false;
			
			cur.first += x;
			s.insert(cur);
		}
	}

	set <pll> s2;

	for (auto &i : s)
		s2.insert({i.second, i.first});

	for (auto &i : s2)
	{
		if (neg[i.first])
			cout << -i.second << ' ';

		else
			cout << i.second << ' ';
	}
}