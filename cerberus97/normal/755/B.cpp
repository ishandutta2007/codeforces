/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

set <string> st;

int main()
{
	int n, m;
	cin >> n >> m;

	string s;
	for (int i = 0; i < n+m; ++i)
	{
		cin >> s;
		st.insert(s);
	}

	int common = n + m - st.size();
	n -= common;
	m -= common;

	if (common % 2 == 0)
	{
		if (n > m)
			cout << "YES";

		else
			cout << "NO";
	}

	else
	{
		if (m > n)
			cout << "NO";

		else
			cout << "YES";
	}
}