//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <cassert>
#include <set>
#include <bitset>
#include <iomanip> 
#include <stack>

//#pragma comment(linker, "/STACK:256000000")

using namespace std;

#define make_pair mp
#define push_back pb
#define insert ins
#define erase er

typedef long long int ll;
typedef long double ld;	

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vvi;
typedef vector<ll> vvl;
typedef vector<string> vvs;

const int INF = 1000 * 1000 * 1000 +5;
const ll LLINF = 1ll * INF * INF + 5;
const int MOD = 1000 * 1000 * 1000 + 7;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vvi arr(n);
	int s = 0;
	for (int i = 0 ; i < n; ++i) 
		cin >> arr[i], s += arr[i];

	if (n == 1)
	{
		printf(arr[0] == 0 ? "NO" : "YES");
	}
	else
	{
		printf(s == n - 1 ? "YES" : "NO");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}