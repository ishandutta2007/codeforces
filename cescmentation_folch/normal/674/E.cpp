#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;

const int MAXN = 500010;
const int MAXK = 60;

ld A[MAXN][MAXK + 5];
int P[MAXN];

void actu(int x) {
  ld ant = 0;
  int antx = x;
  A[x][0] = 1;
  x = P[x];
  int k = 1;
  while (x != -1 and k <= MAXK) {
    ld ant2 = A[x][k];
    A[x][k] = 1.0 - ((1.0 - A[antx][k - 1]/2)*((1.0 - A[x][k])/(1.0 - ant/2)));
//     cerr << x << ' ' << k << ' ' << A[x][k] << endl;
    ant = ant2;
    antx = x;
    x = P[x];
    ++k;
  }
}

ld resp(int x) {
  ld res = 0;
  for (int i = 1; i <= MAXK; ++i) {
    res += A[x][i];
//     cerr << i << ' ' << A[x][i] << endl;
  } 
  return res;
}

int main() {
  memset(A, 0.0, sizeof A);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  int cont = 1;
  P[cont] = -1;
  ++cont;
  while (t--) {
    int c, x;
    cin >> c >> x;
    if (c == 1) {
      P[cont] = x;
      actu(cont);
      cont++;
    }
    else cout << setprecision(10) << fixed << resp(x) << endl;
  }
}