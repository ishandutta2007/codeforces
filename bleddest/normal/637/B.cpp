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
	int n;
	cin >> n;
	vector<string> input(n);
	for (int i = 0; i < n; i++)
		cin >> input[i];
	set<string> used;
	for (int i = n - 1; i >= 0; i--)
		if (used.count(input[i]) == 0)
		{
			cout << input[i] << endl;
			used.insert(input[i]);
		}
}