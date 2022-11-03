#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> v;

int fen[300005];

void upd(int pos, int add) {
  for ( ; pos < 300005; pos |= (pos + 1))
    fen[pos] += add;
}

int fnd(int pos) {
  int ret = 0;
  for ( ; pos >=0; pos = (pos & (pos + 1)) - 1)
    ret += fen[pos];
  return ret;
}

long long cnt() {
  vector<pair<int, int>> s;
  for (int i = 0; i < v.size(); ++i) {
    s.push_back({v[i], i});
  }
  sort(s.rbegin(), s.rend());

  memset(fen, 0, sizeof(fen));
  long long inv = 0;
  for (int i = 0; i < s.size(); ++i) {
    inv += fnd(s[i].second);
    upd(s[i].second, 1);
  }
  return inv;
}

int main() {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  long long cur = cnt(), ans = 0;
  for (int bit = 1 << 30; bit > 0; bit >>= 1) {
    for (int i = 0; i < n; ++i) v[i] ^= bit;
    long long val = cnt();
    if (val < cur) {
      cur = val;
      ans |= bit;
    } else {
      for (int i = 0; i < n; ++i) v[i] ^= bit;
    }
  }
  cout << cur << " " << ans << endl;

  return 0;
}