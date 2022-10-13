#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  long long k; cin >> k;
  long long pw2 = 1;
  int add = 0;
  string cf = "codeforces";
  vector<int> cnt(cf.size(), 1);
  int at = 0;
  while (true) {
    long long prod = 1;
    for (auto x : cnt) {
      prod *= x;
    }
    if (prod >= k) break;
    cnt[at] += 1;
    at = (at + 1) % cf.size();
  }

  for (int i = 0; i < (int)cnt.size(); ++i) {
    cout << string(cnt[i], cf[i]);
  }
  cout << endl;

  return 0;
}