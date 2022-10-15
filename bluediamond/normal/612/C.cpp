#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 7;
int n, a[N], stk[N], top, p[N];
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  n = (int) s.size();
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '<') a[i] = +1;
    if (s[i - 1] == '>') a[i] = -1;
    if (s[i - 1] == '{') a[i] = +2;
    if (s[i - 1] == '}') a[i] = -2;
    if (s[i - 1] == '[') a[i] = +3;
    if (s[i - 1] == ']') a[i] = -3;
    if (s[i - 1] == '(') a[i] = +4;
    if (s[i - 1] == ')') a[i] = -4;
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] > 0) {
      stk[++top] = i;
    } else {
      if (top == 0) {
        cout << "Impossible\n";
        return 0;
      }
      p[i] = stk[top--];
    }
  }

  if (top != 0) {
    cout << "Impossible\n";
    return 0;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < 0 && a[i] != -a[p[i]]) {
      ans++;
    }
  }
  cout << ans << "\n";

  return 0;
}