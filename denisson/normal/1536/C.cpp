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

    map<pair<int, int>, int> was;


int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    string s; cin >> s >> s;
    was.clear();
    int w1 = 0, w2 = 0;
    for (char c : s) {
      if (c == 'D') ++w1; else ++w2;
      int g = __gcd(w1, w2);
      if (g == 0) g = 1;
      was[mp(w1 / g, w2 / g)]++;
//      cout << "===" << w1 << ' ' << w2 << ' ' << g << ' ' << was[mp(w1 / g, w2/ g)] << endl;
      cout << was[mp(w1 / g, w2 / g)] << ' ';
    }
    cout << "\n";
  }
}