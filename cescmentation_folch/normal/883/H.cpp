#include<bits/stdc++.h>

using namespace std;

const int N = 80;
int D[N];
int imp, par;

bool pot(int n, int k) {
  if (n%2 == 0) {
    if (imp) return 0;
    if (par%k) return 0;
    return 1;
  }
  int kk = k;
  if (imp > kk) return 0;
  kk -= imp;
  if (kk%2) return 0;
  int ttp = par;
  ttp -= kk/2;
  if (ttp%k) return 0;
  return 1;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0;i < n; ++i) {
    char a;
    cin>> a;
    ++D[a -'0'];
  }
  imp = 0;
  par = 0;
  for (int i = 0; i < N; ++i) {
    imp += D[i]%2;
    par += D[i]/2;
  }
  int res = 0;
  for (int div = 1; div*div <= n; ++div) {
    if (n%div) continue;
    if (pot(div, n/div)) res = max(res, div);
    if (pot(n/div, div)) res = max(res, n/div);
  }
  cout << n/res << endl;
  int cont = n/res;
  string r(res, '0');
  for (int i = 0; i < cont; ++i) {
    if (res%2) {
      int tt = -1;
      for (int j = 0; j < N; ++j) {
	if (D[j]) tt = j;
	if (D[j]%2) {
	  tt = j;
	  break;
	}
      }
      --D[tt];
      r[res/2] = tt + '0';
    }
    int pp = 0;
    for (int j = 0; j < res/2; ++j) {
      while (D[pp] <= 1) ++pp;
      r[j] = pp + '0';
      r[res - j - 1] = pp + '0';
      D[pp] -= 2;
    }
    if (i) cout << ' ';
    cout << r ;
  }
  cout << endl;
}