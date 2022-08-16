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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e2 + 10;

int a[N];
bool seen[N] = {0};

int main()
{
	int n;
	cin >> n;
	int ctr = 0, sum = 0, b;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (!seen[a[i]]) {
			++ctr;
			seen[a[i]] = true;
		}
		if (a[i] == a[1]) {
			++sum;
		}
		else {
			--sum;
			b = a[i];
		}
	}
	if (ctr == 2 and !sum) {
		cout << "YES\n" << a[1] << ' ' << b;
	}
	else {
		cout << "NO";
	}
}