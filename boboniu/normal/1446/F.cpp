#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 123456

int n;
i64 k;
int x[maxN], y[maxN];
double ang[maxN], dis[maxN];
array<double, 2> p[maxN];
int rnk[maxN][2];
int fenwick[2 * maxN];
double eps = 1e-9, pi = acos(-1.0);

i64 count(double D) {
  // count pair >= D
  int m = 0;
  for (int i = 0; i < n; i++) {
    if (dis[i] > D + eps) {
      double cang = acos(D / dis[i]);
      p[m++] = {ang[i] - cang, ang[i] + cang};
    }
  }
  vector<pair<pair<double, double>, int>> rg;
  vector<pair<double, pair<int, int>>> count1;
  vector<pair<double, pair<int, int>>> count2;
  for (int i = 0; i < m; i++) {
    while (p[i][0] < 0)
      p[i][0] += 2 * pi, p[i][1] += 2 * pi;
    rg.push_back({{p[i][0], p[i][1]}, i});
    count1.push_back({p[i][0], {i, 0}});
    count1.push_back({p[i][1], {i, 1}});
    count2.push_back({p[i][0], {i, 0}});
    if (p[i][1] >= 2 * pi) {
      count2.push_back({p[i][1] - 2 * pi, {i, 1}});
    } else {
      count2.push_back({p[i][1], {i, 1}});
    }
  }
  sort(count1.begin(), count1.end());
  for (int i = 0; i < count1.size(); i++)
    rnk[count1[i].second.first][count1[i].second.second] = i + 1;
  i64 answer = 0;
  sort(rg.begin(), rg.end());
  for (int i = 1; i <= 2 * m; i++)
    fenwick[i] = 0;
  for (int i = 0; i < m; i++) {
    int id = rg[i].second;
    int l = rnk[id][0], r = rnk[id][1];
    for (; r; r -= r & -r)
      answer += fenwick[r];
    for (; l; l -= l & -l)
      answer -= fenwick[l];
    for (r = rnk[id][1]; r <= 2 * m; r += r & -r)
      fenwick[r] += 1;
  }
  /*
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++) {
      if (rg[i].first.second < rg[j].first.first &&
          rg[j].first.second - 2 * pi > rg[i].first.first) {
        answer++;
      }
    }*/
  sort(count2.begin(), count2.end());
  for (int i = 0; i < count2.size(); i++)
    rnk[count2[i].second.first][count2[i].second.second] = i + 1;
  for (int i = 1; i <= 2 * m; i++)
    fenwick[i] = 0;
  for (int i = 0; i < m; i++)
    if (rnk[i][1] < rnk[i][0]) {
      for (int r = rnk[i][1]; r <= 2 * m; r += r & -r)
        fenwick[r] += 1;
    }
  for (int i = 0; i < count2.size(); i++) {
    int id = count2[i].second.first;
    int type = count2[i].second.second;
    if (rnk[id][1] < rnk[id][0] && type == 0) {
      for (int r = rnk[id][1]; r <= 2 * m; r += r & -r)
        fenwick[r] -= 1;
    }
    if (rnk[id][1] > rnk[id][0] && type == 1) {
      int l = rnk[id][0], r = rnk[id][1];
      for (; r; r -= r & -r)
        answer += fenwick[r];
      for (; l; l -= l & -l)
        answer -= fenwick[l];
    }
  }
  return answer;
}

int main() {
  scanf("%d%lld", &n, &k);
  k = (i64)n * (n - 1) / 2 + 1 - k;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    ang[i] = atan2(y[i], x[i]);
    dis[i] = sqrt(x[i] * x[i] + y[i] * y[i]);
  }
  double l = 0, r = 5e4;
  while (clock() <= 7 * CLOCKS_PER_SEC) {
    double m = (l + r) * 0.5;
    if (count(m) >= k)
      l = m;
    else
      r = m;
  }
  printf("%.10f\n", l);
}