#include <bits/stdc++.h>
#define int long long

using namespace std;
 
struct SegTree {
  int n;
  vector<int> data, lazy;
  
  SegTree(const vector<int>& v) : 
      n(v.size()), data(4 * n), lazy(4 * n, 0) {
    build(1, 0, n - 1, v);
  }
 
  void build(int node, int b, int e, const vector<int>& v) {
    if (b == e) {
      data[node] = v[b];
      return;
    }
    int m = (b + e) / 2;
    build(node * 2, b, m, v);
    build(node * 2 + 1, m + 1, e, v);
    data[node] = min(data[node * 2], data[node * 2 + 1]);
  }
  
  void add(int node, int b, int e, int l, int val) {
    if (e < l) return;
    if (b >= l) {
      lazy[node] += val;
      data[node] += val;
      return;
    }
    int m = (b + e) / 2;
    add(node * 2, b, m, l, val);
    add(node * 2 + 1, m + 1, e, l, val);
    data[node] = min(data[node * 2], data[node * 2 + 1]) + lazy[node];
  }
 
  int pop(int node, int b, int e, int val) {
    if (b == e) {
      data[node] = 2e18;
      return b;
    }
    int m = (b + e) / 2;
    val -= lazy[node];
 
    int ret = -1;
    if (data[node * 2 + 1] == val)
      ret = pop(node * 2 + 1, m + 1, e, val);
    else ret = pop(node * 2, b, m, val);
    data[node] = min(data[node * 2], data[node * 2 + 1]) + lazy[node];
    return ret;
  }
 
  void Add(int l, int val) { add(1, 0, n - 1, l, val); }
  int Pop() { return pop(1, 0, n - 1, 0); }
};
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];
 
  SegTree st(v);
  for (int i = 1; i <= n; ++i) {
    int pos = st.Pop();
    v[pos] = i;
    st.Add(pos, -i);
  }
  
  for (int i = 0; i < n; ++i)
    cout << v[i] << " ";
  cout << endl;
 
  return 0;
}