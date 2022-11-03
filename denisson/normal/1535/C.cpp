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



int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt; cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    ll res = 0;

    int uk[2] = {-1, -1}; // 1 = -1, uk2 = -1;
    int pos = 0;
    for (char c : s) {
      if (c == '?') {

        res += max(pos - uk[0], pos - uk[1]);

      } else if (c == '0') {
        int q = pos % 2; 
        uk[q] = pos;

        res += pos - uk[q ^ 1];

      } else {
        int q = (pos + 1) % 2; 
        uk[q] = pos;

        res += pos - uk[q ^ 1];
      }
      ++pos;
    }

    cout << res << "\n";
  }

}