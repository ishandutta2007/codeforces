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

int main()
{
	string s;
	cin >> s;
	
	if (s[0] >= 'a') s[0] -= 32;
	
	cout << s;
	return 0;
}