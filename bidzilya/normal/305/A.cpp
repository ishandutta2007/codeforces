#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, int> pii;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int c100, c000;
	c100 = c000 = 0;
	int c0x0, c00x, c0xx;
	c0x0 = c00x = c0xx = 0;
	for (int i=0; i<n; ++i)
	{
		int x;
		cin >> x;
		if (x == 100)
			c100 = 1;
		else
		if (x == 0)
			c000 = 1;
		else
		if (x%10 == 0)
			c0x0 = x;
		else
		if (x/10 == 0)
			c00x = x;
		else
			c0xx = x;
	}
	vector<int> ans;
	if (c100)
		ans.push_back(100);
	if (c000)
		ans.push_back(000);
	if (c0x0 && c00x)
	{
		ans.push_back(c0x0);
		ans.push_back(c00x);
	}else
	if (c0xx)
		ans.push_back(c0xx);
	else
	if (c0x0 || c00x)
		ans.push_back(c0x0+c00x);
	cout << ans.size() << endl;
	for (int i=0; i<ans.size(); ++i)
		cout << ans[i] << " ";
	cout << endl;
	
		

	return 0;
}