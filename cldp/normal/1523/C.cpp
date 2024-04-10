#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    stack<int> st;
    string s;
    st.push(1);
    s.push_back('1');
    cout << s << '\n';
    s.push_back('.');
    for (int i = 1; i < n; ++i) {
      if (x[i] == 1) {
        s.push_back('1');
        st.push(x[i]);
      } else {
        while (st.top() + 1 != x[i]) {
          st.pop();
          s.pop_back();
          while (!s.empty() && s.back() != '.') s.pop_back();
        }
        st.pop();
        st.push(x[i]);
        s.pop_back();
        while (!s.empty() && s.back() != '.') s.pop_back();
        s = s + to_string(x[i]);
      }
      cout << s << "\n";
      s.push_back('.');
    }
  }
  return 0;
}