#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

int n;
string a;
string b[111];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> a >> n;
  rep(i, n) cin >> b[i];
  rep(i, n) rep(f, n) {
    string t = b[i] + b[f];
    if (t.find(a) != string::npos) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  
  return 0;
}