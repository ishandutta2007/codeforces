#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
 
map<string, set<string>> a;
map<set<string>, vector<string>> b;
 
int main() {
  int n;
  cin >> n;
  F0R(i,n) {
    string s;
    cin >> s;
    int id = s.find('/', 7);
    if (id == string::npos) {
      a[s.substr(0, id)].insert("");
      continue;
    }
    a[s.substr(0, id)].insert(s.substr(id, s.size() - id));
  }
  for (auto i : a) b[i.s].pb(i.f);
  vector<vector<string>> ans;
  for (auto i : b) {
    if (i.s.size() > 1) {
      ans.pb(i.s);
    }
  }
  cout << ans.size() << endl;
  for (auto i : ans) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}