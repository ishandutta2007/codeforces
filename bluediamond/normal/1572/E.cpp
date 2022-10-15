#include <bits/stdc++.h>

using namespace std;

#define int long long
bool home = 1;
const int INF = (int) 1e18;

struct ve {
  int x;
  int y;
};

int trapez(ve a, ve b) {
  return (a.x - b.x) * (a.y + b.y);
}

const int N = 444;
int n;
int k;
ve p[N];
int area[N][N];
int canmax[N][N];
pair<int, int> mindel[N]; /// min_delete[position]
bool debug = 0;

bool isok(int limit) {
  /// vreau sa tai de cat mai multe ori astfel incat toate bucatile sa fie >= limit
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 1; j <= 2 * n; j++) {
      canmax[i][j] = -INF;
    }
  }
  for (int l = 2 * n; l >= 1; l--) {
    for (int r = l; r <= min(l + n - 1, 2 * n); r++) {
      if (l == r) {
        mindel[r] = {0, 0};
      } else {
        mindel[r] = mindel[r - 1];
      }
      for (int from = l; from <= r; from++) {
        int add_to_del = area[from][r];
        int cnt_inside = canmax[from][r];

        mindel[r] = max(mindel[r], {mindel[from].first + cnt_inside + 1, mindel[from].second - add_to_del});
      }
      for (int f = l; f <= r; f++) {
        if (area[l][r] + mindel[f].second >= limit) {
          canmax[l][r] = max(canmax[l][r], mindel[f].first);
        }
      }

      {
        int from = l;
        if (from <= r) {
          int add_to_del = area[from][r];
          int cnt_inside = canmax[from][r];
          mindel[r] = max(mindel[r], {mindel[from].first + cnt_inside + 1, mindel[from].second - add_to_del});

        }
      }
    }
  }
  int best = 0;
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      best = max(best, 1 + canmax[l][r] + canmax[r][l + n]);
    }
  }
  return best >= k;
}

signed main() {

#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("iron_man.txt","r",stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
    p[i + n] = p[i];
  }

  for (int l = 1; l <= 2 * n; l++) {
    area[l][l] = 0;
    int current = 0;
    for (int r = l + 1; r <= 2 * n; r++) {
      current += trapez(p[r - 1], p[r]);
      area[l][r] = abs(current + trapez(p[r], p[l]));
    }
  }

  if (k == 0) {
    cout << area[1][n];
    exit(0);
  }

  /// can all be >= x?
  int low = 0, high = INF, sol = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (isok(mid)) {
      sol = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << sol << "\n";

  return 0;
}