#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef pair<int, int> p2;
typedef pair<int, p2> p3;

int a[100005], b[100005], c[100005], d[100005], n, m, k[100005];

vector<p2> par;
vector<p3> act;
set<int> sig;

// end, index
set<p2> valid_act;
int ans[100005];

int main() {
  cin >> n;
  fill(ans, ans+n, -1);
  for(int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    ++b[i];
    par.push_back(p2(a[i], i));
    // cout << a[i] << "." << b[i] <<endl;
    sig.insert(a[i]);
  }
  cin >> m;
  for(int i = 0; i < m; ++i) {
    cin >> c[i] >> d[i] >> k[i];
    ++d[i];
    act.push_back(p3(c[i], p2(0, i)));
    act.push_back(p3(d[i], p2(1, i)));
    // cout << c[i] << "." << d[i] <<endl;
    sig.insert(c[i]);
    sig.insert(d[i]);
  }

  sort(par.begin(), par.end());
  sort(act.begin(), act.end());
  int si = 0, ai = 0;

  for(set<int>::iterator it = sig.begin(); it != sig.end(); ++it) {
    int val = *it;
    //add new valids
    while(ai < act.size() && act[ai].first == val) {
      if(act[ai].second.first == 1) {
        valid_act.erase(p2(val, act[ai].second.second));
      } else {
        valid_act.insert(p2(d[act[ai].second.second], act[ai].second.second));
      }
      ++ai;
    }
    while(si < par.size() && par[si].first == val) {
      set<p2>::iterator best = valid_act.lower_bound(p2(b[par[si].second], -1));
      if(best == valid_act.end()) goto fail;
      int ind = best->second;
      ans[par[si].second] = ind;
      --k[ind];
      if(k[ind] == 0) {
        valid_act.erase(best);
      }
      ++si;
    }
  }
  cout << "YES\n";
  for(int i = 0; i < n; ++i)
    cout << ans[i]+1 << " ";
  cout << "\n";
  return 0;
  fail:;
  cout << "NO\n";
  return 0;

}