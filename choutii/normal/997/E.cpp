#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

const int NX = 121234;

int n, q, a[NX], pos[NX]; LL ans[NX];
vector<pii> querys[NX];

int stack1[NX], stack1_n;
int stack2[NX], stack2_n;

struct seg_info {
  LL s; int v, ti, n, t;  
}T[NX << 2];

seg_info operator + (seg_info lhs, int rhs) {
  lhs.v += rhs; lhs.t += rhs;
  return lhs;
}

seg_info operator + (seg_info lhs, seg_info rhs) {
  seg_info ans;
  ans.v = min(lhs.v, rhs.v);
  ans.s = lhs.s + rhs.s;
  ans.n = 0;
  ans.ti = 0;
  if (ans.v == rhs.v)
    ans.n += rhs.n;
  if (ans.v == lhs.v)
    ans.n += lhs.n;
  return ans;
}

#define _l p << 1
#define _r (_l | 1)
#define mid (l + r >> 1)
void build(int p, int l, int r) {
  T[p].n = 1; T[p].v = l;
  if (l == r)
    return;
  build(_l, l, mid);
  build(_r, mid + 1, r);
}

void add_t(int p, int t) {
  T[p].ti += t; 
  T[p].s += (LL) t * T[p].n;  
}

void push_down(int p) {
  if(T[p].t) {
    T[_l] = T[_l] + T[p].t;
    T[_r] = T[_r] + T[p].t;
    T[p].t = 0;
  }
  if (T[p].ti) {
    if (T[p].v == T[_l].v)
      add_t(_l, T[p].ti);
    if (T[p].v == T[_r].v)
      add_t(_r, T[p].ti);
    T[p].ti = 0;
  }
}
void modify(int p, int l, int r, int ql, int qr, int x) {
  if (qr < l || ql > r)
    return;
  if (ql <= l && r <= qr) {
    T[p] = T[p] + x;
    return;    
  } 
  push_down(p);
  modify(_l, l, mid, ql, qr, x);
  modify(_r, mid + 1, r, ql, qr, x);
  T[p] = T[_l] + T[_r]; 
}

LL query(int p, int l, int r, int ql, int qr) {
  if(qr < l || ql > r)
    return 0;
  if(ql <= l && r <= qr)
    return T[p].s;
    
  push_down(p);
  return query(_l, l, mid, ql, qr) +
        query(_r, mid + 1, r, ql, qr);
}


void modify(int l, int r, int x) {
  modify(1, 1, n, l, r, x);
}

LL query(int l, int r) {
  return query(1, 1, n, l, r);
}

int main() {
  read(n);
  for (int i = 1; i <= n; i++)
//    a[i] = i;
//  random_shuffle(a + 1, a + n + 1);
    read(a[i]);
//  q = n;
  read(q);
  build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    int l, r; read(l); read(r);
    //int l = rand() % n + 1;
    //int r = rand() % n + 1;
    //if (l > r)
    //  swap(l, r); 
    querys[r].push_back(make_pair(l, i));
  }
  
  for (int i = 1; i <= n; i++) {
    int u, v;
    while (stack1_n && a[v = stack1[stack1_n]] < a[i]) {
      u = 1 + stack1[--stack1_n];
      modify(u, v, a[i] - a[v]);      
    }
    
    while (stack2_n && a[v = stack2[stack2_n]] > a[i]) {
      u = 1 + stack2[--stack2_n];
      modify(u, v, a[v] - a[i]);      
    }
    
    stack1[++stack1_n] = stack2[++stack2_n] = i;
    
    add_t(1, 1);
    for (auto q : querys[i])
      ans[q.second] = query(q.first, i);
  }
  
  for (int i = 1; i <= q; i++)
    printf("%lld\n", ans[i]);
  return 0;
}