#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <int, char> pic;

const int N = 505, INF = 2147483647;

ll a[N], b[N];
bool mark[N];

int main()
{	
	int n, k;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cin >> k;

	for (int i = 0; i < k; ++i)
		cin >> b[i];

	int i = 0;

	for (int j = 0; j < k; ++j)
	{
		ll temp = 0;

		while (i < n and temp < b[j])
		{
			temp += a[i];
			++i;
		}

		if (temp != b[j])
		{
			cout << "NO";
			return 0;
		}

		mark[i] = true;
	}

	if (!mark[n])
	{
		cout << "NO";
		return 0;
	}

	// cout << "YES\n";

	vector <int> group;
	vector <pic> out;
	int offset = 0;

	for (int i = 0; i <= n; ++i)
	{	
		if (!mark[i])
			group.push_back(a[i]);

		else
		{
			// cout << i << ' ' << group.size() << endl;
			int mx = 0, p = 0, l = group.size();
			bool ans = false;

			for (int i = 1; i < l; ++i)
			{
				if (group[i] != group[i-1])
				{
					ans = true;
					break;
				}
			}

			if (l == 1)
				ans = true;

			if (!ans)
			{
				cout << "NO";
				return 0;
			}

			for (int i = 0; i < l; ++i)
			{
				if (group[i] > mx)
				{
					mx = group[i];
					p = i;
				}

				else if (group[i] == mx)
				{
					if (i != 0 and group[i] != group[i-1])
					{
						mx = group[i];
						p = i;
					}

					else if (i != l-1 and group[i] != group[i+1])
					{
						mx = group[i];
						p = i;
					}
				}
			}

			int localOffset = 0, timesL = p;

			if (p != l-1 and group[p] == group[p+1])
			{
				out.push_back({p + 1 + offset - localOffset, 'L'});
				localOffset++;
				timesL--;
			}

			for (int i = 0; i < l-p-1; ++i)
				out.push_back({p + 1 + offset - localOffset, 'R'});

			for (int i = 0; i < timesL; ++i)
			{
				out.push_back({p + 1 + offset - localOffset, 'L'});
				++localOffset;
			}

			offset += 1;
			group.clear();
			group.push_back(a[i]);
		}
	}

	cout << "YES\n";

	for (auto &i : out)
		cout << i.first << ' ' << i.second << '\n';
}