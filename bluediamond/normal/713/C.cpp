#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  priority_queue<int> q;

  ll ret = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    x -= i;
    if (!q.empty() && q.top() > x) {
      ret += q.top() - x;
    }
    q.push(x);
    q.push(x);
    q.pop();
  }
  cout << ret << "\n";


}