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

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	map<long long, long long> likes;
	long long n;
	scanf("%I64d", &n);
	long long maxlike = 0, maxind = 0;
	for (long long i = 0; i < n; i++)
	{
		long long k;
		scanf("%I64d", &k);
		likes[k]++;
		if (likes[k] > maxlike)
		{
			maxlike = likes[k];
			maxind = k;
		}
	}
	printf("%I64d\n", maxind);
}