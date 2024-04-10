#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>

using namespace std;

const long long INFLL = 1e18;

set<int> ans_idx;
set<int> cur_idx;

string s;
string cur_ans = "}";
string cur, cur1;
int n, m;

bool check(int i)
{
	if (ans_idx.count(i))
		return true;
	auto it = ans_idx.lower_bound(i);
	int lf = -1;
	int rg = n;
	if (it != ans_idx.end())
		rg = (*it);
	if (it != ans_idx.begin())
		lf = *(--it);
	return rg - lf <= m;
}

bool closest(int i, int& ans)
{
	ans = n;
	int lf = -1;
	auto it = ans_idx.lower_bound(i);
	if (it != ans_idx.begin())
		lf = *(--it);
	it = cur_idx.upper_bound(lf + m);
	if (it != cur_idx.begin() && *(--it) >= i)
		ans = *it;
	return (lf <= i && i <= ans && ans - lf <= m);
}

void calc(char c)
{
	cur1 = cur;
	for (int i = 0; i < n; i++)
		if (s[i] == c)
			cur_idx.insert(i);
	bool good = true;

	int z = 0;
	for (int i = 0; i + m - 1 < n; i++)
	{
		if (!check(i))
		{
			if (closest(i, z))
			{
				cur1 += s[z];
				ans_idx.insert(z);
			}
			else
				good = false;
		}
	}
	if (good)
		cur_ans = min(cur_ans, cur1);
	for (auto it = cur_idx.begin(); it != cur_idx.end(); ++it)
	{
		ans_idx.insert(*it);
		cur += c;
	}
	cur_idx.clear();
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> m >> s;
	n = s.size();
	for (char i = 'a'; i <= 'z'; i++)
		calc(i);
	cout << cur_ans << endl;
	return 0;
}