// zzfy003
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
  int u, tp;
  bool operator < (const Point b) const {
    return tp > b.tp;
  }
};

const int maxn = 1000005;
priority_queue <Point> pq;
long long fst[maxn], ans[maxn];
int m, a, b;

void bfs() {
  memset(fst, -1, sizeof(fst));
  fst[0] = 0; pq.push((Point){0, 0});
  while (!pq.empty()) {
    Point fy = pq.top(); pq.pop();
    int u = fy.u;
    if (u > b) {
      int can = u - b;
      if (fst[can] != -1) ;
      else {
        fst[can] = fy.tp;
        pq.push((Point){can, fst[can]});
      }
    }
    if (u + a <= m) {
      int can = u + a;
      if (fst[can] != -1) continue;
      
      fst[can] = max(can, fy.tp);
      pq.push((Point){can, fst[can]});
    }
  }
  
  for (int i = 0; i <= m; i++)
    if (fst[i] != -1)
      ans[fst[i]]++;
  for (int i = 1; i <= m; i++) {
    ans[i] += ans[i - 1];
  }
}

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int calc() {
  int cc = 0;
  for (int i = 1; i <= m; i++)
    if (fst[i] != -1) cc++;
  return cc;
}

int main() {
  scanf("%d%d%d", &m, &a, &b);
  if (m <= 1000000) {
    bfs();
    long long anss = 0;
    for (int i = 0; i <= m; i++)
      anss += ans[i];
    printf("%lld\n", anss);
  }
  else {
    int mm = m;
    m = a + b;
    bfs();
    int gg = gcd(a, b);
    long long anss = 0;
    for (int i = 0; i <= m; i++) {
      anss += ans[i];
    }
    
    m++; int i, j;
    for (i = m; i % gg != 0; i++)
      anss += i / gg + 1;
    for (j = mm; j % gg != (gg - 1); j--)
      anss += j / gg + 1;
    int times = (j - i + 1) / gg;
    int down = i / gg + 1;
    int up = j / gg + 1;
    
    anss += (long long)(up + down) * times / 2 * gg;
    printf("%lld\n", anss);
  }
  return 0;
}