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
    int n; cin >> n;
    vector<ll> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    sort(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    priority_queue<ll> have;
    have.push(sum);
    bool ok = true;
    while (!have.empty()) {
      auto cur = have.top();
      have.pop();
      if (cur < a.back()) {
        ok = false;
        break;
      } else if (cur == a.back()) {
        a.pop_back();
      } else {
        have.push(cur / 2);
        have.push((cur + 1) / 2);
      }
    }
    if (ok) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}