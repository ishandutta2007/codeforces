#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct Man
{
	string name;
	int l, r;
	Man():l(-1), r(-1){}
	Man(string name):name(name), l(-1), r(-1){}
};

int n;
map<string, int> mp;
int top = -1;
string s;
int sz = 0;
Man a[200228];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (mp.find(s) == mp.end())
		{
			mp[s] = sz;
			a[sz].name = s;
			if (top != -1)
			{
				a[top].l = sz;
				a[sz].r = top;
			}
			top = sz;
			sz++;
		}
		else
		{
			int pos = mp[s];
			if (top == pos)
				continue;
			if (a[pos].r != -1)
			{
				a[a[pos].l].r = a[pos].r;
				a[a[pos].r].l = a[pos].l;
			}
			else
				a[a[pos].l].r = -1;
			a[pos].l = -1;
			a[pos].r = top;
			a[top].l = pos;
			top = pos;
		}
	}
	while (top != -1)
	{
		cout << a[top].name << endl;
		top = a[top].r;
	}
	return 0;
}