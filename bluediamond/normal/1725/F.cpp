#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie();
#endif /// ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  const int B = 30;

  int n;
  cin >> n;
  vector<pair<int, int>> segs(n);
  vector<int> memo(B);

  for (auto &it : segs) {
    cin >> it.first >> it.second;
  }

  for (int bit = 0; bit < B; bit++) {
    int mod = (1 << bit);
    int print = 0, bonus = 0;
    vector<pair<int, int>> jmen;
    for (int i = 0; i < n; i++) {
      int l = segs[i].first, r = segs[i].second;
      if (r - l + 1 >= mod) {
        bonus++;
        continue;
      }
      l &= ((1 << bit) - 1);
      r &= ((1 << bit) - 1);
      if (l <= r) {
        jmen.push_back({l, +1});
        jmen.push_back({r + 1, -1});
      } else {
        jmen.push_back({0, +1});
        jmen.push_back({r + 1, -1});
        jmen.push_back({l, +1});
        jmen.push_back({mod, -1});
      }
    }
    sort(jmen.begin(), jmen.end());
    int current = 0, l = 0;
    while (l < (int) jmen.size()) {
      int r = l;
      current += jmen[l].second;
      while (r + 1 < (int) jmen.size() && jmen[r + 1].first == jmen[r].first) {
        current += jmen[++r].second;
      }
      l = r + 1;
      print = max(print, current);
    }
    memo[bit] = print + bonus;
  }
  int q;
  cin >> q;
  for (int iq = 0; iq < q; iq++) {
    int guy;
    cin >> guy;
    int the_bit = -1;
    for (int i= 0; i < B; i++) {
      if (guy & (1 << i)) {
        the_bit = i;
        break;
      }
    }
    cout << memo[the_bit] << "\n";
  }
  return 0;
}