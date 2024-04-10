#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
using ULL = unsigned long long;

ULL h[100010][26];

inline ULL rnd() {
  ULL ret = rand();
  ret <<= 22; ret ^= rand();
  ret <<= 22; ret ^= rand();
  return ret;
}
char s[100010];

unordered_map<ULL, int> lisan;
int sz = 0;
int get(ULL x) {
  if (!lisan.count(x))
    lisan[x] = sz++;
  return lisan[x];
}

vector<int> a[100010][2];
bool fg[100010];
LL ans = 0, la[100010];
int main() {
  REP(i, 100010) REP(j, 26) {
    h[i][j] = rnd();
  }
  int k, n;
  scanf("%d%d", &k, &n);
  int x;
  REP(i, k) {
    scanf("%s%d", s, &x);
    ULL h1 = 0, h2 = 0;
    REP(i, n) {
      int idx = s[i] - 'a';
      h1 ^= h[i][idx];
      h2 ^= h[n - i - 1][idx];
    }
    // cout << h1 << ' ' << h2 << ' ' << x << endl;
    int rev = 0;
    if (h1 > h2) {
      swap(h1, h2);
      rev = 1;
    }
    int idx = get(h1);
    if (h1 == h2) fg[idx] = true;
    a[idx][rev].push_back(x);
  }
  REP(i, sz) {
    sort(a[i][0].begin(), a[i][0].end(), greater<int>());
    sort(a[i][1].begin(), a[i][1].end(), greater<int>());
    if (fg[i]) {
      for (int j = 0; j + 1 < a[i][0].size(); j += 2) {
        int t = a[i][0][j] + a[i][0][j + 1];
        if (t > 0) la[i] += t;
        else break;
      }
      ans += la[i];
    } else {
      for (int j = 0, jj = 0; j < a[i][0].size() && jj < a[i][1].size(); ++j, ++jj) {
        int t = a[i][0][jj] + a[i][1][jj];
        if (t > 0) la[i] += t;
        else break;
      }
      ans += la[i];
    }
  }
  LL sum = ans;
  REP(i, sz) if (fg[i]) {
    LL tmp = sum - la[i];
    for (auto x : a[i][0]) {
      if (x > 0) tmp += x;
      else break;
    }
    ans = max(ans, tmp);
  }
  printf("%lld\n", ans);
  return 0;
}