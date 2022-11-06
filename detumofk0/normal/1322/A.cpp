#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; string s;
  cin >> n >> s;

  int cur = 0, neg = -1, ans = 0;
  for(int i = 0; i < n; ++i) {
    if(s[i] == '(') cur++;
    if(s[i] == ')') cur--;
    if(cur < 0 && neg == -1) neg = i;
    else if(cur == 0 && neg != -1) {
      ans += i - neg + 1;
      neg = -1;
    }
  }

  if(neg != -1 || cur != 0) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}