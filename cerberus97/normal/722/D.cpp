#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

set <ll, greater <ll> > ans;

int main()
{
	int n, a;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		ans.insert(a);
	}

	bool flag = true;

	while (flag)
	{
		flag = false;

		int cur = *(ans.begin());

		while (cur > 1)
		{
			cur /= 2;

			if (ans.find(cur) == ans.end())
			{
				ans.erase(ans.begin());
				ans.insert(cur);
				flag = true;
				break;
			}
		}
	}

	for (auto &i : ans)
		cout << i << ' ';
}