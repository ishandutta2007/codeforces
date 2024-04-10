#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; ++qq) {
    int n, m, c, c0;
    cin >> n >> m >> c >> c0;
    vector<vector<int>> task;
    for (int i = 0; i < n; ++i) {
      int t, a, b;
      cin >> t >> a >> b;
      task.push_back(vector<int> {t, a, b});
    }
    task.push_back(vector<int> {0, c0, 0});
    task.push_back(vector<int> {m, 0, -1});
    sort(task.begin(), task.end());
    n = task.size();
    map<int, long long> remained;
    long long flow = 0;
    long long answer = 0;
    for (int i = 0; i <= n - 2; ++i) {
      remained[task[i][2]] += task[i][1];
      flow += task[i][1];

      long long  go = max(flow - c, 0ll);
      while (!remained.empty() && go > 0) {
        auto largest = --remained.end();
        auto got = min(go, largest -> second);
        go -= got;
        flow -= got;
        if (largest -> second == got) {
          remained.erase(largest);
        } else {
          largest -> second -= got;
        }
      }
      
      go = task[i + 1][0] - task[i][0];
      while (!remained.empty() && go > 0) {
        auto smallest = remained.begin();
        auto got = min(go, smallest -> second);
        go -= got;
        flow -= got;
        answer += got * smallest -> first;
        if (smallest -> second == got) {
          remained.erase(smallest);
        } else {
          smallest -> second -= got;
        }
      }
      if (go > 0) {
        answer = -1;
        break;
      }
    }
    cout << answer << endl;
  }

  return 0;
}