#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using ll = long long;
using pii = pair<long long, int>;
//#define int ll
const int MOD = 1000000007;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  vector<int> s; s.push_back(1);
  for(int i=1;i<n;i++){
    s.push_back(1);
    while(s.size() > 1 && s[s.size()-1] == s[s.size()-2]) {
      s.pop_back();
      s.back()++;
    }
  }
  for(int i=0;i<s.size();i++)
    cout<<s[i]<<" \n"[i==s.size()-1];
}