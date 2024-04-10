#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, k;
string arr[55];
string ans[55];

string gen(int num)
{
	string ans = "";
	ans += 'A' + num / 26;
	ans += 'a' + num % 26;

	return ans;
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	cin >> n >> k;
	for (int i = 0; i < n - k + 1; ++i)
	{
		cin >> arr[i];
	}
	
	for (int i = 0; i < k - 1; ++i)
	{
		ans[i] = gen(i);
	}
	
	for (int i = k - 1; i < n; ++i)
	{
		if (arr[i - k + 1] == "NO")
		{
			ans[i] = ans[i - k + 1];
		}
		else
		{
			ans[i] = gen(i);
		}
	}
	
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";

	return 0;
}