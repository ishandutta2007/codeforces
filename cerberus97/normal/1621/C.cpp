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

int ask(int i);

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<bool> seen(n + 1, 0);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
      if (seen[i]) {
        continue;
      }
      vector<int> here = {ask(i)};
      while (true) {
        int nxt = ask(i);
        seen[here.back()] = true;
        p[here.back()] = nxt;
        here.pb(nxt);
        if (nxt == here[0]) {
          break;
        }
      }
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i) {
      cout << p[i] << ' ';
    }
    cout << endl;
  }
}

int ask(int i) {
  cout << "? " << i << endl;
  int ans; cin >> ans;
  return ans;
}