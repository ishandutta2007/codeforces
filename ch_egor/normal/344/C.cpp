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

int64 arr[3];
int64 answer[3];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	//for (int i = 0; i < 3; ++i) cin >> arr[i];
	//
	//if (arr[0] > arr[1] && arr[0] > arr[2])
	//{
	//	if (arr[1] + arr[2] < arr[0] || (arr[1] + arr[2] - arr[0]) % 2 == 1)
	//	{
	//		cout << "Impossible";
	//	}
	//	else
	//	{

	//	}
	//}

	int64 a, b;

	cin >> a >> b;

	int64 c, answer = 0;

	while (b != 0)
	{
		answer += a / b;
		c = a;
		a = b;
		b = c % b;
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}