/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include "iomanip"
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int main()
{
	int n, h;
	cin >> n >> h;

	double a = double(h) / (2 * n);
	for (int i = 1; i < n; ++i)
	{
		cout << fixed << setprecision(7) << sqrt(2 * h * i * a) << ' ';
	}	
}