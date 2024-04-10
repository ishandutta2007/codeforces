#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> v;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < n; ++i)
	{
		if (v[i].length() <= 10)
			cout << v[i] << endl;
		else
			cout << v[i][0] << v[i].size() - 2 << v[i][v[i].size() - 1]<<endl;
	}

	return 0;
}