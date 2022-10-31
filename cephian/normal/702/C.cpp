#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> v;
const int N = 100005;
vector<ll> l,r;

ll INF = 1e12;

int main() {
  ios::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    v.push_back(pii(a,0));
  }
  for(int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    v.push_back(pii(a,1));
  }
  sort(v.begin(),v.end());
  ll prv = -1;
  for(int i = 0; i < v.size(); ++i) {
    if(v[i].second == 0) {
      if(prv == -1) l.push_back(INF);
      else l.push_back(v[i].first - v[prv].first);
    } else {
      prv = i;
    }
  }
  prv = -1;
  for(int i = v.size()-1; i >= 0; --i) {
    if(v[i].second == 0) {
      if(prv == -1) r.push_back(INF);
      else r.push_back(v[prv].first - v[i].first);
    } else {
      prv = i;
    }
  }
  reverse(r.begin(), r.end());
  ll mn = 0;
  for(int i = 0; i < l.size(); ++i) {
    if(l[i] == 0 || r[i] == 0) continue;
    mn = max(mn,min(l[i],r[i]));
  }
  cout << mn << "\n";
  return 0;
}