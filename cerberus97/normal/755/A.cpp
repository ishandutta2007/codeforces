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

const int N = 1e5 + 5;

int main()
{
	int n;
	cin >> n;

	for (int m = 1; m <= 1e3; ++m)
	{
		int num = n*m + 1, sq = sqrt(num);

		for (int j = 2; j <= sq; ++j)
		{
			if (num % j == 0)
			{
				cout << m;
				return 0;
			}
		}
	}	
}