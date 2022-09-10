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
	int n,k;
	cin >> n>>k;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int foo;
		cin >> foo;
		v.push_back(foo);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i] >= v[k - 1]&&v[i] > 0)
			++ans;
		else
			break;
	}
	cout << ans << endl;
	return 0;
}