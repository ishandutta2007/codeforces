#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define SIZE 150228
#define pint pair<int, int>
#define mp make_pair

int n, k, q;
pint res[10];
int t[SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++)
		cin >> t[i];
	int type, num;
	for (int i = 0; i < 10; i++)
	{
		res[i].first = -1;
		res[i].second = -1;
	}
	for (int i = 0; i < q; i++)
	{
		cin >> type >> num;
		if (type == 1)
		{
			int pos = -1;
			for (int j = 0; j < k; j++)
			{
				if (res[j].first < t[num - 1])
				{
					pos = j;
					break;
				}
			}
			if (pos != -1)
			{
				for (int j = k - 1; j > pos; j--)
					res[j] = res[j - 1];
				res[pos] = mp(t[num - 1], num - 1);
			}
		}
		else
		{
			bool f = false;
			for (int j = 0; j < k; j++)
			{
				if (res[j].second == num - 1)
				{
					cout << "YES" << endl;
					f = true;
					break;
				}
			}
			if (!f)
				cout << "NO" << endl;
		}
	}
	return 0;
}