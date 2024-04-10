#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

bool is_prime(int x)
{
	for (int i = 2; i*i <= x; ++i)
	{
		if (x % i == 0)
		{
			return false;
		}
	}

	return true;
}

int arr[4] = { 4, 9, 25, 49 };
int gg[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int cnt_yes = 0;

	string answer;

	//for (int i = 2; i <= 100; ++i)
	//{
	//	if (is_prime(i))
	//	{
	//		cout << i << ", ";
	//	}
	//}

	for (int i = 0; i < 4; ++i)
	{
		cout << arr[i] << endl;
		fflush(stdout);

		cin >> answer;
		if (answer == "yes")
		{
			cout << "composite\n";
			fflush(stdout);
			return 0;
		}
	}

	for (int i = 0; i < 16; ++i)
	{
		cout << gg[i] << endl;
		fflush(stdout);

		cin >> answer;

		if (answer == "yes")
		{
			++cnt_yes;
		}

	}

	if (cnt_yes > 1)
	{
		cout << "composite\n";
		fflush(stdout);
	}
	else
	{
		cout << "prime\n";
		fflush(stdout);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}