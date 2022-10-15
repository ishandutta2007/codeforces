#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

const int N = 1000 + 7;
int n, a[N], len;
bool done = 0;
string sol;
set<string> st;

void gen(string cur) {
  if (done) return;
  if ((int) cur.size() == len) {
    if (!st.count(cur)) {
      done = 1;
      sol = cur;
    }
    return;
  }
  for (char c = 'a'; c <= 'z'; c++) {
    gen(cur + c);
    if (done) return;
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    st.clear();
    cin >> n >> s;
    done = 0;
    for (int i = 0; i < n; i++) {
      string t;
      for (int j = i; j < n && j < i + 10; j++) {
        t += s[j];
        st.insert(t);
      }
    }
    len = 1;
    while (!done) {
      assert(len <= 9);
      gen("");
      len++;
    }
    cout << sol << "\n";
  }

  return 0;
}