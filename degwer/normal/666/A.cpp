#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
using namespace std;
set<string>bef[11000];
int main()
{
	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	set<string>ans;
	bef[0].insert("");
	for (int i = 0; i < str.size() - 2; i++)
	{
		string z;
		z.push_back(str[i]);
		z.push_back(str[i + 1]);
		if (bef[i].size() == 1)
		{
			set<string>::iterator it = bef[i].begin();
			if ((*it) != z)
			{
				if (str.size() - (i + 1) > 5)ans.insert(z);
				bef[i + 2].insert(z);
			}
		}
		else if (bef[i].size() >= 2)
		{
			if (str.size() - (i + 1) > 5)ans.insert(z);
			bef[i + 2].insert(z);
		}
		z.push_back(str[i + 2]);
		if (bef[i].size() == 1)
		{
			set<string>::iterator it = bef[i].begin();
			if ((*it) != z)
			{
				if (str.size() - (i + 2) > 5)ans.insert(z);
				bef[i + 3].insert(z);
			}
		}
		else if (bef[i].size() >= 2)
		{
			if (str.size() - (i + 2) > 5)ans.insert(z);
			bef[i + 3].insert(z);
		}
	}
	vector<string>r;
	set<string>::iterator it = ans.begin();
	for (;;)
	{
		if (it == ans.end())break;
		string z = *it;
		reverse(z.begin(), z.end());
		r.push_back(z);
		it++;
	}
	sort(r.begin(), r.end());
	printf("%d\n", r.size());
	for (int i = 0; i < r.size(); i++)cout << r[i] << endl;
}