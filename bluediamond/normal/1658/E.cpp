#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2000 + 7;
const int INF = (int) 1e9 + 7;
int n, k;
bool act[N][N];
pair<int, int> loc[N * N];

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin >> n >> k;
  k++;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int foo;
      cin >> foo;
      loc[foo] = {i, j};
    }
  }

  int mxa = -INF, mna = +INF;
  int mxb = -INF, mnb = +INF;

  for (int x = n * n; x >= 1; x--) {
    int r = loc[x].first, c = loc[x].second;
    if ((mxa < r + c + k) && (mxb < r - c + k) && (mna > r + c - k) && (mnb > r - c - k)) {
      act[r][c] = 1;
      mxa = max(mxa, r + c);
      mna = min(mna, r + c);
      mxb = max(mxb, r - c);
      mnb = min(mnb, r - c);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (act[i][j] == 1) {
        cout << "M";
      } else {
        cout << "G";
      }
    }
    cout << "\n";
  }

  return 0;
}