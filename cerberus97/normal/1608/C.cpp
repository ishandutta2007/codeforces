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
    vector<int> a(n), b(n);
    for (auto& i : a) {
      cin >> i;
    }
    for (auto& i : b) {
      cin >> i;
    }
    vector<int> r1(n), r2(n);
    iota(r1.begin(), r1.end(), 0);
    iota(r2.begin(), r2.end(), 0);
    sort(r1.begin(), r1.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    sort(r2.begin(), r2.end(), [&](int i, int j) {
      return b[i] < b[j];
    });
    vector<int> rank1(n), rank2(n);
    for (int i = 0; i < n; ++i) {
      rank1[r1[i]] = i;
      rank2[r2[i]] = i;
    }
    string ans(n, '0');
    int p1 = n, p2 = n, q1 = n - 1, q2 = n;
    while (q1 < p1 or q2 < p2) {
      if (q1 < p1) {
        for (int i = q1; i < p1; ++i) {
          int id = r1[i];
          ans[id] = '1';
          q2 = min(q2, rank2[id]);
        }
        p1 = q1;
      } else {
        for (int i = q2; i < p2; ++i) {
          int id = r2[i];
          ans[id] = '1';
          q1 = min(q1, rank1[id]);
        }
        p2 = q2;
      }
    }
    cout << ans << '\n';
  }
}