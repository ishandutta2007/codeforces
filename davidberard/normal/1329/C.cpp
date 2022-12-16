#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int a[1<<21], b[1<<21];
int r[1<<21], take[1<<21];
priority_queue<int, vector<int>, greater<int>> pq[1<<21];

int g, h;

void get_for(priority_queue<int, vector<int>, greater<int>>& q, int x) {
  if (x >= (1<<h)) return;
  q.push(a[x]);
  get_for(q, x*2);
  get_for(q, x*2+1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    cin >> h >> g;
    vector<int> v;
    ll sum = 0;
    for (int i=1; i<(1<<h); ++i) {
      cin >> a[i];
      v.push_back(a[i]);
    }
    for (int i=(1<<h); i<(1<<(h+1)); ++i) {
      a[i] = 0;
    }

    while (!pq[1].empty()) {
      pq[1].pop();
    }

    vector<int> ans;
    for (int i=(1<<(g-1)); i<(1<<g); ++i) {
      get_for(pq[i], i);
      r[i] = pq[i].top(); pq[i].pop();
      take[r[i]] = 1;
    }
    for (int i=(1<<(g-1))-1; i>=1; --i) {
      while (!pq[i*2+1].empty()) {
        pq[i*2].push(pq[i*2+1].top()); pq[i*2+1].pop();
      }
      swap(pq[i*2], pq[i]);
      pq[i].push(a[i]);
      while (pq[i].top() < max(r[i*2], r[i*2+1])) {
        pq[i].pop();
      }
      r[i] = pq[i].top(); pq[i].pop();
      take[r[i]] = 1;
    }

    for (int i=(1<<h)-1; i>=1; --i) {
      if (take[a[i]]) {
        take[a[i]] = 0;
        sum += a[i];
      } else {
        ans.push_back(i);
      }
    }

    cout << sum << "\n";
    for (int x : ans) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}