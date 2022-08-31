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
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int main()
{
	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int r1 = 2 * t1 + s * v1, r2 = 2 * t2 + s * v2;
	if (r1 < r2)
		cout << "First\n";
	else if (r1 > r2)
		cout << "Second\n";
	else
		cout << "Friendship\n";
}