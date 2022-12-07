#include <bits/stdc++.h>
using namespace std;

class PA {
private:
  static const int N = 300010;
  struct Node {
    int len, minlen;
    int ptr[3], fail;
    Node(int len = 0) : len(len), minlen(N), fail(0) { memset(ptr, 0, sizeof(ptr)); }
  } nd[N];

  int size, cnt;
  int cur;
  char s[N];

  int getfail(int x) {
    while (s[size - nd[x].len - 1] != s[size]) {
      x = nd[x].fail;
    }
    return x;
  }

public:
  PA() : size(0), cnt(0), cur(0) {
    nd[cnt] = Node(0);
    nd[cnt].fail = 1;
    nd[++cnt] = Node(-1);
    nd[cnt].fail = 0;
    s[0] = '$';
  }

  void extend(char c) {
    s[++size] = c;
    int now = getfail(cur);
    if (!nd[now].ptr[c - 'A']) {
      int tmp = ++cnt;
      nd[tmp] = Node(nd[now].len + 2);
      nd[tmp].fail = nd[getfail(nd[now].fail)].ptr[c - 'A'];
      nd[tmp].minlen = min(
        (nd[tmp].len >= 2 ? nd[tmp].len : nd[tmp].minlen),
        nd[nd[tmp].fail].minlen);
      nd[now].ptr[c - 'A'] = tmp;
    }
    cur = nd[now].ptr[c - 'A'];
  }

  int qlen() { return nd[cur].minlen; }
} A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  string s;
  long long answer = 0;
  cin >> n;
  cin >> s;
  vector<vector<int>> t(n, vector<int>(0));
  for (int i = n - 1; i >= 0; --i) {
    B.extend(s[i]);
    if (i + B.qlen() - 1 < n) {
      t[i + B.qlen() - 1].push_back(i);
    }
  }
  vector<int> c(n + 1, 0);
  auto modify = [&] (int x, int s) {
    for (; x <= n; x += x & (-x))
      c[x] += s;
  };
  auto query = [&] (int x) {
    int s = 0;
    for (; x > 0; x -= x & (-x))
      s += c[x];
    return s;
  };
  for (int i = 0; i < n; ++i) {
    A.extend(s[i]);
    for (auto l : t[i]) {
      modify(l + 1, 1);
    }
    if (i - A.qlen() + 1 >= 0) {
      answer += query(i - A.qlen() + 2);
    }
  }
  cout << answer << endl;
  return 0;
}