#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int module = 1e9+7;

string s;

int main()
{
	ios_base::sync_with_stdio(0);
//	ifstream cin("input.txt");
	//ofstream cout("output.txt");
	
	getline(cin, s);
	
	for (int i=0; i<s.length(); i++)
	{
		if (s[i] == ' ') continue;
		if (s[i] == '"')
		{
			i++;
			cout << '<';
			while (s[i] != '"')
				cout << s[i++];
			cout << '>';
			cout << endl;
			i++;
		}else
		{
			cout << '<';
			while (i<s.length() && s[i]!=' ' && s[i]!='"')
				cout << s[i++];
			cout << '>';
			cout << endl;
		}
	}
	return 0;
}