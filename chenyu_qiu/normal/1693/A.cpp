#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using vii = vector<vector<int>>;
using mii = map<int, int>;
#define in(a) for (auto &e : a) cin >> e
#define sz(x) int((x).size())
#define all(a) a.begin(), a.end()
#define ptp partition_point
#define F first
#define S second
#define Testcase ll t; cin >> t; while (t--)
#define nl "\n"
#define m_p make_pair
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n; 
    bool flag = true;
    vl a(n);
    cin >> a[0];
    int pt = ((a[0] == 0) ? 0 : -1);
    for (int i = 1; i < n; i++) {
      int x; cin >> x; a[i] = a[i - 1] + x;
      if (a[i] == 0 && pt == -1)  pt = i;
    }
    for (int i = 0; i < n; i++) {
      if (i > pt && a[i] != 0)  flag = false;
      if (a[i] < 0) flag = false;
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
}