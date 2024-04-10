#include <bits/stdc++.h>

using namespace std;

vector<int> manacher(vector<int> a) {
  int n = a.size(), m = (n << 1) - 1;
  vector<int> b(m, -1), p(m, 0);
  for (int i = 0; i < n; ++i) {
    b[i << 1] = a[i];
  }
  int x = 0;
  for (int i = 1; i < m; ++i) {
    if (i <= x + p[x]) {
      p[i] = min(p[(x << 1) - i], x + p[x] - i);
    }
    while (i - p[i] - 1 >= 0 && i + p[i] + 1 < m && b[i - p[i] - 1] == b[i + p[i] + 1]) {
      ++p[i];
    }
    if (i + p[i] >= x + p[x]) {
      x = i;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (i - p[i] == 0 || i + p[i] == m - 1) {
      ++p[i];
    }
  }
  for (int i = 0; i < m; ++i) {
    p[i] >>= 1;
  }
  return p;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<int> b(n);
  for (int i = 0; i < n - 1; ++i) {
    b[i] = a[i + 1] - a[i];
  }
  b[n - 1] = (a[0] + m - a[n - 1]) % m;
  vector<int> p = manacher(b);
  vector<int> answer;
  
  auto palindrome = [&](int l, int r) {
    return l == r || p[l + r - 1] >= r - l >> 1;
  };

  for (int i = 0; i < n; ++i) {
    if (palindrome(0, i) && palindrome(i, n)) {
      answer.push_back((a[0] + a[i]) % m);
    }
  }
  printf("%d\n", answer.size());
  if (!answer.empty()) {
    vector<int> temp;
    int p = min_element(answer.begin(), answer.end()) - answer.begin();
    for (int j = p; j < answer.size(); ++j) {
      temp.push_back(answer[j]);
    }
    for (int j = 0; j < p; ++j) {
      temp.push_back(answer[j]);
    }
    for (int j = 0; j < temp.size(); ++j) {
      printf("%d%c", temp[j], j == temp.size() - 1 ? '\n' : ' ');
    }
  }
  return 0;
}