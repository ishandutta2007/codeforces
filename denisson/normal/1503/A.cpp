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

void solve() {
  string s;
  cin >> s >> s;
  string s1, s2;
  int cnt = 0;
  int f =0 ;
  for (char c : s) if (c == '1') {
    ++f;
  } else {
    ++cnt;
  }
  if (cnt % 2 == 1) {
    cout << "NO\n";
    return;
  }

  int was0 = 0;

  //cout << f << ' ' << s << ' ' << cnt << endl;

  for (char c : s) {
    if (c == '1') {
      ++was0;
      if (was0 * 2 <= f) s1 += '(', s2 += '('; else s1 += ')', s2 += ')';
    } else {
      if (cnt % 2 == 0) {
        s1 += '(';
        s2 += ')';
      } else {
        s2 += '(';
        s1 += ')';
      }
      --cnt;
    }
  }


  int ok1 = 1, ok2 = 1;

  int b = 0;
  for (char c : s1) {
    if (c == '(') ++b;
    else {
      --b;
      if (b < 0) ok1 = 0;
    }
  }

  b = 0;
  for (char c : s2) {
    if (c == '(') ++b;
    else {
      --b;
      if (b < 0) ok2 = 0;
    }
  }

  if (ok1 && ok2) {
    cout << "YES\n";
    cout << s1 << '\n' << s2 << endl;
  } else {
    cout << "NO\n";
  }
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt; cin >> tt;
  while (tt--) {
    solve();
  }
}