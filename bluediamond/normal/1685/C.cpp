#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
const int inf = (int) 1e9 + 7;
int n, a[N], pref[N], value[N];

struct T {
  int x;
  int y;
  int i;
};

bool operator < (T a, T b) {
  return a.x < b.x;
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    {
      string str;
      cin >> n >> str;
      n *= 2;
      assert((int) str.size() == n);
      for (int i = 1; i <= n; i++) {
        char ch = str[i - 1];
        assert(ch == '(' || ch == ')');
        a[i] = ((ch == '(') ? (+1) : (-1));
        pref[i] = pref[i - 1] + a[i];
      }
    }
    if (*min_element(pref + 1, pref + n + 1) == 0) {
      cout << "0\n";
      continue;
    }
    int firstBad = 0, lastBad = 0;
    for (int i = 1; i <= n; i++) {
      if (pref[i] < 0) {
        lastBad = i;
      }
    }
    for (int i = n; i >= 1; i--) {
      if (pref[i] < 0) {
        firstBad = i;
      }
    }
    int lsol = -1, rsol = -1;
    assert(firstBad <= lastBad);

    int allMax = -inf;

    for (int i = firstBad + 1; i < lastBad; i++) {
      allMax = max(allMax, pref[i - 1]);
    }
    for (int i = lastBad; i <= n; i++) {
      value[i] = pref[i - 1];
      if (i > lastBad) {
        value[i] = max(value[i], value[i - 1]);
      }
    }
    vector<T> guys;

    for (int r = lastBad; r <= n; r++) {
      guys.push_back({-pref[r], value[r] - pref[r], r});
    }
    sort(guys.begin(), guys.end());
    int dim = (int) guys.size();
    vector<int> minimum(dim + 1, inf);
    for (int i = 1; i <= dim; i++) {
      minimum[i] = min(minimum[i - 1], guys[i - 1].y);
    }

    for (int l = firstBad; l >= 1; l--) {
      allMax = max(allMax, pref[l - 1]);

      int valx = pref[l - 1] - allMax;
      int valy = pref[l - 1];

      int low = 0, high = dim - 1, until = -1;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (guys[mid].x <= valx) {
          until = mid;
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }

      if (minimum[until + 1] <= valy) {
        for (int p = 0; p <= until; p++) {
          auto &it = guys[p];
          if (it.y <= valy) {
            lsol = l;
            rsol = it.i;
          }
        }
        assert(lsol != -1 && rsol != -1);
        break;
      }

    }
    if (lsol !=- 1) {
      cout << "1\n";
      cout << lsol << " " << rsol << "\n";
      continue;
    }
    int P = max_element(pref + 1, pref + n + 1) - pref;
    cout << "2\n";
    cout << 1 << " " << P << "\n";
    cout << P + 1 << " " << n << "\n";
  }
}