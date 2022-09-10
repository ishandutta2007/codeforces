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
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 1; i < n; ++i)
	{
		if (s[i] == s[i - 1])
			ans++;
	}






	cout << ans;
	return 0;
}