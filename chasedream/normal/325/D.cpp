#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rll RE ll
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i != -1; i = edge[i].nxt)
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

template <typename T>
void read(T &x) {
  x = 0; char op = getchar(); int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1; op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0'; op = getchar();
  }
  x *= F;
}

template <typename T, typename ...Args>
void read(T &x, Args &...args) {
  read(x); read(args...);
}

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

const int N = 1000005;
const int d[8][2] = {
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1},
  {1, 1},
  {1, -1},
  {-1, 1},
  {-1, -1}
};

int f[N], hsh[5005][7005];
int n, m, k, x, y;

int find(int k) {
  return f[k] == k ? k : f[k] = find(f[k]);
}

int id[N];
int cnt = 0;
bool check(int x, int y) {
  if (m == 1) return 0;
  cnt++; int sx, sy;
  for (int tmp = 0; tmp <= 1; tmp++) {
    if (tmp == 0)
      sx = x, sy = y;
    else
      sx = x, sy = y + m;
    for (int j = 0; j < 8; j++) {
      int xx, yy;
      xx = sx + d[j][0];
      yy = sy + d[j][1];
      if (yy < 1) yy += 2 * m;
      if (yy > 2 * m) yy -= 2 * m;
      if (hsh[xx][yy]) {
        if (tmp == 0)
          id[find(hsh[xx][yy])] = cnt;
        else if (id[find(hsh[xx][yy])] == cnt)
          return 0;
      }
    }
  }
  return 1;
}

int ans = 0;
int main() {
  read(n, m, k);
  for (int i = 1; i <= k << 1; i++) {
    f[i] = i;
  }
  for (int i = 1; i <= k; i++) {
    read(x, y);
    if (!check(x, y)) continue;
    ans++;
    hsh[x][y] = i;
    hsh[x][y + m] = i + k;
    for (int tmp = 0; tmp <= 1; tmp++) {
      int sx, sy;
      if (tmp == 0)
        sx = x, sy = y;
      else
        sx = x, sy = y + m;
      for (int j = 0; j < 8; j++) {
        int xx, yy;
        xx = sx + d[j][0];
        yy = sy + d[j][1];
        if (yy < 1) yy += 2 * m;
        if (yy > 2 * m) yy -= 2 * m;
        if (hsh[xx][yy])
          f[find(hsh[sx][sy])] = find(hsh[xx][yy]);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
} 

/*
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rll RE ll
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i != -1; i = edge[i].nxt)
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

template <typename T>
void read(T &x) {
  x = 0; char op = getchar(); int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1; op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0'; op = getchar();
  }
  x *= F;
}

template <typename T, typename ...Args>
void read(T &x, Args &...args) {
  read(x); read(args...);
}

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

const int N = 500005;
const int d[8][2] = {
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1},
  {1, 1},
  {1, -1},
  {-1, 1},
  {-1, -1}
};

int f[N], hsh[5005][5005];
int n, m, k, x, y;

int find(int k) {
  return f[k] == k ? k : f[k] = find(f[k]);
}

int id[N];
int cnt = 0;
bool check(int x, int y) {
  if (m == 1) return 0;
  cnt++; int sx, sy;
  for (int tmp = 0; tmp <= 1; tmp++) {
    if (tmp == 0)
      sx = x, sy = y;
    else
      sx = x, sy = y + m;
    for (int j = 0; j < 8; j++) {
      int xx, yy;
      xx = sx + d[j][0];
      yy = sy + d[j][1];
      if (yy < 1) yy += 2 * m;
      if (yy > 2 * m) yy -= 2 * m;
      if (hsh[xx][yy]) {
        if (tmp == 0)
          id[find(hsh[xx][yy])] = cnt;
        else if (id[find(hsh[xx][yy])] == cnt)
          return 0;
      }
    }
  }
  return 1;
}

int ans = 0;
int main() {
  read(n, m, k);
  for (int i = 1; i <= k << 1; i++) {
    f[i] = i;
  }
  for (int i = 1; i <= k; i++) {
    read(x, y);
    if (!check(x, y)) continue;
    ans++;
    hsh[x][y] = i;
    hsh[x][y + m] = i + k;
    for (int tmp = 0; tmp <= 1; tmp++) {
      int sx, sy;
      if (tmp == 0)
        sx = x, sy = y;
      else
        sx = x, sy = y + m;
      for (int j = 0; j < 8; j++) {
        int xx, yy;
        xx = sx + d[j][0];
        yy = sy + d[j][1];
        if (yy < 1) yy += 2 * m;
        if (yy > 2 * m) yy -= 2 * m;
        if (hsh[xx][yy])
          f[find(hsh[sx][sy])] = find(hsh[xx][yy]);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
} #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rll RE ll
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i != -1; i = edge[i].nxt)
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

template <typename T>
void read(T &x) {
  x = 0; char op = getchar(); int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1; op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0'; op = getchar();
  }
  x *= F;
}

template <typename T, typename ...Args>
void read(T &x, Args &...args) {
  read(x); read(args...);
}

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

const int N = 500005;
const int d[8][2] = {
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1},
  {1, 1},
  {1, -1},
  {-1, 1},
  {-1, -1}
};

int f[N], hsh[5005][5005];
int n, m, k, x, y;

int find(int k) {
  return f[k] == k ? k : f[k] = find(f[k]);
}

int id[N];
int cnt = 0;
bool check(int x, int y) {
  if (m == 1) return 0;
  cnt++; int sx, sy;
  for (int tmp = 0; tmp <= 1; tmp++) {
    if (tmp == 0)
      sx = x, sy = y;
    else
      sx = x, sy = y + m;
    for (int j = 0; j < 8; j++) {
      int xx, yy;
      xx = sx + d[j][0];
      yy = sy + d[j][1];
      if (yy < 1) yy += 2 * m;
      if (yy > 2 * m) yy -= 2 * m;
      if (hsh[xx][yy]) {
        if (tmp == 0)
          id[find(hsh[xx][yy])] = cnt;
        else if (id[find(hsh[xx][yy])] == cnt)
          return 0;
      }
    }
  }
  return 1;
}

int ans = 0;
int main() {
  read(n, m, k);
  for (int i = 1; i <= k << 1; i++) {
    f[i] = i;
  }
  for (int i = 1; i <= k; i++) {
    read(x, y);
    if (!check(x, y)) continue;
    ans++;
    hsh[x][y] = i;
    hsh[x][y + m] = i + k;
    for (int tmp = 0; tmp <= 1; tmp++) {
      int sx, sy;
      if (tmp == 0)
        sx = x, sy = y;
      else
        sx = x, sy = y + m;
      for (int j = 0; j < 8; j++) {
        int xx, yy;
        xx = sx + d[j][0];
        yy = sy + d[j][1];
        if (yy < 1) yy += 2 * m;
        if (yy > 2 * m) yy -= 2 * m;
        if (hsh[xx][yy])
          f[find(hsh[sx][sy])] = find(hsh[xx][yy]);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
} */