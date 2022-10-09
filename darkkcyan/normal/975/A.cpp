#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  set<set<char>> s;
  int n; cin >> n;
  string t;
  while (cin >> t) {
    set<char> ts;
    for(auto i: t) ts.insert(i);
    s.insert(ts);
  }
  cout << len(s);

  return 0;
}