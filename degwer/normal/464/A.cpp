#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
string ans;
char gen;
string beg;
void dfs(string s, int t, bool f)
{
	if (ans != "")return;
	if (t == beg.size())
	{
		if (!f)ans = s;
		return;
	}
	char b = beg[t];
	if (!f)b = 'a';
	for (char z = b; z <= gen; z++)
	{
		if (s.size() >= 1)
		{
			if (s[s.size() - 1] == z)continue;
		}
		if (s.size() >= 2)
		{
			if (s[s.size() - 2] == z)continue;
		}
		s.push_back(z);
		dfs(s, t + 1, f&(z == beg[t]));
		s.pop_back();
	}
}
int main()
{
	int len, g;
	scanf("%d%d", &len, &g);
	gen = g + 'a' - 1;
	cin >> beg;
	dfs("", 0, true);
	if (ans == "")cout << "NO" << endl;
	else cout << ans << endl;
}