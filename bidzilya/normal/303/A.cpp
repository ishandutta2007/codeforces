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

const int N = 1e5;

int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	if (n%2 == 0)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i=n-2; i>=0; --i)
		cout << i << " ";
	cout << n-1 << endl;
	for (int i=2; i<n; i += 2)
		cout << i << " ";
	for (int i=1; i<n; i += 2)
		cout << i << " ";
	cout << 0 << endl;
	for (int i=0; i<n; ++i)
		cout << i << " ";
	cout << endl;

	return 0;
}