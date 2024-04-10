#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <fstream>

using namespace std;

const int INF = 1e+9;
const int LIM = 5e+5 + 10;
const int LEFT_BORDER = 0;
const int RIGHT_BORDER = LIM;
const int ROOT = 0;

struct node {
  int l, r, val;

  node() : l(-1), r(-1), val(INF) {
  }
};

struct query {
  int l, r, num;

  query() : l(0), r(0), num(-1) {
  }
};

bool operator <(const query& a, const query& b) {
  return a.l < b.l || (a.l == b.l && a.r < b.r);
}

istream& operator >>(istream& in, query& q) {
  in >> q.l >> q.r;
  --q.l;
  --q.r;
  return in;
}

node tree[3 * LIM];
int size = 1;

unordered_map <int, int> last_pos;
int ans[LIM];
int next_pos[LIM];
query queries[LIM];

void change(int vertex, int lb, int rb, int pos, int val) {
  if (lb == rb) {
    tree[vertex].val = val;
  } else {
    int med = (lb + rb) / 2;
    if (pos <= med) {
      if (tree[vertex].l == -1)
        tree[vertex].l = size++;
      change(tree[vertex].l, lb, med, pos, val);
    } else {
      if (tree[vertex].r == -1)
        tree[vertex].r = size++;
      change(tree[vertex].r, med + 1, rb, pos, val);
    }
    tree[vertex].val = INF;
    if (tree[vertex].l != -1)
      tree[vertex].val = min(tree[vertex].val, tree[tree[vertex].l].val);
    if (tree[vertex].r != -1)
      tree[vertex].val = min(tree[vertex].val, tree[tree[vertex].r].val);
  }
}

int get_ans(int vertex, int lb, int rb, int query_lb, int query_rb) {
  if (vertex == -1)
    return INF;
  int res = INF;
  if (lb == query_lb && rb == query_rb) {
    res = tree[vertex].val;
  } else {
    int med = (lb + rb) / 2;
    if (query_rb <= med) {
      res = get_ans(tree[vertex].l, lb, med, query_lb, query_rb);
    } else if (query_lb > med) {
      res = get_ans(tree[vertex].r, med + 1, rb, query_lb, query_rb);
    } else {
      res = get_ans(tree[vertex].l, lb, med, query_lb, med);
      res = min(res, get_ans(tree[vertex].r, med + 1, rb, med + 1, query_rb));
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  //ifstream cin("input.txt");
  int n, m;
  cin >> n >> m;
  int tmp;
  for (int i = 0; i < n; ++i) {
    next_pos[i] = INF;
    cin >> tmp;
    if (last_pos.find(tmp) == last_pos.end()) {
      change(ROOT, LEFT_BORDER, RIGHT_BORDER, i, INF);
      last_pos[tmp] = i;
    } else {
      change(ROOT, LEFT_BORDER, RIGHT_BORDER, i, i - last_pos[tmp]);
      next_pos[last_pos[tmp]] = i;
      last_pos[tmp] = i;
    }
  }

  for (int i = 0; i < m; ++i) {
    cin >> queries[i];
    queries[i].num = i;
  }
  sort(queries, queries + m);

  int next_q = 0;
  for (int i = 0; next_q < m; ++i) {
    while (next_q < m && queries[next_q].l == i) {
      ans[queries[next_q].num] = get_ans(ROOT, LEFT_BORDER, RIGHT_BORDER, i, queries[next_q].r);
      ++next_q;
    }
    if (next_pos[i] != INF)
      change(ROOT, LEFT_BORDER, RIGHT_BORDER, next_pos[i], INF);
  }

  for (int i = 0; i < m; ++i)
    if (ans[i] == INF)
      cout << "-1\n";
    else
      cout << ans[i] << '\n';

  return 0;
}