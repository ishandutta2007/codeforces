#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 7;
int n;
string s;
vector<int> p;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  n = (int) s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[(i + 1) % n]) {
      p.push_back(i);
    }
  }
  /// yes or no
  int ant = -1;
  int yes = 0;
  int no = 0;

  for (int i = 1; i < (int) p.size(); i++) {
    if (ant == -1 || p[i] != ant + 1) {
      ant = p[i];
      yes++;
    }
  }
  if (p.back() == n - 1 && p[0] == 0) {
    p.pop_back();
  }
  ant = -1;
  for (int i = 0; i < (int) p.size(); i++) {
    if (ant == -1 || p[i] != ant + 1) {
      ant = p[i];
      no++;
    }
  }
  cout << max(yes, no) << "\n";


}