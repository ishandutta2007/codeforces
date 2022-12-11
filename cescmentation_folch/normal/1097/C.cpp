#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<pld> vpld;
typedef vector<vpld> vvpld;
typedef map<int, int> mi;

int main() {
  int n;
  cin >> n;
  vpi S(n);
  mi A;
  mi B;
  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    int cont = 0;
    S[i].first = 0;
    for (auto c : a) {
      if (c == '(') ++cont;
      else --cont;
      S[i].first = min(S[i].first, cont);
    }
    S[i].second = cont;
    if (S[i].first == 0 and S[i].second >= 0) A[S[i].second]++;
    if (S[i].first == S[i].second and S[i].first < 0) B[-S[i].first]++;
  }
  int res = 0;
  for (auto it : A) {
    if (it.first == 0) {
      res += (it.second)/2;
      continue;
    }
    if (B.count(it.first) > 0) res += min(it.second, B[it.first]);
  }
  cout << res << '\n';
}