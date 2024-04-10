#include <bits/stdc++.h>

template<typename Val, 
         typename VV = std::plus<>,
         typename Comp = std::less<>>
class seg_tree {
public:
  typedef std::size_t size_type;

private:
  constexpr static size_type enlarge(size_type n) {
    size_type res = 1;
    while (res < n) {
      res <<= 1;
    }
    return res;
  }

protected:
  const size_type n, en;

  VV vv;
  Comp comp;

  std::vector<Val> val;

  void up(size_type u) {
    val[u] = vv(val[u << 1], val[u << 1 | 1]);
  }

  template<typename Iter>
  void build(size_type u, size_type l, size_type r, Iter &it) {
    if (l + 1 == r) {
      val[u] = Val(*it);
      ++it;
      return;
    }
    size_type mid = (l + r) >> 1;
    build(u << 1, l, mid, it);
    build(u << 1 | 1, mid, r, it);
    up(u);
  }

  void modify(size_type u, size_type l, size_type r, 
              size_type x, const Val &v) {
    if (l + 1 == r) {
      val[u] = v;
      return;
    }
    size_type mid = (l + r) >> 1;
    if (x < mid) {
      modify(u << 1, l, mid, x, v);
    } else {
      modify(u << 1 | 1, mid, r, x, v);
    }
    up(u);
  }

  Val query(size_type u, size_type l, size_type r, 
            size_type L, size_type R) {
    if (L <= l && r <= R) {
      return val[u];
    }
    size_type mid = (l + r) >> 1;
    if (R <= mid) {
      return query(u << 1, l, mid, L, R);
    } else if (L >= mid) {
      return query(u << 1 | 1, mid, r, L, R);
    } else {
      return vv(query(u << 1, l, mid, L, R), 
                query(u << 1 | 1, mid, r, L, R));
    }
  }

  size_type lower_bound(size_type u, size_type l, size_type r, 
                        size_type L, size_type R,
                        Val &pre, const Val &v) {
    if (L <= l && r <= R) {
      const Val &tmp = vv(pre, val[u]);
      if (comp(tmp, v)) {
        pre = tmp;
        return r;
      }
    }
    if (l + 1 == r) {
      return l;
    }
    size_type mid = (l + r) >> 1;
    if (R <= mid) {
      return lower_bound(u << 1, l, mid, L, R, pre, v);
    } else if (L >= mid) {
      return lower_bound(u << 1 | 1, mid, r, L, R, pre, v);
    } else {
      size_type res = lower_bound(u << 1, l, mid, L, R, pre, v);
      if (res < mid) {
        return res;
      } else {
        return lower_bound(u << 1 | 1, mid, r, L, R, pre, v);
      }
    }
  }

  size_type upper_bound(size_type u, size_type l, size_type r, 
                        size_type L, size_type R,
                        Val &pre, const Val &v) {
    if (L <= l && r <= R) {
      const Val &tmp = vv(pre, val[u]);
      if (!comp(v, tmp)) {
        pre = tmp;
        return r;
      }
    }
    if (l + 1 == r) {
      return l;
    }
    size_type mid = (l + r) >> 1;
    if (R <= mid) {
      return upper_bound(u << 1, l, mid, L, R, pre, v);
    } else if (L >= mid) {
      return upper_bound(u << 1 | 1, mid, r, L, R, pre, v);
    } else {
      size_type res = upper_bound(u << 1, l, mid, L, R, pre, v);
      if (res < mid) {
        return res;
      } else {
        return upper_bound(u << 1 | 1, mid, r, L, R, pre, v);
      }
    }
  }

public:
  seg_tree() : seg_tree(0) {}

  seg_tree(size_type t_n, VV t_vv = VV(), Comp t_comp = Comp())
  : n(t_n), en(enlarge(n)), 
    vv(t_vv), comp(t_comp), val(en << 1) {}

  template<typename Iter>
  seg_tree(Iter first, Iter last, VV t_vv = VV(), Comp t_comp = Comp())
  : seg_tree(last - first, t_vv, t_comp) {
    if (n) {
      build(1, 0, n, first);
    }
  }

  size_type size() const {
    return n;
  }

  VV func_vv() const {
    return vv;
  }

  Comp func_comp() const {
    return comp;
  }

  void modify(size_type x, const Val &v) {
    modify(1, 0, n, x, v);
  }

  Val query(size_type l, size_type r) {
    if (l < r) {
      return query(1, 0, n, l, r);
    } else {
      return Val();
    }
  }

  size_type lower_bound(size_type l, size_type r, Val E, const Val &v) {
    return lower_bound(1, 0, n, l, r, E, v);
  }

  size_type upper_bound(size_type l, size_type r, Val E, const Val &v) {
    return upper_bound(1, 0, n, l, r, E, v);
  }
};

struct node {
  int l, r, cnt, ans;

  node() : l(), r(), cnt(), ans() {}

  node(int v) {
    if (v == 0) {
      l = r = 1;
      cnt = -1;
    } else {
      l = r = 0;
      cnt = 1;
    }
    ans = 0;
  }

  node(int t_l, int t_r, int t_cnt, int t_ans)
     : l(t_l), r(t_r), cnt(t_cnt), ans(t_ans) {
    if (cnt == 0 && l != r) {
      cnt = -1;
      l = r = 1;
    }
  }

  node operator+(const node &rhs) const {
    int s = ans + rhs.ans;
    if (cnt == -1 && rhs.cnt == -1) {
      return node(1, 1, 0, s);
    } else if (cnt == -1) {
      return node(!rhs.l, rhs.r, rhs.cnt, s + rhs.l);
    } else if (rhs.cnt == -1) {
      return node(l, !r, cnt, s + r);
    } else if (r == rhs.l) {
      return node(l, rhs.r, cnt + rhs.cnt, s + r);
    } else if (cnt < rhs.cnt) {
      return node(!l, rhs.r, rhs.cnt - cnt, s + cnt + l);
    } else if (cnt > rhs.cnt) {
      return node(l, !rhs.r, cnt - rhs.cnt, s + rhs.cnt + rhs.r);
    } else if (l == rhs.r) {
      return node(1, 1, -1, s + cnt + l);
    } else {
      return node(1, 1, 0, s + cnt);
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;
  std::string s;
  std::cin >> s;
  std::vector<int> p;
  std::vector<int> a;
  for (int i = 0; i < n; ++i) {
    if (i == 0 || s[i] == s[i - 1]) {
      a.push_back(1);
      p.push_back(i);
    } else {
      a.back() ^= 1;
    }
  }
  seg_tree<node> T(a.begin(), a.end());
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    --l;
    int pl = std::upper_bound(p.begin(), p.end(), l) - p.begin();
    int pr = std::lower_bound(p.begin(), p.end(), r) - p.begin() - 1;
    if (pl > pr) {
      std::cout << 1 << "\n";
      continue;
    }
    node tmp = pl == pr ? node() : T.query(pl, pr);
    node res = node((p[pl] - l) & 1) + tmp + node((r - p[pr]) & 1);
    std::cout << res.l + res.r + res.cnt + res.ans << "\n";
  }
}