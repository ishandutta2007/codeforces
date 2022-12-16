#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<int> st;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    st.clear();
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
    }
    st.insert(a[0]);
    int curidx = 0;
    bool good = true;
    for (int i=1; i<a.size(); ++i) {
      int u = a[i];
      int cur = *st.find_by_order(curidx);
      //cerr << " " << curidx << " : " << cur << endl;
      if (u == cur) {
        continue;
      } else if (u < cur) {
        if (curidx == 0) {
          st.insert(u);
          continue;
        }
        int pr = *st.find_by_order(curidx-1);
        if (pr == u) {
          --curidx;
        } else if (pr < u) {
          st.insert(u);
        } else if (pr > u) {
          good = false;
          break;
        }
      } else if (u > cur) {
        if (curidx+1 == st.size()) {
          st.insert(u);
          ++curidx;
          continue;
        }
        int pr = *st.find_by_order(curidx+1);
        if (pr == u) {
          ++curidx;
        } else if (pr < u) {
          good = false;
          break;
        } else if (pr > u) {
          st.insert(u);
          ++curidx;
        }

      }
    }
    cout << (good ? "YES" : "NO") << "\n";
  }
  return 0;
}