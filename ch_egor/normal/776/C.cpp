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

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int n;
int64 k;
int arr[228228];
map<int64, int64> cnt1;
vector<int64> kk;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%lld", &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	cnt1[0] = 1;

	if (k == 1)
	{
		kk.push_back(1);
	}
	else if (k == -1)
	{
		kk.push_back(1);
		kk.push_back(-1);
	}
	else
	{
		kk.push_back(1);
		int64 pt = k;
		while (abs(pt) < 1000000000000000ll)
		{
			//cout << pt << endl;
			kk.push_back(pt);
			pt *= k;
		}
	}

	int64 ans = 0;
	int64 sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < (int)kk.size(); ++j)
		{
			ans += cnt1[sum - kk[j] + arr[i]];
		}
		sum += arr[i];
		++cnt1[sum];
	}

	cout << ans;

	fclose(stdin);
	fclose(stdout);

	return 0;
}