#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

const int N = 2e5 + 5, inf = 1e7;

int n;
pair< pair<int, int>, pair<int, int> > event[N];
vector< int > ver;

long long val[N<<2], rm[N<<2];

void build(int id = 1, int l = 0, int r = n) {
  val[id] = rm[id] = 0;
  if(r - l  < 2)
    return;
  int mid = (l+r) >> 1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if(x >= r || l >= y) return;
  if(x <= l && r <= y) {
    rm[id] += v;
    return;
  }
  int mid = (l+r) >> 1, il = id<<1, ir = il|1;
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  val[id] = (rm[il] > 0 ? ver[mid]-ver[l] : val[il]) + (rm[ir] > 0 ? ver[r]-ver[mid] : val[ir]);
}


int main() {
  scanf("%d", &n);
  int m = 0;
  for(int i = 0; i<n; i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(b > d) {
      swap(a, c);
      swap(b, d);
    }
    if(a > c) {
      swap(a, c);
      swap(b, d);
    }
    ver.push_back(b);
    ver.push_back(d+1);
    event[m++] = {{a, 1}, {b, d+1}};
    event[m++] = {{c+1, -1}, {b, d+1}};
  }
  sort(ver.begin(), ver.end());
  ver.erase(unique(ver.begin(), ver.end()), ver.end());
  n = ver.size() - 1;
  sort(event, event+m);
  build();
  int last = event[0].x.x;
  long long ans = 0;
  for(int i = 0; i<m; ) {
    int now = event[i].x.x;
    ans += 1LL * (now - last) * (rm[1] > 0 ? ver.back()-ver[0] : val[1]);
    while(i < m && event[i].x.x == now) {
      int l = lower_bound(ver.begin(), ver.end(), event[i].y.x) - ver.begin(),
          r = lower_bound(ver.begin(), ver.end(), event[i].y.y) - ver.begin();
      update(l, r, event[i].x.y);
      i++;
    }
    last = now;
  }
  cout << ans << endl;
  return 0;
}