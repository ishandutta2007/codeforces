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
#define lf long float
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define pb push_back
using namespace std;
ull middle(ull x) {
	ull ans = 1;
	for (ull i = 1; i < x; i++) {
		ans *= (ull)2;
	}
	return ans;
}
void dfs(ull n, ull k) {
	ull x = middle(n);
	if (x == k) {
		cout << n;
		return;
	}
	if (k < x) {
		dfs(n - 1, k);
	}
	else {
		dfs(n - 1, k - x);
	}
	return;
}

int main() {
	ull n, k;
	cin >> n >> k;
	dfs(n, k);
	return 0;
}