#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 222222;
int n, m, a[maxN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		vector<int> l, r;
		for (int j = 0; j < i; j++)
			if (s[j] == '(')
				l.push_back(j + 1);
		for (int j = i; j < n; j++)
			if (s[j] == ')')
				r.push_back(j + 1);
		if (l.size() == r.size() && l.size() > 0)
		{
			cout << 1 << endl;
			cout << l.size() + r.size() << endl;
			for (auto x : l)
				cout << x << " ";
			for (auto x : r)
				cout << x << " ";
			cout << endl;
			return 0;
		}
	}
	cout << 0 << endl;
}