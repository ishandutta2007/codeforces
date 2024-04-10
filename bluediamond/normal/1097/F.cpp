#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
const int A = 7000 + 7;
int n, q;
bool sqfree[A];
bitset<A> koala[A];
bitset<A> nums[A];
bitset<A> b[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  for (int i = 1; i < A; i++) {
    for (int j = i; j < A; j += i) {
      nums[j][i] = !nums[j][i];
    }
  }
  for (int i = 1; i < A; i++) {
    sqfree[i] = 1;
  }
  for (int i = 2; i * i < A; i++) {
    for (int j = i * i; j < A; j += i * i) sqfree[j] = 0;
  }
  for (int i = 1; i < A; i++) {
    for (int j = i; j < A; j += i) {
      if (sqfree[j / i]) koala[i][j] = 1;
    }
  }
  string ret;
  cin >> n >> q;
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int x, v;
      cin >> x >> v;
      b[x] = nums[v];
      continue;
    }
    if (tp == 2) {
      int x, y, z;
      cin >> x >> y >> z;
      b[x] = (b[y] ^ b[z]);
      continue;
    }
    if (tp == 3) {
      int x, y, z;
      cin >> x >> y >> z;
      b[x] = (b[y] & b[z]);
      continue;
    }
    if (tp == 4) {
      int x, v;
      cin >> x >> v;
      ret += (char) ('0' + (koala[v] & b[x]).count() % 2);
    }
  }
  cout << ret << "\n";
}