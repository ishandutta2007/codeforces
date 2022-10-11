#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <iomanip>
//#include <ctime>
//#include <cmath>

using namespace std;

typedef long long int int64;
typedef long double double80;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	string st1;
	string st2;

	cin >> n;
	cin >> st1;
	cin >> st2;

	int answer = 0;
	int delta;

	for (int i = 0; i < n; ++i)
	{
		delta = abs(st1[i] - st2[i]);

		answer += min(delta, 10 - delta);
	}

	printf("%d", answer);

	fclose(stdin);
	fclose(stdout);

	return 0;
}