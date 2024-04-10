#include <bits/stdc++.h>

using namespace std;

struct SegmentTreeMax{

  static const int N = 200020;

  int it[N << 2];
  int lazy[N << 3];

  #define mid ((l + r) >> 1)

  void Init(){
    memset(it, 0, sizeof it);
    memset(lazy, 0, sizeof lazy);
  }

  void push(int x){
    it[x] += lazy[x];
    lazy[x + x] += lazy[x];
    lazy[x + x + 1] += lazy[x];
    lazy[x] = 0;
  }

  void update(int x, int l, int r, int u, int v, int val){
    if(v < u) return;
    push(x);

    if(l > v || r < u) return;
    if(l >= u && r <= v){
      lazy[x] += val;
      push(x);      
      return;
    }
    update(x + x, l, mid, u, v, val);
    update(x + x + 1, mid + 1, r, u, v, val);
    it[x] = max(it[x + x], it[x + x + 1]);  
  }

  void modify(int x, int l, int r, int pos, int val){
    push(x);
    if(l > pos || r < pos) return;
    if(l == r) {
      it[x] = val;
      return;
    }
    modify(x + x, l, mid, pos, val);
    modify(x + x + 1, mid + 1, r, pos, val);
    it[x] = max(it[x + x], it[x + x + 1]);
  }

  int query(int x, int l, int r, int u, int v){
    push(x);
    if(u > v) return -1e9;
    if(l > v || r < u) return -1e9;
    if(l >= u && r <= v){
      return it[x];
    }
    int ret = max(query(x + x, l, mid, u, v), query(x + x + 1, mid + 1, r, u, v));
    it[x] = max(it[x + x], it[x + x + 1]);
    return ret;
  }
}seg;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector < int > a(n);
  vector < vector < int > > start(n), finish(n);
  vector < pair < int, int > > segments(m);
	
  for(auto &x : a) cin >> x;
  for(int i = 0; i < m; ++i) {
    auto &p = segments[i];
    cin >> p.first >> p.second;
    --p.first; 
    --p.second;
    start[p.first].push_back(i);
    finish[p.second].push_back(i);
  }

  for(int i = 0; i < n; ++i) {
    seg.modify(1, 0, n - 1, i, a[i]);
  }


  int ans = 0, pos = -1;

  for(int i = 0; i < n; ++i) {
    if(i) {
      for(int id : finish[i - 1]) {
        auto &p = segments[id];
        seg.update(1, 0, n - 1, p.first, p.second, 1);
      }
    }

    for(int id : start[i]) {
      auto &p = segments[id];
      seg.update(1, 0, n - 1, p.first, p.second, -1);
    //  cout << i << " : " << p.first << " " << p.second << endl;
    }



    if(ans < seg.it[1] - seg.query(1, 0, n - 1, i, i)) {
      ans = seg.it[1] - seg.query(1, 0, n - 1, i, i);
      pos = i;
    }
  }

  vector < int > choose;

  for(int i = 0; i < m; ++i) {
    if(segments[i].first <= pos && segments[i].second >= pos) choose.push_back(i);
  }

  cout << ans << endl << choose.size() << endl;

  for(int &x : choose) cout << x + 1 << " ";

  return 0;
}