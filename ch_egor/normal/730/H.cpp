/*






le
toucan
has
arrived*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
string s[107];
int a[107];
bool good[107];
bool check(string s, string t)
{
	if (s.length() != t.length()) return false;
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] != t[i] && s[i] != '?' && t[i] != '?') return false;
	}
	return true;
}
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
		good[a[i]] = true;
	}
	int len = (int)s[a[1]].length();
	for (int i = 2; i <= m; i++)
	{
		if ((int)s[a[i]].length() != len)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	string p;
	for (int i = 0; i < len; i++)
	{
		char go = s[a[1]][i];
		for (int j = 1; j <= m; j++)
		{
			if (s[a[j]][i] != go)
			{
				go = '?';
			}
		}
		p += go;
	}
	for (int i = 1; i <= n; i++)
	{
		if (check(s[i], p) != good[i])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	cout << p << endl;
	return 0;
}