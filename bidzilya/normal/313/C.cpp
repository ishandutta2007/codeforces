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

vector<int> d;
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	d.resize(n);
	for (int i=0; i<n; ++i)
		cin >> d[i];
	sort(d.begin(), d.end());
	ll ans = 0, sum = 0;
	for (int i=n-1, sp=1; i >= 0; --i)
	{
		sum += d[i];
		if (n-i == sp)
		{
			sp *= 4;
			ans += sum;
		}
	}
	cout << ans << endl;		
	return 0;
}