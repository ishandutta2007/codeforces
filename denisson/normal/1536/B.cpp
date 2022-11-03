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
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s >> s;
    int st = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      int ok = 1;
      for (char q : s) if (q == c) ok = 0;
      if (ok) {
        cout << c << "\n";
        st = 1;
        break;
      }
    }
    if (st == 0) {
      for (char c = 'a'; c <= 'z' && st == 0; ++c) 
      for (char c2 = 'a'; c2 <= 'z' && st == 0; ++c2) {
        int ok = 1;
        for (int i = 0; i + 1 < s.size(); ++i) {
          if (s[i] == c && s[i + 1] == c2) {
            ok = 0;
          }
        }
        if (ok) {
          cout << c << c2 << "\n";
          st = 1;
          break;
        }
      }
    }
    if (st == 0) {
      for (char c = 'a'; c <= 'z' && st == 0; ++c) 
      for (char c2 = 'a'; c2 <= 'z' && st == 0; ++c2)
      for (char c3 = 'a'; c3 <= 'z' && st == 0; ++c3) {
        int ok = 1;
        for (int i = 0; i + 2 < s.size(); ++i) {
          if (s[i] == c && s[i + 1] == c2 && s[i + 2] == c3) {
            ok = 0;
          }
        }
        if (ok) {
          cout << c << c2 << c3 << "\n";
          st = 1;
          break;
        }
      }
    }
  }

}