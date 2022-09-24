#include<iostream>
#include<math.h>
#include<algorithm>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#define ull unsigned long long
#define ll long long
#define ld long double
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define pb push_back
ull INF = 1e9 + 7;

using namespace std;


bool a[100005];

int main() {
	int cur = 0, ans=0;
	int n, num;
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> num;
		if (!a[num]) cur++;
		else cur--;
		ans = max(ans, cur);
		a[num] = 1;
	}
	cout << ans;
}