#include <bits/stdc++.h>

using namespace std;

bool sm(string a, string b) {
  if ((int) a.size() == (int) b.size()) return a <= b; else return (int) a.size() < (int) b.size();
}

void p(string s) {
  cout << s << "\n";
  exit(0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  if (sm(s, "127")) p("byte");
  if (sm(s, "32767")) p("short");
  if (sm(s, "2147483647")) p("int");
  if (sm(s, "9223372036854775807")) p("long");
  p("BigInteger");
}