/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() do {ios_base::sync_with_stdio(false); cin.tie(0);} while(0)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int main()
{
	fast_cin();
	int n;
	cin >> n;
	while (n--)
	{
		ll a, b;
		cin >> a >> b;
		ll prod = a * b, cb = round(cbrt(prod));
		if (cb * cb * cb == prod and a % cb == 0 and b % cb == 0)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}