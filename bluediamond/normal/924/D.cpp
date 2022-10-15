#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;
const int N = (int) 2e5 + 7;
int n, w, ret;
int x[N], v[N];
map<ld, int> f;
int t1[N], t2[N];
vector<int> ord;

bool cmp(int i, int j) {
  return t1[i] < t1[j];
}

ld get(int i, int a) {
  return -x[i] / (ld) (v[i] + a);
}

int aib[N];

void add(int i) {
  while (i <= 2 * n) {
    aib[i]++;
    i += i & (-i);
  }
}

int get(int i) {
  int ret = 0;
  while (i) {
    ret += aib[i];
    i -= i & (-i);
  }
  return ret;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> v[i];
    f[get(i, -w)] = f[get(i, +w)] = 0;
  }
  int fof = 0;
  for (auto &it : f) it.second = ++fof;
  for (int i = 1; i <= n; i++) {
    t1[i] = f[get(i, -w)];
    t2[i] = f[get(i, +w)];
  }
  vector<int> ord;
  for (int i = 1; i <= n; i++) {
    ord.push_back(i);
  }
  sort(ord.begin(), ord.end(), cmp);
  int l = 0;
  while (l < n) {
    int r = l;
    while (r + 1 < n && t1[ord[r]] == t1[ord[r + 1]]) {
      r++;
    }
    for (int i = l; i <= r; i++) {
      ret += i - l + get(2 * n + 1 - t2[ord[i]]);
    }
    for (int i = l; i <= r; i++) {
      add(2 * n + 1 - t2[ord[i]]);
    }
    l = r + 1;
  }
  cout << ret << "\n";


}