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

string s;
vector<int> d;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> s;
	d.resize(s.length());
	d[0] = 0;
	for (int i=1; i<s.length(); ++i)
	{
		d[i] = d[i-1];
		if (s[i] == s[i-1])
			++d[i];
	}
	int m;
	cin >> m;
	for (int i=0; i<m; ++i)
	{
		int l,r;
		cin >> l >> r;
		--l;--r;
		cout << d[r]-d[l] << endl;
	}

	return 0;
}