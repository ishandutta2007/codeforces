#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

/**
mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}**/

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 200000 + 7;
int c, n, f[N], smallerInitial[N]; /// smaller[i] = biggest value that is smaller than i or -1 if it is nonexistent
int extra;

int get_smaller(int num) {
  int ret = smallerInitial[num];
  if (extra <= num) ret = max(ret, extra);
  return ret;
}

signed realMain() {
  cin >> c >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    f[a]++;
  }
  
  smallerInitial[0] = -1;
  for (int i = 1; i <= c; i++) {
    if (f[i]) smallerInitial[i] = i;
    else smallerInitial[i] = smallerInitial[i - 1];
  }
  
  for (int bag = 1; bag <= c; bag++) {
    extra = bag;
    f[bag]++;
    int have = c, last = c + 1;
    while (have > 0) {
      int want = get_smaller(min(have, last - 1));
      if (want == -1) break;
      int will_take = min(f[want], have / want);
      last = want;
      have -= will_take * want;
    }
    if (have > 0) {
      cout << bag << "\n";
      return 0;
    }
    f[bag]--;
  }
  cout << "Greed is good\n";
  return 0;
}