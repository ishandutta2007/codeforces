#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 2e5 + 7;
int n, pre[N], a[N];

void print() {
  int lol = 0;
  for (int i = 1; i <= n; i++) {
    lol = max(lol, a[i]);
    cout << a[i] << " ";
    assert(lol == pre[i]);
  }
  cout << "\n";
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) assert(a[i] == i);
}

set<int> st;

void mn() {
  for (int i = 1; i <= n; i++) a[i] = 0;
  for (int i = 1; i <= n; i++) st.insert(i);
  a[1] = pre[1];
  st.erase(a[1]);
  for (int i = 2; i <= n; i++) {
    if (pre[i] != pre[i - 1]) {
      a[i] = pre[i];
    } else {
      a[i] = *st.begin();
    }
    st.erase(a[i]);
  }
  print();
}

void mx() {
  for (int i = 1; i <= n; i++) a[i] = 0;
  for (int i = 1; i <= n; i++) st.insert(i);
  a[1] = pre[1];
  st.erase(a[1]);
  for (int i = 2; i <= n; i++) {
    if (pre[i] != pre[i - 1]) {
      a[i] = pre[i];
    } else {
      auto it = st.lower_bound(pre[i]);
      assert(it != st.begin());
      it--;
      a[i] = *it;
    }
    st.erase(a[i]);
  }
  print();
}

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> pre[i];
    }
    mn();
    mx();
  }
  return 0;
}