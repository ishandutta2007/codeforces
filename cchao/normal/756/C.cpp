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

const int maxn = 1e5 + 10;
const int bs = 512;
int n;

bool v[bs][bs];
int type[bs][bs];
int no[bs][bs];
vector<int> arr[bs];
int pp[bs];

void update(int x) {
  pp[x] = 0;
  arr[x].clear();
  REP(i, 512) if (v[x][i]) {
    int t = type[x][i];
    int a = no[x][i];
    if (t == 0) {
      if (arr[x].empty()) pp[x]++;
      else arr[x].pop_back();
    } else arr[x].push_back(a);
  }
}

int main() {
  scanf("%d", &n);
  REP(it, n) {
    int p, t, x = 0;
    scanf("%d%d", &p, &t);
    p--;
    if (t == 1) scanf("%d", &x);
    int b = p >> 9;
    int c = p & 511;
    v[b][c] = true;
    type[b][c] = t;
    no[b][c] = x;
    update(b);
    int tmp = 0;
    int out = -1;
    for (int i = 511; i >= 0; --i) {
      int sz = SZ(arr[i]);
      if (tmp >= sz) {
        tmp -= sz;
      } else {
        out = arr[i][sz - 1 - tmp];
        break;
      }
      tmp += pp[i];
    }
    printf("%d\n", out);
  }
  return 0;
}