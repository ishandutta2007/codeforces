#include <bits/stdc++.h>

using namespace std;



int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  ///ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int n;
  cin >> n;

  function<int(int)> rep = [&] (int i) {
    i %= n;
    if (i < 0) i += n;
    return i;
  };

  for (int i = 1; i <= n; i++) {
    int b;
    cin >> b;
    for (int j = 1; j <= n; j++) {
      cout << rep(b + i * (j - i)) << " ";
    }
    cout << "\n";
  }

  return 0;

}