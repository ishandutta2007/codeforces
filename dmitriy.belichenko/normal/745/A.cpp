#include <stdio.h>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#include <string>
#define ull unsigned long long
#define lf long float
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define pb push_back
using namespace std;


int main()
{
	ull ans = 0;
	int a[1000];
	string s;
	set<string> p;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		ans++;
		p.insert(s);
		int k = 1;
		s = s.substr(k) + s[0];
	}
	cout << p.size() << endl;
}