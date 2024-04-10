#include <bits/stdc++.h>

using namespace std;

bool home = 1;
const int N = 1000 + 7;
const int M = 1000 + 7;
int n;
bool can[N][2 * M];
vector<int> par[N][2 * M];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  cin >> n;


  vector<vector<int>> que;
  que.push_back({ 0, 0 });
  can[0][0] = 1;
  for (int pique = 0; pique < (int)que.size(); pique++) {
    int carry = que[pique][0];
    int bal = que[pique][1];
    for (int digit = (carry == 0 && bal == 0); digit <= 9; digit++) {
      int newcarry = (carry + digit * n) / 10;
      int newbal = bal - digit + n * ((carry + digit * n) % 10);
      if (abs(newbal) >= M - 7) continue;
      if (can[newcarry][newbal + M]) continue;
      can[newcarry][newbal + M] = 1;
      par[newcarry][newbal + M] = { carry, bal, digit };

      que.push_back({ newcarry, newbal });
    }
  }

  que.clear();
  for (int carry = 0; carry < n; carry++) {
    for (int bal = -(M - 7); bal <= (M + 7); bal++) {
      if (can[carry][bal]) {
        que.push_back({ carry, bal });
      }
    }
  }

  for (int pique = 0; pique < (int)que.size(); pique++) {
    int carry = que[pique][0];
    int bal = que[pique][1];
    if (carry >= 10) {
      int newcarry = carry / 10;
      int newbal = bal + n * (carry % 10);
      if (abs(newbal) >= M - 7) continue;
      if (can[newcarry][newbal + M]) continue;
      can[newcarry][newbal + M] = 1;
      par[newcarry][newbal + M] = { carry, bal };
      que.push_back({ newcarry, newbal });
    }
  }

  if (!can[0][M]) {
    cout << "-1\n";
    exit(0);
  }

  vector<int> sol;
  int carry = 0, bal = 0;

  while (1) {
    vector<int> nxt = par[carry][bal + M];
    int _carry = nxt[0];
    int _bal = nxt[1];
    if ((int)nxt.size() == 3) {
      int digit = nxt[2];
      sol.push_back(digit);
    }
    carry = _carry;
    bal = _bal;
    if (carry == 0 && bal == 0) {
      break;
    }
  }
  bool f = 0;
  for (auto& x : sol) {
    f |= (x > 0);
    if (!f) continue;
    cout << x;
  }
  cout << "\n";

  return 0;
}