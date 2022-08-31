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

void op(string& s, int i, vector<int>& cnt, int& sum);

int main() {
  fast_cin();
  int n, q; string s;
  cin >> n >> q >> s;
  vector<int> cnt(n, 0);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    op(s, i, cnt, sum);
  }
  while (q--) {
    int i; char c;
    cin >> i >> c;
    --i;
    s[i] = c;
    for (int j = i - 2; j <= i; ++j) {
      op(s, j, cnt, sum);
    }
    cout << sum << '\n';
  }
}

void op(string& s, int i, vector<int>& cnt, int& sum) {
  int n = s.length();
  if (i < 0 or i + 2 >= n) {
    return;
  }
  sum -= cnt[i];
  cnt[i] = (s[i] == 'a' and s[i + 1] == 'b' and s[i + 2] == 'c');
  sum += cnt[i];
}