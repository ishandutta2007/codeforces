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

const int N = 1e5 + 10;

int ctr[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		ctr[x]++;
	}

	bool ans = false;
	for (int i = 1; i < N; ++i) {
		if (ctr[i] % 2 == 1) {
			ans = true;
			break;
		}
	}

	if (ans) {
		cout << "Conan";
	} else {
		cout << "Agasa";
	}
}