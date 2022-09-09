#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    string s1 = "2020";
    bool flag = 0;
    for (int i = 0; i <= 4; i++) {
      if (s.substr(0, i) == s1.substr(0, i) &&
          s.substr(n - 4 + i, 4 - i) == s1.substr(i, 4 - i)) {
        flag = 1;
        break;
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}