#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int A = 1 << 18;
bool lol[A];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, mosquito;
  cin >> n >> mosquito;
  if (mosquito >= (1 << n)) {
    cout << (1 << (n)) - 1 << "\n";
    int rot = 0;
    for (int i = 1; i < (1 << n); i++) {
      rot ^= i;
      cout << rot << " ";
      rot = i;
    }
    cout << "\n";
    return 0;
  }
  cout << (1 << (n - 1)) - 1 << "\n";
  lol[0] = lol[mosquito] = 1;
  int bly = 0;
  for (int i = 0; i < (1 << n); i++) {
    if (i[lol]) continue;
   // i[lol] = (i ^ mosquito)[lol] = 1;
    lol[i] = lol[i ^ mosquito] = 1;
    bly ^= i;
    cout << bly << " ";
    bly = i;
  }
  cout << "\n";
}