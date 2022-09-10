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
	string s;
	cin >> s;
	int cou = 0;
	char c = '2';
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == c) cou++;
		else
		{
			cou = 0;
			c = s[i];
		}
		if (cou == 6)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}