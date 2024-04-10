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

int get(int a[], int start, int stop) {
  if (start > stop) {
    return 0;
  }
  assert(start >= 1);
  return a[stop] - a[start - 1];
}

string str;
const int N = (int) 1e6 + 7;
int n, dir[N], sumrgh[N], sumlft[N], i1, i2, memory[N][2];

signed realMain() {
  cin >> n >> str;
  for (int i = 1; i <= n; i++) {
    dir[i] = (str[i - 1] == 'U') ? (+1) : (-1);
    if (dir[i] == +1) {
      i1++;
      sumlft[i1] = sumlft[i1 - 1] + i;
    } else {
      i2++;
      sumrgh[i2] = sumrgh[i2 - 1] + i;
    }
    memory[i][0] = i1;
    memory[i][1] = i2;
  }
  for (int i = 1; i <= n; i++) {
    int sol = 0, slft = memory[i - 1][0], srgh = memory[n][1] - memory[i][1], elft = 0, ergh = 0, finito;
    if (dir[i] == +1) {
      if (srgh <= slft) {
        elft = srgh;
        ergh = srgh;
        finito = n;
      } else {
        elft = slft;
        ergh = slft + 1;
        finito = -1;
      }
    } else {
      if (slft <= srgh) {
        elft = slft;
        ergh = slft;
        finito = -1;
      } else {
        ergh = srgh;
        elft = srgh + 1;
        finito = n;
      }
    }
    sol = 2 * (get(sumrgh, memory[i][1] + 1, memory[i][1] + ergh) - get(sumlft, memory[i - 1][0] - elft + 1, memory[i - 1][0])) + finito - dir[i] * i + 1;
    cout << sol << " ";
  }
  cout << "\n";
  return 0;
}