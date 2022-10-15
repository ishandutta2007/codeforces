#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if ((a + b) % 2 == 1) {cout << "-1\n"; continue;}
    if (a == 0 && b == 0) {cout << "0\n"; continue;}
    if (a == b) {cout << "1\n"; continue;}
    cout << "2\n";
  }

  return 0;
}