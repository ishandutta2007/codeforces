#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 7;
const int L = (int) 1e6 + 7;
int n, k, a[N], lproc[L];
bool deja[L];
vector<int> inds[L];

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (inds[a[i] - a[j]].size() > 10) continue;
      inds[a[i] - a[j]].push_back(a[i]);
      inds[a[i] - a[j]].push_back(a[j]);
    }
  }

  for (int x = 1; x < L; x++) {
    if (inds[x].empty()) {
      continue;
    }
  }

  for (int x = 1; x < L; x++) {
    /**
    vreau sa gasesc grupuri de lungime >= 2 de numere care au restul
    egal la impartirea cu x
    => toate diferentele lor sunt divi cu x => dif intre doua e multiplu de x
    **/
    int cnt_deja = 0;
    vector<int> vals;
    for (int multiple = x; multiple < L && cnt_deja <= k; multiple += x) {
      for (auto &val : inds[multiple]) {
        if (lproc[val] == x) {
          continue;
        }
        lproc[val] = x;
        if (deja[val % x] == 0) {
          deja[val % x] = 1;
          vals.push_back(val % x);
        } else {
          cnt_deja++;
          if (cnt_deja > k) {
            break;
          }
        }
      }
    }
    if (cnt_deja <= k) {
      cout << x << "\n";
      exit(0);
    }
    for (auto &val : vals) {
      deja[val % x] = 0;
    }
  }
  assert(0);



  return 0;
}