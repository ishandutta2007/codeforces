#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> w(m);
  for (int i = 0; i < m; ++i) {
    std::string tmp(m, '0');
    tmp[i] = '1';
    std::cout << "? " << tmp << std::endl;
    std::cin >> w[i];
  }
  std::vector<int> id(m);
  std::iota(id.begin(), id.end(), 0);
  std::sort(id.begin(), id.end(), [&](int i, int j) {
    return w[i] < w[j];
  });
  std::string now(m, '0');
  int lst = 0;
  for (int i : id) {
    now[i] = '1';
    std::cout << "? " << now << std::endl;
    int s;
    std::cin >> s;
    if (s - lst != w[i]) {
      now[i] = '0';
    } else {
      lst = s;
    }
  }
  std::cout << "! " << lst << std::endl;
}