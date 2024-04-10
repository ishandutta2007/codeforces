#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>
#include <unordered_map>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX_N = 200 * 1000 + 5;

int n;
map<string, vector<string> >arr;
map<string, set<string> > arr1;
char st[432];

vector<vector<string> > answer;
string host, lin;

struct point
{
	string host;
	vector<string> ll;

	point(string _host, vector<string> _ll)
	{
		host = _host;
		ll = _ll;
	}
};

bool operator< (const point &a, const point &b)
{
	bool good = true;
	for (int i = 0; i < a.ll.size(); ++i)
	{
		if (i == b.ll.size())
		{
			bool gg = true;
			for (int j = 0; j < b.ll.size(); ++j)
			{
				if (a.ll[j] != b.ll[j])
				{
					gg = false;
					break;
				}
			}

			if (gg)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		if (a.ll[i] > b.ll[i])
		{
			return false;
		}
	}

	if (a.ll.size() == b.ll.size())
	{
		bool gg = true;
		for (int j = 0; j < b.ll.size(); ++j)
		{
			if (a.ll[j] != b.ll[j])
			{
				gg = false;
				break;
			}
		}

		if (gg)
		{
			return false;
		}
	}

	return true;
}

unordered_map<string, vector<string> > ans;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	int sz;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", st);
		sz = strlen(st);

		host = "http://";
		lin = "";
		for (int i = 7; i < sz; ++i)
		{
			if (st[i] != '/')
			{
				host += st[i];
			}
			else
			{
				for (int j = i; j < sz; ++j)
				{
					lin += st[j];
				}
				break;
			}
		}

		if (arr1[host].count(lin) == 0)
		{
			arr[host].push_back(lin);
			arr1[host].insert(lin);
		}
	}

	string kk;
	for (auto it = arr.begin(); it != arr.end(); ++it)
	{
		sort(it->second.begin(), it->second.end());
		kk = "";
		for (int i = 0; i < it->second.size(); ++i)
		{
			kk += "$" + it->second[i];
		}
		ans[kk].push_back(it->first);
	}

	int cnt = 0;
	for (auto it = ans.begin(); it != ans.end(); ++it)
	{
		if (it->second.size() > 1) ++cnt;
	}

	printf("%d\n", cnt);

	for (auto it = ans.begin(); it != ans.end(); ++it)
	{
		if (it->second.size() > 1)
		{
			for (int i = 0; i < it->second.size(); ++i)
			{
				cout << it->second[i] << " ";
			}
			cout << "\n";
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}