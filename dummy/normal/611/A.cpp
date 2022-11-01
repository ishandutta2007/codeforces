#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
string s;

int main() {
  cin >> n >> s >> s;
  if(s == "week") {
    if(n == 5 || n == 6)
      cout << 53 << endl;
    else
      cout << 52 << endl;
  }
  else {
    if(n <= 29)
      cout << 12 << endl;
    else
      if(n == 30)
        cout << 11 << endl;
      else
        cout << 7 << endl;
  }
  return 0;
}