#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int INF = (int) 1e18;

int add(int a, int b) {
  return min(a + b, INF);
}

void addup(int &a, int b) {
  a = add(a, b);
}

int mul(int a, int b) {
  if (a <= INF / b) return a * b;
  return INF;
}

void mulup(int &a, int b) {
  a = mul(a, b);
}

const int N = 100;
int k, maxf, comb[N][N], lim[16], dp[N], ndp[N];

void place() {

  for (int i = 0; i < N; i++) dp[i] = ndp[i] = 0;
  dp[0] = 1;
  for (int x = 15; x >= 0; x--) {
    for (int bef = 0; bef < N; bef++) {
      for (int from = 0; bef + from < N && from <= lim[x]; from++) {
        addup(ndp[bef + from], mul(dp[bef], comb[bef + from][bef]));
      }
    }
    for (int i = 0; i < N; i++) {
      dp[i] = ndp[i];
      ndp[i] = 0;
    }
  }
}

char code(int x) {
  if (x <= 9) return '0' + x;
  x -= 10;
  return 'a' + x;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  for (int i = 0; i < N; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1]);
    }
  }

  cin >> k >> maxf;
  for (int i = 0; i < 16; i++) {
    lim[i] = maxf;
  }


  int lungime = 1;
  while (1) {
    int cnt = 0;
    for (int f = 1; f < 16; f++) {
      lim[f]--;
      place();
      addup(cnt, dp[lungime - 1]);
      lim[f]++;
    }
    if (k <= cnt) {
      break;
    }
    k -= cnt;
    lungime++;
  }


  int start = 1;

  while (lungime) {
    for (int x = start; x < 16; x++) {
      if (lim[x]) {
        lim[x]--;


        place();
        if (k <= dp[lungime - 1]) {
          cout << code(x);
          break;
        }
        k -= dp[lungime - 1];


        lim[x]++;
      }
    }
    start = 0;
    lungime--;
  }
  //cout << k << " " << lungime << "\n";

}