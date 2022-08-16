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

const int N = 1e5 + 5;

int main()
{
	string s;
	cin >> s;

	char cur = 'a';
	for (auto &i : s)
	{
		if (i > cur)
		{
			cout << "NO";
			return 0;
		}

		cur = max(cur, char(i + 1));
	}

	cout << "YES\n";
}