#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string sa, sb;
	cin >> sa >> sb;
	sort(sa.begin(), sa.end());
	sort(sb.begin(), sb.end());
	reverse(sb.begin(), sb.end());
	int num = sa.size();
	string ans;
	int t = 0;
	int p1 = 0, p2 = 0;
	bool f = false;
	for (int i = 0; i < num; i++)
	{
		if ((!f) && sa[p1] >= sb[p2])
		{
			if ((num - i) % 2 == 0)t = 1 - t;
			f = true;
		}
		if (t == 0)ans.push_back(sa[p1++]);
		else ans.push_back(sb[p2++]);
		t = 1 - t;
	}
	cout << ans << endl;
}