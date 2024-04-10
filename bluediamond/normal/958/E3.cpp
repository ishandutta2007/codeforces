#include <bits/stdc++.h>

using namespace std;

const int N = 20000 + 7;
int n, pr[N];

struct point {
  int x, y, id;
} p[N];

int f(point a, point b) {
  return (a.x - b.x) * (a.y + b.y);
}

int f(point a, point b, point c) {
  return f(a, b) + f(b, c) + f(c, a);
}

bool operator < (point a, point b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

point gigel;

bool cmp(point a, point b) {
  return f(a, b, gigel) > 0;
}

void baga(int l, int r) {
  if (l > r) return;
  int sol = l;
  for (int j = l + 1; j <= r; j++) {
    if (p[j] < p[sol]) sol = j;
  }
  swap(p[sol], p[l]);
  gigel = p[l];
  sort(p + l + 1, p + r + 1, cmp);
  int same = 0, dif = 0, last;
  for (int j = l + 1; j <= r; j++) {
    same += (p[j].id <= n) == (p[l].id <= n);
    dif += (p[j].id <= n) != (p[l].id <= n);
    last = j;
    if (dif == same + 1) break;
  }
  assert(dif == same + 1);
  pr[p[l].id] = p[last].id;
  pr[p[last].id] = p[l].id;
  baga(l + 1, last - 1);
  baga(last + 1, r);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> p[i].x >> p[i].y;
    p[i].id = i;
  }
  baga(1, 2 * n);
  for (int i = 1; i <= n; i++) {
    cout << pr[i] - n << "\n";
  }
}