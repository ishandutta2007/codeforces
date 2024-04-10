#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
	string s;
	vector<int> v;
	cin >> s;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] != '+')
			v.push_back(s[i] - 48);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; ++i)
	{
		cout << v[i] << "+";
	}
	cout << v[v.size() - 1];
	return 0;
}