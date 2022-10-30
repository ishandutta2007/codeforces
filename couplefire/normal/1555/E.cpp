#include <bits/stdc++.h>
using namespace std;

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

int m;

struct seg{
  vector<int> lazy, arr;

  void push(int id, int l, int r) {
    if(lazy[id]) {
      lazy[left] += lazy[id];
      arr[left] += lazy[id];
      lazy[right] += lazy[id];
      arr[right] += lazy[id];
      lazy[id] = 0;
    }
  }

  void update(int x, int y, int v, int id = 0, int l = 0, int r = m-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      lazy[id] += v;
      arr[id] += v;
      return;
    }

    push(id, l, r);
    update(x, y, v, left, l, mid);
    update(x, y, v, right, mid+1, r);

    arr[id] = min(arr[left], arr[right]);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n >> m;
  m--;

  int max = 0;
  vector<pair<int, pair<int, int> > > vec;

  for(int i = 0; i < n; i++) {
    int l, r, w;
    cin >> l >> r >> w;
    l--;
    r -= 2;
    max = std::max(w, max);
    vec.push_back({w, {l, r}});
  }

  sort(vec.begin(), vec.end());

  seg tree;
  tree.arr = tree.lazy = vector<int>(2*m-1, 0);

  int l = 0;

  for(int i = 0; i < n; i++) {
    tree.update(vec[i].second.first, vec[i].second.second, 1);

    if(tree.arr[0] > 0) {
      while(l < n) {
        tree.update(vec[l].second.first, vec[l].second.second, -1);
        if(tree.arr[0] == 0) {
          tree.update(vec[l].second.first, vec[l].second.second, 1);
          break;
        }
        l++;
      }
      max = min(max, vec[i].first-vec[l].first);
    }
  }

  cout << max << endl;

  return 0;
}