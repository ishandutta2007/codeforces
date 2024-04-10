#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100 + 7;
int n, a[N];
string s;
int b[N], l[N];
int sol;

void upd() {
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += a[i];
  }
  sol = max(sol, cur);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    a[i] = s[i - 1] - '0';
  }

  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> b[i];
  }

  upd();

  for (int j = 1; j <= 10000; j++) {
    for (int i = 1; i <= n; i++) {
      if (j >= b[i] && (j - b[i]) % l[i] == 0) {
        a[i] ^= 1;
      }
    }
    upd();
  }
  cout << sol << '\n';


  return 0;
}