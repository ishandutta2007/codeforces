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

int arr[256];
int arr2[256];
const string gg = "Bulbasaur";
string st;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> st;
	for (int i = 0; i < gg.size(); ++i)
		++arr[gg[i]];
	for (int i = 0; i < st.size(); ++i)
		++arr2[st[i]];
	
	int ans = INF;
	for (int i = 0; i < gg.size(); ++i)
		ans = min(ans, arr2[gg[i]] / arr[gg[i]]);

	cout << ans;

	fclose(stdin);
	fclose(stdout);

	return 0;
}