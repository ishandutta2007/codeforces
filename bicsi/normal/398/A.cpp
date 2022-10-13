#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b; cin >> a >> b;

  if (a == 0) {
    cout << -1LL * b * b << endl;
    for (int i = 0; i < b; ++i)
      cout << 'x';
    cout << endl;
    return 0;
  }

  if (b == 0) {
    cout << 1LL * a * a << endl;
    for (int i = 0; i < a; ++i)
      cout << 'o';
    cout << endl;
    return 0;
  }

  long long best = -1e18;
  int cga = -1, cgb = -1;

  for (int ga = 1; ga <= a; ++ga) {
    for (int gb = ga - 1; gb <= ga + 1; ++gb) {
      if (gb < 1 || gb > b) 
        continue;

      long long now = ga - 1;
      now += 1LL * (a - (ga - 1)) * (a - (ga - 1));
      long long r = b % gb;
      if (r == 0) now -= 1LL * (b / gb) * (b / gb) * gb;
      else {
        now -= 1LL * (b / gb) * (b / gb) * (gb - b % gb);
        now -= 1LL * (b / gb + 1) * (b / gb + 1) * (b % gb);
      }
      if (best < now) {
        best = now;
        cga = ga;
        cgb = gb;
      }
    }
  }

  cout << best << endl;
  cerr << cga << " " << cgb << endl;

  int last = -1;
  while (cga > 0 || cgb > 0) {
    int now;
    if (last != -1) now = !last;
    else if (cga > cgb) now = 0;
    else now = 1;

    if (now == 0) {
      while (a >= cga) {
        cout << 'o';
        --a;
      }
      --cga;
    } else {
      for (int i = 0; i < b / cgb; ++i)
        cout << 'x';
      b -= b / cgb;
      --cgb;
    }
    last = now;
  }

  return 0;
}