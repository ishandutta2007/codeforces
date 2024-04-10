#include <bits/stdc++.h>

using namespace std;

int n;
string s, t;

bool good(string a) {
  for (int i = 0; i + 1 < (int) a.size(); i++) {
    if (a[i] == s[0] && a[i + 1] == s[1]) {
      return 0;
    }
    if (a[i] == t[0] && a[i + 1] == t[1]) {
      return 0;
    }
  }
  return 1;
}

string t1(string s) {
  string sol;
  for (int j = 0; j < n; j++) {
    sol += s;
  }
  return sol;
}

string t2(string s) {
  string sol;
  for (auto &ch : s) {
    for (int j = 0; j < n; j++) {
      sol += ch;
    }
  }
  return sol;
}

void upd(string s) {
  string a = t1(s), b = t2(s);
  if (good(a)) {
    cout << a << "\n";
    exit(0);
  }
  if (good(b)) {
    cout << b << "\n";
    exit(0);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cout << "YES\n";
  cin >> n >> s >> t;

  string jeg = "abc";
  upd(jeg);

  while (next_permutation(jeg.begin(), jeg.end())) {
    upd(jeg);
  }



  return 0;
}