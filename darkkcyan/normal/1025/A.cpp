#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  map<char, int> x;
  int n;
  string s;
  cin >> n >> s;
  if (n == 1) {
    cout << "Yes";
    return 0;
  }

  for (auto c: s) x[c]++;
  for (auto i: x) {
    if (i.yy > 1) {
      cout << "Yes";
      return 0;
    }
  }
  
  cout << "No";
  
  
  return 0;
}