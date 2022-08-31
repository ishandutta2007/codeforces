/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int main()
{
	int n;
	cin >> n;
	set <int> s;
	stack <int> st;
	int cur = 1, ans = 0;
	for (int i = 0; i < 2 * n; ++i)
	{
		string str;
		cin >> str;
		if (str[0] == 'a')
		{
			int x;
			cin >> x;
			st.push(x);
			s.insert(x);
		}

		else
		{
			if (!st.empty())
			{
				if (st.top() == cur)
					st.pop();

				else
				{
					while (!st.empty())
						st.pop();

					++ans;
				}
			}

			s.erase(cur);
			++cur;
		}
	}

	cout << ans;
}