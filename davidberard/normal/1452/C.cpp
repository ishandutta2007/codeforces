#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
int a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    string s;
    cin >> s;
    int brack = 0, paren = 0;
    int ans = 0;
    for (int i=0; i<s.size(); ++i) {
      char c = s[i];
      if (c == '[') {
        ++brack;
      }
      if (c == ']' && brack) {
        --brack;
        ++ans;
      }
      if (c == '(') {
        ++paren;
      }
      if (c == ')' && paren) {
        --paren;
        ++ans;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}