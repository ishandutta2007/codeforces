/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    int cnt0 = count(a.begin(), a.end(), 0);
    int cnt1 = n - cnt0;
    int op1 = (n % (k - 1));
    if (op1 == 0) {
      op1 = k - 1;
    }
    --op1;
    if (cnt1 > 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}