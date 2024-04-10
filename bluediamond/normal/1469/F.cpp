#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool reachable(vector<int> lens, int depth, int wanted_value) {
  vector<ll> adding(depth + 2, 0LL);
  ll per_step = 0;
  ll used = 0;
  ll have = 1;
  int ptr = 0;
  ll sum = 0;
  sum++;
  int root_depth = 0;

  while (sum < wanted_value) {
    if (ptr >= (int) lens.size()) return 0;
    while (root_depth <= depth && used == have) {
      root_depth++;
      per_step += adding[root_depth];
      assert(per_step >= 0);
      have += per_step;
    }
    if (root_depth > depth) return 0;
    used++;
    sum--;
    int l = lens[ptr++];
    if (l % 2 == 1) {
      /// l = 3 => +2, +2
      /// l = 5 => +2, +2, +3, +3
      int low = 2, r = min(depth - root_depth, l / 2 + 1);
      if (low <= r) {
        adding[root_depth + low] += 2;
        adding[root_depth + r + 1] -= 2;
        sum += 2 * (r - low + 1);
      }
    } else {
      /// l = 2 => +2
      /// l = 4 => +2 +2 +3
      int low = 2, r = min(depth - root_depth, l / 2);
      if (low <= r) {
        adding[root_depth + low] += 2;
        adding[root_depth + r + 1] -= 2;
        sum += 2 * (r - low + 1);
      }
      if (root_depth + l / 2 + 1 <= depth) {
        adding[root_depth + l / 2 + 1] += 1;
        adding[root_depth + l / 2 + 2] -= 1;
        sum++;
      }
    }
  }

  return 1;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int n;
  ll k;
  cin >> n >> k;
  vector<int> lens(n);
  for (auto &l : lens) {
    cin >> l;
  }

  sort(lens.rbegin(), lens.rend());

  if (accumulate(lens.begin(), lens.end(), 0LL) - 2 * n + 1LL < k) {
    cout << "-1\n";
    exit(0);
  }

  int low = 0, high = (int) 1e6, sol = -1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (reachable(lens, mid, k)) {
      sol = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  assert(sol != -1);
  cout << sol << "\n";
}