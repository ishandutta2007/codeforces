#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;


int main()
{
	ios_base::sync_with_stdio(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	
	string s,t;
	getline(cin, s);
	getline(cin, t);

	int c1=0,c2=0;
	for (int i=0; i<s.length(); i++)
		if (s[i]=='1')
			c1++;
	for (int i=0; i<t.length(); i++)
		if (t[i]=='1')
			c2++;
	if (c1%2==1)
		c1++;
	if (c2 > c1)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}