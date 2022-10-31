#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

int n;
int iter = 11111;

int query(vector<int> s, vector<int> t, int v) {
  if(!iter) exit(0);
  iter--;
  cout << s.size() << endl;
  for(auto i : s) cout << i + 1 << " ";
  cout << endl;
  cout << t.size() << endl;
  for(auto i : t) cout << i + 1 << " ";
  cout << endl;
  cout << v + 1 << endl;
  int res;
  cin >> res;
  cerr << endl;
  return res;
}

int main() {
  cin >> n;
  vector<pair<int, int>> sub(n - 1);
  vector<int> to(n, -1);
  vector<int> sz(n);
  sz[0] = n;
  range(i, 1, n) {
    vector<int> s = {0};
    vector<int> t(n - 1);
    iota(t.begin(), t.end(), 1);
    sz[i] = query(s, t, i);
    sub[i - 1] =  make_pair(sz[i], i);
  }
  sort(sub.begin(), sub.end(), greater<pair<int, int>>());
  vector<vector<int>> edges(n);
  int cnt = 0;
  vector<int> pos(n, 1);
  while(cnt < n - 1 && sub[cnt].first == sub[0].first) {
    edges[0].push_back(sub[cnt].second);
    pos[0]++;
    cnt++;
  }
  if(sub[0].first > sz[0] / 2) to[0] = sub[0].second;
  function<void(int, int, bool)> solve = [&] (int v, int c, bool op) {
    if(~to[v] && op) {
      vector<int> s = {to[v]}, t = {c};
      if(pos[to[v]] + sz[c] <= sz[to[v]] && !query(s, t, v)) {
        vector<int> st;
        int sp = v;
        while(~to[sp] && pos[to[sp]] + sz[c] <= sz[to[sp]]) {
          st.push_back(sp);
          sp = to[sp];
        }
        int lo = 0, hi = st.size();
        while(hi - lo > 1) {
          int mid = (hi + lo) >> 1;
          s[0] = st[mid];
          if(query(s, t, to[st[mid]])) lo = mid;
          else hi = mid;
        }
        st.push_back(to[st.back()]);
        range(i, 0, hi) pos[st[i]]++;
        solve(st[hi], c, false);
        return;
      }
    }
    vector<int> st;
    for(auto i : edges[v]) {
      if(pos[i] + sz[c] <= sz[i] && i != to[v]) st.push_back(i);
    }
    int lo = 0, hi = st.size() + (pos[v] + sz[c] <= sz[v]);
    while(hi - lo > 1) {
      int mid = (hi + lo) >> 1;
      vector<int> s = {c};
      vector<int> t;
      range(i, 0, mid) t.push_back(st[i]);
      if(query(s, t, v) == mid) lo = mid;
      else hi = mid;
    }
    pos[v]++;
    if(lo == (int) st.size()) {
      edges[v].push_back(c);
      if(sz[c] > sz[v] / 2) to[v] = c;
    } else solve(st[lo], c, true);
  };
  while(cnt < n - 1) {
    solve(0, sub[cnt].second, true);
    cnt++;
  }
  cout << "ANSWER" << endl;
  range(i, 0, n) {
    for(auto j : edges[i]) cout << i + 1 << " " << j + 1 << endl;
  }
  return 0;
}