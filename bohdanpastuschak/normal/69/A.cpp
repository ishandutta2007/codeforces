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
#include <map>
using namespace std;
#define ll long long

int main()
{
	int n;
	cin >> n;
	bool b = true;
	vector<int> x(n), y(n), z(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i] >> z[i];
	}
	
	int s = 0,t = 0,r = 0;
	for (int j = 0; j < n; ++j)
	{
		s += x[j];
		t += y[j];
		r += z[j];
	}
	if (t != 0 || r != 0 || s != 0)
		cout << "NO";
	else

	
	
	cout << "YES";
	
	return 0;
}