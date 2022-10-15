#include <bits/stdc++.h>

using namespace std;

int ask(int a, int b) {
  cout << "? " << a << " " << b << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int next_dif = ask(0, 0);
  int a = 0;
  int b = 0;
  for (int bit = 29; bit >= 0; bit--) {
    if (next_dif == 0) {
      int val = ask(a + (1 << bit), b);
      if (val == -1) {
        a += (1 << bit);
        b += (1 << bit);
      }
    }
    else {
      int val = ask(a + (1 << bit), b + (1 << bit));
      if (val == next_dif) {
        int val2 = ask(a + (1 << bit), b);
        if (val2 == -1) {
          a += (1 << bit);
          b += (1 << bit);
        }
      }
      else {
        if (next_dif == 1) {
          a += (1 << bit);
        }
        else {
          b += (1 << bit);
        }
        next_dif = ask(a, b);
      }
    }
  }
  cout << "! " << a << " " << b << "\n";
  return 0;
}