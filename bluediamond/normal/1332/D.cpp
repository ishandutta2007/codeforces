#include <bits/stdc++.h>

using namespace std;

int mt[4][4];

void put(int b) {
  int a = 1;
  while (a <= b) {
    a *= 2;
  }
  mt[1][1] = b + a;
  mt[1][2] = a;
  mt[1][3] = a;
  mt[2][1] = b;
  mt[2][2] = a;
  mt[2][3] = a;
  mt[3][1] = b;
  mt[3][2] = b + a;
  mt[3][3] = b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x;
  cin >> x;
  put(x);
  cout << "3 3\n";
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cout << mt[i][j] << " ";
    }
    cout << "\n";
  }

}