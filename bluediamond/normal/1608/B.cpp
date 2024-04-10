#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 1e5 + 7;
int type[N], sol[N], cop[N];

bool test(int n, int a, int b) {
  for (int i = 2; i < n; i++) {
    if (sol[i] > sol[i - 1] && sol[i] > sol[i + 1]) {
      a--;
    }
    if (sol[i] < sol[i - 1] && sol[i] < sol[i + 1]) {
      b--;
    }
  }
  for (int i = 1; i <= n; i++) {
    cop[i] = sol[i];
  }
  sort(cop + 1, cop + n + 1);
  for (int i = 1; i <= n; i++) {
    assert(cop[i] == i);
  }
  return a == 0 && b == 0;
}

void solve(int n, int a, int b) {
  int _a = a, _b = b;
  for (int i = 1; i <= n; i++) {
    type[i] = 0;
    sol[i] = 0;
  }
  for (int i = 2; i < n; i++) {
    if (a > b) {
      if (a && type[i - 1] != 1 && !(i - 2 >= 0 && type[i - 1] == 0 && type[i - 2] == 1)) {
        a--;
        type[i] = 1;
      } else {
        if (b && type[i - 1] != 2 && !(i - 2 >= 0 && type[i - 1] == 0 && type[i - 2] == 2)) {
          b--;
          type[i] = 2;
        }
      }
    } else {

      if (b && type[i - 1] != 2 && !(i - 2 >= 0 && type[i - 1] == 0 && type[i - 2] == 2)) {
        b--;
        type[i] = 2;
      } else {
        if (a && type[i - 1] != 1 && !(i - 2 >= 0 && type[i - 1] == 0 && type[i - 2] == 1)) {
          a--;
          type[i] = 1;
        }
      }
    }
  }
  if (a + b > 0) {
    cout << "-1\n";
    return;
  }
  assert(a == 0 && b == 0);
  int l = 1, r = n;
  for (int i = 1; i <= n; i++) {
    if (type[i] == 1) {
      sol[i] = r--;
    }
    if (type[i] == 2) {
      sol[i] = l++;
    }
  }
  int initl = l;
  for (int i = 1; i <= n; i++) {
    if (type[i] == 0) {
      sol[i] = l++;
    }
  }
  if (!test(n, _a, _b)) {
    for (int i = 1; i <= n; i++) {
      if (type[i] == 0) {
        sol[i] = r--;
      }
    }
    if (!test(n, _a, _b)) {
      cout << "-1\n";
      return;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << sol[i] << " ";
  }
  cout << "\n";
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  int t;
  cin>>t;
  while (t--){
    int n, a, b;
    cin >> n >> a >> b;
    solve(n, a, b);
  }

  return 0;
}