#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
using namespace std::chrono;

int main() {
  auto start = high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  priority_queue<pair<int, int>> pq;
  stack<int> st;

  vector<pair<int, int>> ans;

  st.push(0);
  for (int i = 1; i < n; ++i)
    pq.emplace(a[i], i);

  while (!pq.empty() && !st.empty()) {
    int know = st.top();
    st.pop();

    if (a[know] == 0)
      continue;

    pair<int, int> top = pq.top();
    pq.pop();

    ans.emplace_back(know, top.second);
    --a[know];
    st.push(know);
    st.push(top.second);
  }

  if (!pq.empty()) {
    cout << -1 << endl;
  } else {
    cout << ans.size() << endl;
    for (pair<int, int>& it : ans)
      cout << it.first + 1 << " " << it.second + 1 << endl;
  }

  cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

  return 0;
}