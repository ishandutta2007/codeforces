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

const int N = 2e3 + 10;

ll f(ll n) {
    if (!n) {
        return 0;
    } else {
        return n + ((n - 1) * (n - 2)) / 2 + f(n - 1);
    }
}

int main() {
	int n;
	cin >> n;
	cout << f(n) << endl;
}