#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, ka, kb;
  cin >> n >> m >> ka >> kb;
  if (ka >= m or kb >= n) {
    cout << "No" << '\n';
    return 0;
  }
  vi V(n+m,0);
  vi A1(ka);
  vi A2(kb);
  priority_queue<int> Q1,Q2;
  for (int i = 0; i < ka; ++i) {
    cin >> A1[i];
    --A1[i];
    ++V[A1[i]];
  }
  for (int i = 0; i < kb; ++i) {
    cin >> A2[i];
    --A2[i];
    ++V[A2[i]];
  }
  for (int i = 0; i < n; ++i) {
    if (V[i] == 0) Q2.push(-i);
  }
  for (int i = n; i < n+m; ++i) {
    if (V[i] == 0) Q1.push(-i);
  }
  vpi R;
  int inda = 0;
  int indb = 0;
  while (inda < ka or indb < kb) {
    if (indb < kb and !Q2.empty()) {
      int x = -Q2.top(); Q2.pop();
      R.push_back(pi(x, A2[indb]));
      --V[A2[indb]];
      if (V[A2[indb]] == 0) Q1.push(-A2[indb]);
      ++indb;
    }
    else if (inda < ka and !Q1.empty()) {
      int x = -Q1.top(); Q1.pop();
      R.push_back(pi(x, A1[inda]));
      --V[A1[inda]];
      if (V[A1[inda]] == 0) Q2.push(-A1[inda]);
      ++inda;
    }
    else {
      cout << "No" << '\n';
      return 0;
    }
  }
  if (Q1.empty() or Q2.empty()) {
    cout << "No" << '\n';
    return 0;
  }
  int x1 = -Q1.top(); Q1.pop();
  int y1 = -Q2.top(); Q2.pop();
  R.push_back(pi(x1,y1));
  while (!Q1.empty()) {
    int x = -Q1.top(); Q1.pop();
    R.push_back(pi(y1, x));
  }
  while (!Q2.empty()) {
    int x = -Q2.top(); Q2.pop();
    R.push_back(pi(x1, x));
  }
  cout << "Yes" << '\n';
  for (auto it : R) cout << it.first +1 << ' ' << it.second + 1 << '\n';
}