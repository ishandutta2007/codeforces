#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Segment {
  int l;
  int r;
};

bool operator < (Segment a, Segment b) {
  if (a.l != b.l) return a.l < b.l;
  return a.r > b.r;
}

const int N = (int) 2e5 + 7;
const ll INF = (ll) 1e18;
int n;
int m;
int y;
int a[N];
int goLeft[N];
int goRight[N];
Segment segs[N];

int countPointsUnder(int x) {
  int l = 1, r = n, sol = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (a[m] <= x) {
      sol = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return sol;
}

ll dp[N], nou[N], v1[N], v2[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> segs[i].l >> segs[i].r;


    sort(a + 1, a + n + 1);
    sort(segs + 1, segs + m + 1);

    int y = 0;
    for (int i = 1; i <= m; i++) {
      int inMijloc = countPointsUnder(segs[i].r) - countPointsUnder(segs[i].l - 1);
      if (inMijloc == 0) {
        segs[++y] = segs[i];
      }
    }
    m = y;

    y = 0;
    for (int i = 1; i <= m; i++) {
      segs[++y] = segs[i];
      while (y >= 2 && segs[y].r <= segs[y - 1].r) {
        y--;
        segs[y] = segs[y + 1];
      }
    }
    m = y;
    for (int i = 1; i <= m; i++) {
      dp[i] = nou[i] = INF;
    }
    for (int i = 1; i <= n; i++) {
      goLeft[i] = 0;
      goRight[i] = 0;
    }

    for (int i = 1; i <= m; i++) {
      int l = 1, r = n, id = 0;
      while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] <= segs[i].l) {
          id = m;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }

      if (id) {
        if (goLeft[id] == 0) {
          goLeft[id] = i;
        }
        goRight[id] = i;
      }
      if (id + 1 <= n) {
        if (goLeft[id + 1] == 0) {
          goLeft[id + 1] = i;
        }
        goRight[id + 1] = i;
      }
    }

    for (int point = 1; point <= n; point++) {
      if (goRight[point] == 0) {
        continue;
      }
      int pivot = 0;
      for (int i = goLeft[point]; i <= goRight[point]; i++) {
        if (a[point] >= segs[i].l) {
          pivot = i;
        } else {
          break;
        }
      }
      pivot = max(pivot, goLeft[point] - 1);
      for (int i = pivot + 1; i <= goRight[point]; i++) {
        v1[i] = dp[i - 1] - a[point];
        if (i - 1 >= pivot + 1) {
          v1[i] = min(v1[i], v1[i - 1]);
        }
        nou[i] = min(nou[i], v1[i] + segs[i].l);
      }
      for (int i = goLeft[point]; i <= goRight[point]; i++) {
        v1[i] = dp[i - 1] - segs[i].r;
        if (i - 1 >= goLeft[point]) {
          v1[i] = min(v1[i], v1[i - 1]);
        }
      }
      for (int i = pivot; i >= goLeft[point]; i--) {
        v2[i] = dp[i - 1] - 2 * segs[i].r;
        if (i + 1 <= pivot) {
          v2[i] = min(v2[i], v2[i + 1]);
        }
      }
      for (int i = pivot + 1; i <= goRight[point]; i++) {
        int dist1 = segs[i].l - a[point];
        int first = 0, l = goLeft[point], r = pivot;
        while (l <= r) {
          int j = (l + r) / 2;
          int dist2 = a[point] - segs[j].r;
          if (dist1 <= dist2) {
            first = j;
            l = j + 1;
          } else {
            r = j - 1;
          }
        }
        first = max(first, goLeft[point] - 1);
        if (first >= goLeft[point]) {
          nou[i] = min(nou[i], v1[first] + 2 * dist1 + a[point]);
        }
        if (first + 1 <= pivot) {
          nou[i] = min(nou[i], v2[first + 1] + dist1 + 2 * a[point]);
        }
      }
      for (int i = goLeft[point]; i <= pivot; i++) {
        v1[i] = dp[i - 1] - segs[i].r;

        if (i - 1 >= goLeft[point]) {
          v1[i] = min(v1[i], v1[i - 1]);
        }
        nou[i] = min(nou[i], v1[i] + a[point]);
      }
      for (int j = goLeft[point]; j <= goRight[point]; j++) {
        dp[j] = nou[j];
      }
    }
    cout << dp[m] << "\n";
  }
}