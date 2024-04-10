#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 5e5 + 7;
const int M = (int) 1e5 + 7;
const int INF = (int) 1e9 + 7;
int n, q, a[N];
int rad;
int bucket[N];
int first[M];
int last[M];
vector<int> so[M];
int add[M];

void open(int b) {
  if (!add[b]) return;
  for (int i = first[b]; i <= last[b]; i++) {
    a[i] = min(INF, a[i] + add[b]);
  }
  for (auto &x : so[b]) {
    x = min(INF, x + add[b]);
  }
  add[b] = 0;
}

void recalc(int b) { /// I could be a try-hard, but I won't
  so[b].clear();
  for (int j = first[b]; j <= last[b]; j++) {
    so[b].push_back(a[j]);
  }
  sort(so[b].begin(), so[b].end());
}

bool is(int b, int val) {
  val -= add[b];
  if (val < 0) return 0;
  int lo = 0, hi = (int) so[b].size() - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (so[b][mid] == val) return 1;
    if (so[b][mid] < val) lo = mid + 1;
    else hi = mid - 1;
  }
  return 0;
}

bool este[M];

signed realMain() {
  cin >> n >> q;
  rad = sqrt(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    bucket[i] = (i - 1) / rad + 1;
    last[bucket[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    first[bucket[i]] = i;
  }
  for (int b = bucket[1]; b <= bucket[n]; b++) {
    for (int j = first[b]; j <= last[b]; j++) {
      so[b].push_back(a[j]);
    }
    sort(so[b].begin(), so[b].end());
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      if (bucket[l] == bucket[r]) {
        open(bucket[l]);
        for (int j = l; j <= r; j++) {
          a[j] = min(INF, a[j] + x);
        }
        recalc(bucket[l]);
      } else {
        open(bucket[l]);
        for (int j = l; j <= last[bucket[l]]; j++) {
          a[j] = min(INF, a[j] + x);
        }
        recalc(bucket[l]);


        open(bucket[r]);
        for (int j = first[bucket[r]]; j <= r; j++) {
          a[j] = min(INF, a[j] + x);
        }
        recalc(bucket[r]);

        for (int b = bucket[l] + 1; b <= bucket[r] - 1; b++) {
          add[b] = min(INF, add[b] + x);
        }
      }
    } else {
      int x;
      cin >> x;
      int l = -1, r = -1;
      for (int j = bucket[1]; j <= bucket[n]; j++) {
        este[j] = is(j, x);
        if (este[j]) {
          r = j;
          if (l == -1) {
            l = j;
          }
        }
      }
      if (l == -1) {
        cout << "-1\n";
      } else {
        open(l);
        open(r);
        l = first[l];
        r = last[r];
        while (a[l] != x) l++;
        while (a[r] != x) r--;
        cout << r - l << "\n";
      }
    }
  }
  return 0;
}