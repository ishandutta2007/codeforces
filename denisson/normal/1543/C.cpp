#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const db eps = 1e-8;

db v;
db res = 0;
db p[3];


void gen(int ve = 1, db pp = 1) {
  res += ve * p[2] * pp;
  for (int i = 0; i < 2; ++i) {

    if (p[i] > eps) {
      db f[3] = {p[0], p[1], p[2]};
      if (p[i] > v) {
        p[i] -= v;
        if (p[i ^ 1] > eps) {
          p[i ^ 1] += v / 2;
          p[2] += v / 2;
        } else {
          p[2] += v;
        }
        gen(ve + 1, pp * (p[i] + v));
      } else {
        auto s = p[i];
        p[i] = 0;
        if (p[i ^ 1] > eps) {
          p[i ^ 1] += s / 2;
          p[2] += s / 2;
        } else {
          p[2] += s;
        }
        gen(ve + 1, pp * s);
      }
      p[0] = f[0];
      p[1] = f[1];
      p[2] = f[2];
    }
  }
}

int main(){
#ifdef LOCAL
  freopen("C_input.txt", "r", stdin);
  //freopen("C_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int tt; cin >> tt; while (tt--) {
    cin >> p[0] >> p[1] >> p[2] >> v;
    res = 0; 
    gen();


    cout.precision(10);
    cout << fixed << res << "\n";
  }
}