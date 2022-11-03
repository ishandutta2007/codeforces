#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

string s;

int main()
{
	cin >> s;
	for (int i=0; i<s.length()-1; i++)
		if (s[i]=='0')
		{
			for (int j=i+1; j<s.length(); j++)
				cout << s[j];
			return 0;
		}else
			cout << 1;
	return 0;
}