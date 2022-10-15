#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<pair<ll, ll>, int> memo_win;
map<pair<ll, ll>, int> memo_lose;

int can_win_brute(ll s, ll e) {
  if (s > e) {
    return 1;
  }
  assert(1LL <= s && s <= e);
  if (memo_win.count({s, e})) {
    return memo_win[{s, e}];
  }
  int& sol = memo_win[{s, e}];
  if (can_win_brute(2 * s, e) == 0) {sol = 1; return sol;}
  if (can_win_brute(s + 1, e) == 0) {sol = 1; return sol;}
  return sol;
}

int can_lose_brute(ll s, ll e) {
  if (s > e) {
    return 0;
  }
  assert(1LL <= s && s <= e);
  if (memo_lose.count({s, e})) {
    return memo_lose[{s, e}];
  }
  int& sol = memo_lose[{s, e}];
  if (can_lose_brute(2 * s, e) == 0) {sol = 1; return sol;}
  if (can_lose_brute(s + 1, e) == 0) {sol = 1; return sol;}
  return sol;
}

int can_win_smart(ll s, ll e) {
  if (e % 2 == 1) {
    return 1 - s % 2;
  }
  if (2 * s > e) {
    return (e - s) % 2;
  }
  if (4 * s > e) {
    return 1;
  }
  return can_win_smart(s, e / 4);
}

int can_lose_smart(ll s, ll e) {
  return can_win_smart(s, 2 * e);
}


/// DO NOT TOUCH:::::::::
int can_win(ll s, ll e) {
  return can_win_smart(s, e);
  assert(can_win_brute(s, e) == can_win_smart(s, e));
  return can_win_brute(s, e);
}

int can_lose(ll s, ll e) {
  return can_lose_smart(s, e);
  assert(can_lose_brute(s, e) == can_lose_smart(s, e));
  return can_lose_brute(s, e);
}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int can_be_first = 1, can_be_second = 0;

  int n;
  cin >> n;
  for (int iter = 1; iter <= n; iter++) {
    ll s, e;
    cin >> s >> e;
    if (can_be_first == 1 && can_be_second == 1) {
      continue;
    }
    if (can_be_first == 0 && can_be_second == 0) {
      continue;
    }

    int ok_win = can_win(s, e), ok_lose = can_lose(s, e);
    if (can_be_first == 0) {
      ok_win ^= 1;
      ok_lose ^= 1;
    }
    can_be_first = ok_lose;
    can_be_second = ok_win;
  }
  /// the loser of this round is the starter of the next round

  cout << can_be_second << " " << can_be_first << "\n";

  return 0;
}