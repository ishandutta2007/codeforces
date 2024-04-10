#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
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
typedef pair<ll, int> pii;

const int MAX_INT = (1 << 31)-1;
const ll MAX_LL = (1LL << 63)-1;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	if (s[0] != '-')
		cout << s << endl;
	else
	{

		if (s[s.length()-1] > s[s.length()-2])
			s.erase(s.begin()+s.length()-1);
		else
			s.erase(s.begin()+s.length()-2);
		cout << atoi(s.c_str()) << endl;
	}
	return 0;
}