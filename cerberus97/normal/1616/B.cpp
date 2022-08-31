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
    int n; string s;
    cin >> n >> s;
    vector<int> check = {1, n};
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] < s[i + 1]) {
        check.pb(i + 1);
        break;
      }
    }
    vector<string> cand;
    for (auto& k : check) {
      string tmp = s.substr(0, k);
      string cpy = tmp;
      reverse(cpy.begin(), cpy.end());
      cand.pb(tmp + cpy);
    }
    sort(cand.begin(), cand.end());
    cout << cand[0] << '\n';
  }
}