#include <bits/stdc++.h>
using namespace std;

vector<int> FindShortestPath(int n, int k) {
  vector<int> ones_change(n + 1, -1);
  ones_change[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int i = max(cur + k - n, 0); i <= cur; ++i) {
      int next = cur - 2 * i + k;
      if (0 <= next && next <= n && ones_change[next] == -1) {
        ones_change[next] = i;
        q.push(next);
      }
    }
  }

  if (ones_change.back() == -1) {
    return {};
  }
  vector<int> result;
  result.emplace_back(ones_change.back());
  int prev = n + 2 * ones_change.back() - k;

  while (prev != 0) {
    result.emplace_back(ones_change[prev]);
    prev = prev + 2 * ones_change[prev] - k;
  }

  reverse(result.begin(), result.end());
  return result;
}

int main() {
  int n, k;
  cin >> n >> k;
  auto path = FindShortestPath(n, k);
  if (path.empty()) {
    cout << -1 << std::endl;
    return 0;
  }

  int result{};
  vector<bool> summed(n);
  for (auto one_change : path) {
    int zero_change = k - one_change;

    cout << "?";
    for (size_t i = 0; i < summed.size(); ++i) {
      if (summed[i] && one_change) {
        --one_change;
        cout << " " << i + 1;
        summed[i] = !summed[i];
      } else if (!summed[i] && zero_change) {
        --zero_change;
        cout << " " << i + 1;
        summed[i] = !summed[i];
      }
    }

    cout << std::endl;

    int value;
    cin >> value;

    result ^= value;
  }

  cout << "! " << result << std::endl;

  return 0;
}