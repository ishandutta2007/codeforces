#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define rep(i,n) for (int i =-1; ++i < n; )
#define rep1(i,n) for (int i = 0; ++i <= n; )
#define sgn(x) ((x) < 0 ? -1 : (x) > 0)

string a, b, c;

map<char, char> ma;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> a >> b >> c;
  rep(i, sz(a)) ma[a[i]] = b[i];
  for (auto i: c) {
    if (!isalpha(i)) cout << i;
    else if (!islower(i)) cout << (char)::toupper(ma[::tolower(i)]);
    else cout << ma[i];
  }

  return 0;
}