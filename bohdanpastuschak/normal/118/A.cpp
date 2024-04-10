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
	int n = s.length();
	string d = ".";
	int i = 0; 
	while (i < s.length())
	{
		if (s[i] > 64 && s[i] <= 64+26) s[i] += 32;
		if (s[i] == 'A' || s[i] == 'a' || s[i] == 'O' || s[i] == 'o' || s[i] == 'I' || s[i] == 'i' || s[i] == 'U' || s[i] == 'u' || s[i] == 'E' || s[i] == 'e' || s[i] == 'Y' || s[i] == 'y')
			s.erase(i,1);
		else
		{
			s.insert(i, d);
			
			i+=2;
		}
	}

	cout << s;
	return 0;
}