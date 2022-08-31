/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e2 + 5;

ll a[N];
bool elim[N] = {0};

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i)
		cin >> a[i];

	int cur = 0, last = n - 1;
	for (int i = 0; i < k; ++i)
	{
		ll temp = a[i] % (n - i);
		while (temp)
		{
			cur = (cur + 1) % n;
			if (elim[cur])
				continue;

			--temp;
		}

		elim[cur] = true;
		cout << (cur + 1) << ' ';
		cur = (cur + 1) % n;
		while (elim[cur])
			cur = (cur + 1) % n;
		
		while (elim[last])
			--last;
	}
}