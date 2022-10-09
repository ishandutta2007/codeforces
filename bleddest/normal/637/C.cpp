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

int distance(int a, int b)
{
	int ans = 0;
	for (int i = 0; i < 6; i++)
	{
		if (a % 10 != b % 10)
			ans++;
		a /= 10;
		b /= 10;
	}
	return ans;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	vector<int> code(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &code[i]);
	int answer = 13;
	for (int i = 0; i + 1 < n; i++)
		for (int j = i + 1; j < n; j++)
			answer = min(answer, distance(code[i], code[j]));
	printf("%d\n", (answer - 1) / 2);
}