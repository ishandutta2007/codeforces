#include <bits/stdc++.h>

std::vector<int> dfs(std::vector<int> s) {
  if ((int)s.size() == 1) {
    return s;
  }
  std::vector<std::pair<int, int>> A, B;
  for (int i = 0; i < (int)s.size(); i += 2) {
    A.emplace_back(s[i], s[i + 1]);
    B.emplace_back(s[i + 1], s[i]);
  }
  std::sort(A.begin(), A.end());
  A.erase(std::unique(A.begin(), A.end()), A.end());
  std::sort(B.begin(), B.end());
  B.erase(std::unique(B.begin(), B.end()), B.end());
  std::vector<int> a, b;
  for (int i = 0; i < (int)s.size(); i += 2) {
    std::pair<int, int> ta(s[i], s[i + 1]), tb(s[i + 1], s[i]);
    a.push_back(std::lower_bound(A.begin(), A.end(), ta) - A.begin());
    b.push_back(std::lower_bound(B.begin(), B.end(), tb) - B.begin());
  }
  auto ra = dfs(a), rb = dfs(b);
  std::vector<int> sa(s.size()), sb(s.size());
  for (int i = 0; i < (int)s.size(); i += 2) {
    sa[i] = A[ra[i >> 1]].first, sa[i + 1] = A[ra[i >> 1]].second;
    sb[i] = B[rb[i >> 1]].first, sb[i + 1] = B[rb[i >> 1]].second;
  }
  if (std::lexicographical_compare(sa.begin(), sa.end(),
                                   sb.begin(), sb.end())) {
    return sa;
  } else {
    return sb;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  std::vector<int> a(1 << n);
  for (int i = 0; i < (1 << n); ++i) {
    a[i] = s[i] - 'a';
  }
  auto res = dfs(a);

  for (int i = 0; i < (1 << n); ++i) {
    std::cout << char(res[i] + 'a');
  }
  std::cout << "\n";
}