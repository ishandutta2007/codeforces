#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = 100010;

int n, q, a[MaxN];
ll ans[MaxN];

struct query_t {
  int l, r, i;
  query_t() {
  }
  query_t(int l, int r, int i) : l(l), r(r), i(i) {
    
  }
}Q[MaxN];

const int B = 320;
bool cmp(query_t x, query_t y) {
  int u = x.l / B, v = y.l / B;
  return u != v ? u < v : x.r < y.r;
}

int c[MaxN], d[MaxN], q_t[MaxN]; vector<int> bigs;

inline void add(int i) {
  --d[c[a[i]]++];
  ++d[c[a[i]]];
}

inline void del(int i) {
  --d[c[a[i]]--];
  ++d[c[a[i]]];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  
  for (int i = 1; i <= n; i++) 
    ++c[a[i]];
  for (int i = 1; i < MaxN; i++)
    if (c[i] > B)
      bigs.push_back(i);
  for (int i = 1; i <= n; i++)
    --c[a[i]];
  scanf("%d", &q);
  for (int i = 1, l, r; i <= q; i++) {
    scanf("%d%d", &l, &r);
    Q[i] = query_t(l, r, i);
  }
  
  sort(Q + 1, Q + q + 1, cmp);
  int l = 1, r = 0;
  for (int i = 1; i <= q; i++) {
    while (l > Q[i].l)
      add(--l);
    while (r < Q[i].r) 
      add(++r);
    while (l < Q[i].l)
      del(l++);
    while (r > Q[i].r)
      del(r--);
    priority_queue<int, vector<int>, greater<int> > pq;
    for (auto x : bigs)
      if(c[x] > B) {
        pq.push(c[x]);
      }
    
    for (int i = 1; i <= B; i++)
      q_t[i] = d[i];
    ll ans = 0;
    int y = 0;
    for (int x = 1; x <= B; x++) {
      if (!q_t[x])
        continue;
      if (y) {
        --q_t[x];
        ans += x + y;
        if (x + y > B)
          pq.push(x + y);
        else
          ++q_t[x + y];
        y = 0;
      }
      
      if (q_t[x] & 1) 
        q_t[x] ^= 1,
        y = x;
      
      ans += q_t[x] * x;
      if ((x << 1) > B)
        for (int t = q_t[x] >> 1; t--; ) {
          pq.push(x << 1);
        }
      else
        q_t[x << 1] += q_t[x] >> 1, q_t[x] = 0; 
    }
    if (y)
      pq.push(y);
    while (!pq.empty()) {
      int x = pq.top(); pq.pop();
      if (pq.empty())
        break;
      int y = pq.top(); pq.pop();
      ans += x + y; pq.push(x + y);
    }
    ::ans[Q[i].i] = ans;
  } 
  for (int i = 1; i <= q; i++)
    printf("%lld\n", ans[i]);
  return 0;
}