#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  cin >> a >> b;
  int up = 7 - max(a, b);
  int down = 6;
  int red = gcd(up, down);
  up /= red;
  down /= red;
  cout << up << "/" << down << "\n";

}