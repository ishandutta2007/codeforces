#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {

  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    for (int i=0; i<s.size(); i+=2) {
      cout << s[i];
    }
    cout << s.back() << "\n";
  }
  return 0;
}