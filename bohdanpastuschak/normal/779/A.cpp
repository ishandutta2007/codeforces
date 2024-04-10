#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
#define ll unsigned long long
#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0;
	int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
	int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] == 1) {
			i1++; a1++;
		}
		if (a[i] == 2) {
			i2++; a2++;
		}
		if (a[i] == 3) {
			i3++; a3++;
		}
		if (a[i] == 4) {
			i4++; a4++;
		}
		if (a[i] == 5) {
			i5++; a5++;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
		if (b[i] == 1) {
			i1++; b1++;
		}
		if (b[i] == 2) {
			i2++; b2++;
		}
		if (b[i] == 3) {
			i3++; b3++;
		}
		if (b[i] == 4) {
			i4++; b4++;
		}
		if (b[i] == 5) {
			i5++; b5++;
		}
	}

	if ((i1 % 2 != 0) || (i2 % 2 != 0) || (i3 % 2 != 0) || (i4 % 2 != 0) || (i5 % 2 != 0))
	{
		cout << -1;
		return 0;
	}

	int ans = 0;
	ans += abs(a1 - i1 / 2);
	ans += abs(a2 - i2 / 2);
	ans += abs(a3 - i3 / 2);
	ans += abs(a4 - i4 / 2);
	ans += abs(a5 - i5 / 2);




	cout << ans/2;
	return 0;
}