#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

int n, a, b;
string s;
vector<int> l;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> a >> b >> s;
  rep(i, n) if (s[i] == '*') s[i] = ' ';
  stringstream ss; ss << s;
  while (ss >> s) {
    l.push_back(len(s));
    //clog << len(s) << ' ';
  }
  //clog << endl;

  int ans = 0;
  for (auto&i: l) {
    int p = i / 2;
    p = min(p, min(a, b));
    a -= p;
    b -= p;
    ans += 2 * p;
    i -= 2 * p;
    //clog << p << ' ' << i << ' ' << a << ' ' << b<< endl;
  }
  
  a += b;
  
  for (auto& i: l) {
    if (!a) break;
    int p = min((i + 1) / 2, a);
    a -= p;
    i -= p;
    ans += p;
  }
  cout << ans;

  return 0;
}