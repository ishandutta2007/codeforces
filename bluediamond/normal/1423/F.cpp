#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
 // freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  ll n;
  ll cnt_players = 0;
  ll sum = 0;
  int k;
  cin >> n >> k;

  for (int i = 1; i <= k; i++) {
    ll a, b;
    cin >> a >> b;
    a--;
    cnt_players += b;
    sum = (sum + a * b) % n;
  }


  if (cnt_players < n) {
    cout << "1\n";
    exit(0);
  }
  if (cnt_players > n) {
    cout << "-1\n";
    exit(0);
  }
  ll wanted_sum = (n * (n - 1) / 2) % n;


  if (sum == wanted_sum) {
    cout << "1\n";
  } else {
    cout << "-1\n";
  }

  return 0;
}