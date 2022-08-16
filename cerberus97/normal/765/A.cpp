/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e2 + 5;

map <string, int> m;
set <int> st;

int main()
{
	int n; string s;
	cin >> n >> s;

	m[s] = 0;
	int x = 1;

	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		string a, b;
		a = s.substr(0, 3);
		b = s.substr(5, 3);
		// cout << a << ' ' << b << endl;

		if (m.find(a) == m.end())
			m[a] = x++;
		if (m.find(b) == m.end())
			m[b] = x++;

		if (m[a] == 0)
			swap(a, b);

		if (st.find(m[a]) == st.end())
			st.insert(m[a]);
		else
			st.erase(m[a]);
	}

	if (st.empty())
		cout << "home\n";
	else
		cout << "contest\n";
}