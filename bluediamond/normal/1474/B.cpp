#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int E = (int) 1e6;
bool prime[E];
int nxt[E];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  prime[2] = 1;
  for (int i = 3; i < E; i += 2) {
    prime[i] = 1;
  }
  for (int i = 3; i * i < E; i += 2) {
    for (int j = i * i; j < E; j += 2 * i) {
      prime[j] = 0;
    }
  }
  for (int i = E - 2; i; i--) {
    if (prime[i]) {
      nxt[i] = i;
    } else {
      nxt[i] = nxt[i + 1];
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int d, p1, p2;
    cin >> d;
    p1 = nxt[d + 1];
    p2 = nxt[p1 + d];
    cout << (ll) p1 * p2 << "\n";
  }
}