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
	int n = s.length();
	int res[4], broken[4] = {0};

	for (int i = 0; i < 4; ++i)
		res[i] = -1;

	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 'R')
			res[0] = i % 4;

		else if (s[i] == 'B')
			res[1] = i % 4;

		else if (s[i] == 'Y')
			res[2] = i % 4;

		else if (s[i] == 'G')
			res[3] = i % 4;

		else
			broken[i % 4]++;
	}

	for (int i = 0; i < 4; ++i)
		cout << broken[res[i]] << ' ';
}