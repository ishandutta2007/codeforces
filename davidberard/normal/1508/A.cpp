#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int onecount(const string& s) {
  int amt = 0;
  for (int i=0; i<s.size(); ++i) {
    amt += (s[i] == '1');
  }
  return amt;
}
int majority_one(const string &s) {
  return onecount(s)*2 >= s.size();
}
void flip(string& s) {
  for (int i=0; i<s.size(); ++i) {
    s[i] = (s[i] == '0' ? '1' : '0');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    bool is_flipped = false;
    if (!(majority_one(a) + majority_one(b) + majority_one(c) >= 2)) {
      flip(a); flip(b); flip(c);
      is_flipped = true;
    }
    if (!majority_one(a)) {
      swap(a, b);
    }
    if (!majority_one(b)) {
      swap(b, c);
    }
    if (onecount(b) > onecount(a)) {
      swap(a, b);
    }
    int j = 0;
    string out;
    for (int i=0; i<a.size(); ++i) {
      if (a[i] == '0') {
        out += "0";
        if (j < b.size() && b[j] == '0') {
          ++j;
        }
      } else {
        while (j < b.size() && b[j] == '0') {
          out += "0";
          ++j;
        }
        out += "1";
        if (j < b.size() && b[j] == '1') {
          ++j;
        }
      }
    }
    while (j < b.size()) {
      assert(b[j] == '0');
      out += "0";
      ++j;
    }
    if (is_flipped) {
      flip(out);
    }
    cout << out << "\n";
  }
  return 0;
}