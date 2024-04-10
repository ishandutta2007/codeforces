#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
#define int long long


const int N = (int) 1e6 + 7;
int n, w, ret[N], len, jmen[N];

void add(int l, int r, int x) {jmen[l] += x;jmen[r + 1] -= x;}
struct Segment {int l, r;};
bool operator == (Segment a, Segment b) {return a.l == b.l && a.r == b.r;}
Segment get(int i) {return {max(-1LL, i - w - 1 + len) + 1, min(len + 1, i) - 1 + 1};}
bool eq(int i, int j) {return get(i) == get(j);}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> len;
    vector<int> v(2 + len, 0);
    for (int j = 1; j <= len; j++) cin >> v[j];
    deque<int> dq;
    int L = 0, R = -1;
    int l = 1;
    while (l <= w) {
      int r = l, lo = l + 1, hi = w;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (eq(l, mid)) {
          r = mid;
          lo = mid + 1;
        } else hi = mid - 1;
      }
      auto it = get(l);
      while (R < it.r) {
        R++;
        while (!dq.empty() && v[R] >= v[dq.back()]) dq.pop_back();
        dq.push_back(R);
      }
      while (dq.front() < it.l) dq.pop_front();
      add(l, r, v[dq.front()]);
      L = it.l;
      R = it.r;
      l = r + 1;
    }
  }
  for (int j = 1; j <= w; j++) {jmen[j] += jmen[j - 1]; cout << jmen[j] << " ";}
  cout << "\n";
}