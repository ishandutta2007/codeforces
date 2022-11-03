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
	int n;
	cin >> n;
	int ans = 0;
	for (int a=1; a<=n; ++a)
		for (int b=a; b<=n; ++b)
		{
			int cc = a*a + b*b;
			int c = sqrt(.0+cc);
			if (c*c == cc && c <= n)
				++ans;
		}
	cout << ans << endl;
	return 0;
}