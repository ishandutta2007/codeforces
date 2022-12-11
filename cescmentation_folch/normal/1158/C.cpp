#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi N(n+1);
    for (int i = 1; i <= n; ++i) cin >> N[i];
    vi P(n+1);
    int cont = 1;
    stack<pi> S;
    bool pot = true;
    int ind = 1;
    while (ind <= n+1 and pot) {
      while (!S.empty() and S.top().first <= ind) {
        int x = S.top().second;
        S.pop();
        P[x] = cont++;
      }
      if (ind == n+1) break;
      if (N[ind] == -1) P[ind] = cont++;
      else {
        if (!S.empty() and S.top().first < N[ind]) pot = false;
        S.push(pi(N[ind],ind));
      }
      ++ind;
    }
    if (!pot) cout << -1 << '\n';
    else {
      for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << P[i];
      }
      cout << '\n';
    }
  }
}