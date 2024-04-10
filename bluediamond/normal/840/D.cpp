#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 

bool home = true;
using namespace std;
typedef long long ll;

const int N = (int)3e5 + 7;
const int C = 7;
const int kek = 100;
int n;
int v[N];
int q;

struct Q {
  int l;
  int r;
  int k;
  int i;
  int ans = -1;
};

bool cmp1(Q a, Q b) {
  if (a.l / kek == b.l / kek) return a.r < b.r;
  return a.l < b.l;
}

bool cmp2(Q a, Q b) {
  return a.i < b.i;
}

Q qs[N];
int f[N];



mt19937 rng((long long)(new char));


void add(int i) {
  f[v[i]]++;
}

void del(int i) {
  f[v[i]]--;
}

int l, r;

void bring(int x, int y) {
  int ff = max(x, l), ss = min(y, r);
  if (ff <= ss) {
    while (l < ff) del(l++);
    while (ss < r) del(r--);
    while (x < l) add(--l);
    while (r < y) add(++r);
  }
  else {
    for (int j = l; j <= r; j++) del(j);
    l = x;
    r = y;
    for (int j = l; j <= r; j++) add(j);
  }
  assert(l == x && r == y);

}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= q; i++) {
    cin >> qs[i].l >> qs[i].r >> qs[i].k;
    qs[i].i = i;
  }
  sort(qs + 1, qs + q + 1, cmp1);
  l = r = 1;
  add(1);
  for (int i = 1; i <= q; i++) {
    bring(qs[i].l, qs[i].r);
    for (int j = 1; j <= 100; j++) {
      int x = v[qs[i].l + rng() % (qs[i].r - qs[i].l + 1)];
      if (qs[i].ans == -1 || x < qs[i].ans) {
        if (f[x] * qs[i].k > qs[i].r - qs[i].l + 1) {
          qs[i].ans = x;
        }
      }
    }
  }
  sort(qs + 1, qs + q + 1, cmp2);
  
  for (int i = 1; i <= q; i++) {

    cout << qs[i].ans << "\n";
  }

}