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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	double ans = 0.0;
	double cc = 1;
	while (cc > 1e-8)
	{
		ans += cc*a/b;
		cc *= (1.0 - a/b)*(1.0 - c/d);
	}
	cout << fixed << setprecision(6) << ans << endl;
	
	return 0;
}