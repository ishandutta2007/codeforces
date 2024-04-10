#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroint-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
signed realMain();
int uselessPieceOfInformationThatLivesInMyHeadRentFree;

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

struct state {
  int dp;
  int mint;
};

state operator + (state a, state b) {
  if (a.dp > b.dp) {
    return a;
  }
  if (b.dp > a.dp) {
    return b;
  }
  return {a.dp, min(a.mint, b.mint)};
}

const int N = (int) 1e5 + 7;
int n, p, t, piv = 0;
state dp[N];

/// statementul meu de mai jos e bs -> ptc na...unul poate sa fie propagat de mai multe ori dar e tot o(n) ptc propag doar ultimul pe care
/// l-am propagat si data trecuta in cazul in care vreau un start fresh de viata

/** fiecare state din dp propaga informatia mai departe doar o singura data. (pentru ca daca ar propaga de mai multe ori ar fi useless
                                                                              deoarece poti doar trece prin nodul intermediar)
**/

signed realMain() {
  cin >> uselessPieceOfInformationThatLivesInMyHeadRentFree>> n >> p >> t;
  dp[0].mint = -(int) 1e9;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    if (piv) {
      piv--;
    }
    while (piv < i && dp[piv].mint + t <= r) {
      int start = (dp[piv].mint + t <= l) ? l : (dp[piv].mint + t), finish = r, cando = (finish - start) / p;
      state relax = {dp[piv].dp + cando, start + cando * p};
      dp[i] = dp[i] + relax;
      piv++;
    }
    dp[i] = dp[i - 1] + dp[i];
  }
  cout << dp[n].dp << "\n";
  return 0;
}