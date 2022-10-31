#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

string s, a;
stack<char> st;
string t;
int main() {
  cin >> s;
  a = s;
  for (int i = SZ(s) - 2; i >= 0; --i)
    a[i] = min(a[i], a[i + 1]);
  REP(i, SZ(s)) {
    while (st.size() && st.top() <= a[i]) {
      t += st.top();
      st.pop();
    }
    st.push(s[i]);
  }
  while (st.size()) {
    t += st.top();
    st.pop();
  }
  cout << t << endl;
  return 0;
}