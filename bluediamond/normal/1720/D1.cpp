#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 3e5 + 7;
const int B = 31;
const int INF = (int) 1e9 + 7;
int n, v[N], best[N], xo[N];

struct Trie {
  Trie* kids[2];
  int best[2];

  Trie() {
    kids[0] = kids[1] = 0;
    best[0] = best[1] = 0;
  }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    Trie* root = new Trie;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      xo[i] = v[i] ^ i;
    }
    {


      for (int i = 0; i < n; i++) {
        Trie* cur = root;
        best[i] = 1;
        int total_mask = 0;
        for (int suf = B - 1; suf >= 0; suf--) {
          total_mask += (1 << suf);
          int what_bit = !!(xo[i] & (1 << suf));
          if (!cur->kids[what_bit]) cur->kids[what_bit] = new Trie;
          assert(cur != cur->kids[what_bit]);
          cur = cur->kids[what_bit];

          what_bit = !(xo[i] & (1 << (suf - 1)));
          Trie* lol = cur;
          if (!lol->kids[what_bit]) {
            lol->kids[what_bit] = new Trie;
          }
          lol = lol->kids[what_bit];
          best[i] = max(best[i], lol->best[!!(i & (1 << (suf - 1)))] + 1);
        }
        cur = root;
        for (int suf = B - 1; suf >= 0; suf--) {
          total_mask += (1 << suf);
          int what_bit = !!(xo[i] & (1 << suf));
          if (!cur->kids[what_bit]) cur->kids[what_bit] = new Trie;
          assert(cur != cur->kids[what_bit]);
          cur = cur->kids[what_bit];

          cur->best[!!(v[i] & (1 << suf))] = max(cur->best[!!(v[i] & (1 << suf))], best[i]);
        }
      }
    }
    cout << *max_element(best, best + n) << "\n";
  }

  return 0;
}