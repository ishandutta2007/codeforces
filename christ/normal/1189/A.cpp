#include <bits/stdc++.h>
using namespace std;
int cnt[2];
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++)  cnt[s[i]-'0']++;
  if (cnt[0] != cnt[1]) cout << 1 << '\n' << s << '\n';
  else {
    cout << 2 << '\n';
    cout << s[0] << ' ' << s.substr(1,s.length()-1) << '\n';
  }
  return 0;
}