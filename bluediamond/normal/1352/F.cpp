#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct T {
  int n0;
  int n1;
  int n2;
};

T get(string s) {
  int a = 0, b = 0, c = 0;
  for (int i = 0; i + 1 < (int) s.size(); i++) {
    int cnt = s[i] + s[i + 1] - 2 * '0';
    if (cnt == 0) a++;
    if (cnt == 1) b++;
    if (cnt == 2) c++;
    if (cnt != 0 && cnt != 1 && cnt != 2) cout << "error\n";
  }
  return {a, b, c};
}

string get(int n0, int n1, int n2) {
  if (n0 == 0 && n1 == 0) {
    string s;
    for (int j = 1; j <= n2 + 1; j++) {
      s += "1";
    }
    return s;
  }
  if (n1 == 0 && n2 == 0) {
    string s;
    for (int j = 1; j <= n0 + 1; j++) {
      s += "0";
    }
    return s;
  }
  string s;
  for (int j = 1; j <= n0 + 1; j++) {
    s += "0";
  }
  n1--;
  for (int j = 1; j <= n2 + 1; j++) {
    s += "1";
  }
  for (int j = 0; j < n1; j++) {
    s += (char) ('0' + j % 2);
  }
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 /// freopen ("input", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    cout << get(n0, n1, n2) << "\n";
    continue;
    string s = get(n0, n1, n2);
    auto it = get(s);
    if (it.n0 != n0 || it.n1 != n1 || it.n2 != n2) {
      cout << n0 << " " << n1 << " " << n2 << "\n";
      cout << it.n0 << " " << it.n1 << " " << it.n2 << "\n";
      cout << " =>  " << s << "\n";
      cout << "\n";
    } else {
      cout << "ok!\n";
    }
  }
  return 0;
}