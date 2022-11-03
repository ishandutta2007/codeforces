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

int ty(string& s) {
  int w[] = {0, 0};
  for (char c : s) w[c - '0']++;
  if (w[0] > w[1]) return 0; return 1;
}

void solve(string s1, string s2, int ty) {
  // cout << s1 << ' ' << s2 << ' ' << ty << endl;
  int uk = 0;
  for (char c : s2) {
    if (c - '0' == ty) {
      while (uk < s1.size() && s1[uk] - '0' != ty) {
        cout << s1[uk];
        ++uk;
      }
      if (uk != s1.size()) ++uk;
    } else {
    }
    cout << c;
  }
  for (int i = uk; i < s1.size(); ++i) cout << s1[i];
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    if (ty(s1) == ty(s2)) solve(s1, s2, ty(s1));
    else
    if (ty(s1) == ty(s3)) solve(s1, s3, ty(s1));
    else
    if (ty(s2) == ty(s3)) solve(s3, s2, ty(s2));
    cout << "\n";
  }

}