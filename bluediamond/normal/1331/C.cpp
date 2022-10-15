#include <bits/stdc++.h>

using namespace std;

int b[6];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 6; i++) {
    if (n & (1 << (5 - i))) {
      b[i] = 1;
    }
  }
  swap(b[1], b[5]);
  swap(b[2], b[3]);
  int sol = 0;
  for (int i = 0; i < 6; i++) {
    sol += b[i] * (1 << (5 - i));
  }
  cout << sol << "\n";
}