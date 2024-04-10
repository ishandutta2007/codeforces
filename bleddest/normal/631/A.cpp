#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <limits>
#include <fstream>
#include <algorithm>
#include <string>

long long power(long long n, long long k)
{
	if (k == 1)
		return n;
	else return power(n, k / 2) * power(n, (k + 1) / 2);
}

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> a(n);
	vector<long long> b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	int ans = 0;
	for (int l = 0; l < n; l++)
	{
		int suma = 0, sumb = 0;
		for (int r = l; r < n; r++)
		{
			suma = suma | a[r];
			sumb = sumb | b[r];
		}
		ans = max(ans, suma + sumb);
	}

	cout << ans << endl;
	return 0;
}