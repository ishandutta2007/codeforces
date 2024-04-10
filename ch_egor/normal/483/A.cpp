#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define int64 long long int

using namespace std;

int n, k;
int start;

int main()
{
	int64 l, r;

	cin >> l >> r;

	if (l & 1ll)
		++l;

	if (r - l < 2)
	{
		cout << -1;
	}
	else
	{
		cout << l << " " << l + 1 << " " << l + 2;
	}
}