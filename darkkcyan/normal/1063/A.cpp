#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

template<class x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<class u, class v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  string s; cin >> n >> s;
  int cnt['z' + 1] = {0};
  for (auto i: s) cnt[(int)i] ++;
  for (int i = 'a'; i <= 'z'; ++i) cout << string(cnt[i], (char)i);

  return 0;
}