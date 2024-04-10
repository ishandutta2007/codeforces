#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int a = n / 2, b = n - n / 2;

  int sol = (a + 1) * (b + 1);

  if (n % 2 == 1) {
    sol *= 2;
  }
  cout << sol << "\n";
}