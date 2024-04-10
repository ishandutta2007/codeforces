#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    int k;
    cin >> s >> k;
    int n = sz(s);
    vector<vector<int>> dig(10);
    for (int i = n-1; i >= 0; i--) {
      dig[s[i] - '0'].push_back(i);
    }
    int it = 0, rem = n;
    string ans = "";
    while(rem > k){
      for (int d = (it == 0); d <= 9; d++){
        if (dig[d].empty()) continue;
        int pos = dig[d].back();
        if (pos <= it + k){
          ans.push_back('0' + d);
          // remove all the starting guys
          for (int i = 0; i <= 9; i++) {
            while(!dig[i].empty() && dig[i].back() < pos) {
              dig[i].pop_back();
              k--;
              rem--;
            }
          }
          dig[d].pop_back();
          rem--;
          it = pos+1;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
}