#include <iostream>
#include <vector>

using namespace std;

const int N = (int)3e5 + 5;

vector <int> a[N];
bool unread[N] = {0};

int main()
{
	int n, q, qt, x;
	cin >> n >> q;

	int curTime = 1, ans = 0, maxTime = 0;

	for (int i = 0; i < q; ++i)
	{
		cin >> qt >> x;

		if (qt == 1)
		{
			a[x].push_back(curTime);
			unread[curTime] = true;
			++curTime;
			++ans;
		}

		else if (qt == 2)
		{
			for (vector <int>::iterator i = a[x].begin(); i != a[x].end(); ++i)
			{
				if (*i > maxTime and unread[*i])
				{
					--ans;
					unread[*i] = false;
				}
			}

			a[x].clear();
		}

		else
		{
			if (x > maxTime)
			{
				for (int i = maxTime + 1; i <= x; ++i)
				{
					if (unread[i])
					{
						unread[i] = false;
						--ans;
					}
				}

				maxTime = x;
			}
		}

		cout << ans << '\n';
	}
}