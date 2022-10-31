#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

int n, x, y, a[1010];

int t[1010];

int query(vector<int> v) {
  if (v.empty()) return 0;
  printf("? %d", SZ(v));
  int r = 0;
  for (int x : v) {
    printf(" %d", x);
    r ^= a[x];
  }
  puts("");
  fflush(stdout);
  scanf("%d", &r);
  return r;
}

void answer(int a, int b) {
  if (a > b) swap(a, b);
  printf("! %d %d\n", a, b);
  exit(0);
}

int r[10];

vector<int> construct(int msk) {
  vector<int> r;
  REPE(i, 1, n) if ((i & msk) == msk) r.PB(i);
  return r;
}

int f(vector<int> v) {
  if (v.size() == 1) return v[0];
  int hf = v.size() / 2;
  int r = query(vector<int>(v.begin(), v.begin() + hf));
  if (r == y || r == (x ^ y)) return f(vector<int>(v.begin(), v.begin() + hf));
  else return f(vector<int>(v.begin() + hf, v.end()));
}

int main() {
  scanf("%d%d%d", &n, &x, &y);
  // REPE(i, 1, n) scanf("%d", &a[i]);
  int sum = 0;
  for (int i = 0; i < 10; ++i) {
    r[i] = query(construct(1 << i));
    if (r[i] == y || r[i] == (x ^ y))
      sum ^= 1 << i;
  }
  int aa = 0, bb = 0;
  for (int i = 0; i < 10; ++i) if (r[i] == y || r[i] == (x ^ y)) {
    aa = f(construct(1 << i));
    bb = sum ^ aa;
    answer(aa, bb);
  }
  return 0;
}