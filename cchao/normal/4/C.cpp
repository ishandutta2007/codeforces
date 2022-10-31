#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  unordered_map<string, int> m;
  while (n--) {
    string s;
    cin >> s;
    if (m[s]++) {
      cout << s << m[s] - 1 << endl;
    }
    else {
      cout << "OK" << endl;
    }
  }
  return 0;
}