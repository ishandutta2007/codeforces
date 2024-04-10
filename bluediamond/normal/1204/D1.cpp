#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n;
string s;
int a[N];
int b[N];
int suf[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> s;
  n = (int) s.size();
  for (int i = 1; i <= n; i++) {
    a[i] = s[i - 1] - '0';
  }

  int ones = 0;

  for (int i = n; i >= 1; i--) {
    if (a[i] == 1) {
      ones++;
      suf[i] = max(suf[i + 1], ones);
    } else {
      suf[i] = suf[i + 1] + 1;
    }
  }

  for (int i = 1; i < n; i++) {
    cout << (suf[i] == suf[i + 1]);
  }
  cout << "0\n";

  return 0;
}