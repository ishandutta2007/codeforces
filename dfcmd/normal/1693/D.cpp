#include <bits/stdc++.h>

struct node {
  int len, vl, vr;

  node() : len(), vl(), vr() {}

  node(int t_len, int t_vl, int t_vr) : len(t_len), vl(t_vl), vr(t_vr) {}
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n), p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    --a[i];
    p[a[i]] = i;
  }

  std::vector<node> l(n), r(n);
  l[0] = node(1, -1, n);
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] < a[i]) {
      if (l[i - 1].vr > a[i]) {
        l[i] = l[i - 1];
        ++l[i].len;
        l[i].vl = a[i - 1];
      } else {
        l[i] = node(i - p[l[i - 1].vr], a[i - 1], n);
      }
    } else {
      if (l[i - 1].vl < a[i]) {
        l[i] = l[i - 1];
        ++l[i].len;
        l[i].vr = a[i - 1];
      } else {
        l[i] = node(i - p[l[i - 1].vl], -1, a[i - 1]);
      }
    }
  }
  r[n - 1] = node(1, -1, n);
  for (int i = n - 2; i >= 0; --i) {
    if (a[i + 1] < a[i]) {
      if (r[i + 1].vr > a[i]) {
        r[i] = r[i + 1];
        ++r[i].len;
        r[i].vl = a[i + 1];
      } else {
        r[i] = node(p[r[i + 1].vr] - i, a[i + 1], n);
      }
    } else {
      if (r[i + 1].vl < a[i]) {
        r[i] = r[i + 1];
        ++r[i].len;
        r[i].vr = a[i + 1];
      } else {
        r[i] = node(p[r[i + 1].vl] - i, -1, a[i + 1]);
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += l[i].len;
  }
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i] < a[i + 1]) {
      if (l[i].vr < a[i + 1]) {
        if (l[i].vr > r[i + 1].vl) {
          ans += 1ll * (l[i].len - i + p[l[i].vr]) * r[i + 1].len;
        } else {
          ans += 1ll * (l[i].len - i + p[l[i].vr]) * (p[r[i + 1].vl] - i - 1);
        }
      }
    } else {
      if (l[i].vl > a[i + 1]) {
        if (l[i].vl < r[i + 1].vr) {
          ans += 1ll * (l[i].len - i + p[l[i].vl]) * r[i + 1].len;
        } else {
          ans += 1ll * (l[i].len - i + p[l[i].vl]) * (p[r[i + 1].vr] - i - 1);
        }
      }
    }
  }
  std::cout << ans << "\n";
}
/*
6
3 1 2 5 6 4
*/