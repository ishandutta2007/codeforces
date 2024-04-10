/*






le
toucan
has
arrived*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		int n;
		cin >> n;
		vector<pair<int, int> >pairs;
		for (int i = 1; i <= n; i += 2)
		{
			int x = i, y = i + 1;
			if (y > n) y = n;
			pairs.push_back(make_pair(x, y));
		}
		for (int i = 0; i < (int)pairs.size(); i++)
		{
			int x = pairs[i].first, y = pairs[i].second;
			if (x == y) continue;
			cout << "? " << x << " " << y << endl;
			char res;
			cin >> res;
			if (res == '>')
			{
				swap(pairs[i].first, pairs[i].second);
			}
		}
		int mn = pairs[0].first, mx = pairs[0].second;
		for (int i = 1; i < (int)pairs.size(); i++)
		{
			int x = pairs[i].first, y = pairs[i].second;
			cout << "? " << x << " " << mn << endl;
			char res;
			cin >> res;
			if (res == '<')
			{
				mn = x;
			}
			cout << "? " << y << " " << mx << endl;
			cin >> res;
			if (res == '>')
			{
				mx = y;
			}
		}
		cout << "! " << mn << " " << mx << endl;
	}
}