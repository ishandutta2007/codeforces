#include<bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

int n;
string s, t;

string sorted(string str) {
  sort(str.begin(), str.end());
  return str;
}

vector<int> ans;
void shift(int p) {
  ans.push_back(p);
  s = s.substr(n - p) + s.substr(0, n - p);
  reverse(s.begin() + 0, s.begin() + p);
  //clog << p << " " << s << endl;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
  cin >> n >> s >> t;
  if (sorted(s) != sorted(t)) {
    cout << -1;
    return 0;
  }
  rep(i, n) {
    int p;
    for (p = n - 1; p >= 0; --p) {
      if (s[p] == t[n - 1 - i]) break;
    }
    //clog << p << endl;
    
    shift(n);
    shift(p);
    shift(1);
  }
  cout << len(ans) << '\n';
  for (auto i: ans) {
    cout << i << ' ';
  }

  return 0;
}