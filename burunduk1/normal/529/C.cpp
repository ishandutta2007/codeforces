/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.03.21
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

const int N = 3e5 + 10;

struct Pnt   { int x, y; };
struct Query { int x1, x2, y1, y2, bad; };

struct Event {
  int x, y1, y2, type;
  bool operator < ( const Event &e) const {
    return mp(x, type) < mp(e.x, e.type);
  } 
};

int w, h, k, qn;
Pnt p[N];
Query q[N];
vector<Event> events;

struct Tree {
  int t[2 * N];

  void build() {
    memset(t, -1, sizeof(t));
  }

  void change( int i, int x ) {
    t[N + i] = x;
    for (i = (N + i) / 2; i > 0; i /= 2)
      t[i] = min(t[2 * i], t[2 * i + 1]);
  }

  int get( int l, int r ) {
    int res = INT_MAX;
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
      if ((l & 1) == 1) res = min(res, t[l++]);
      if ((r & 1) == 0) res = min(res, t[r--]);
    }
    return res;
  }
} tree;

int main() {
  scanf("%d%d%d%d", &w, &h, &k, &qn);
  forn(i, k)
    scanf("%d%d", &p[i].x, &p[i].y);
  forn(i, qn)
    scanf("%d%d%d%d", &q[i].x1, &q[i].y1, &q[i].x2, &q[i].y2);
  forn(t, 2) {
    forn(i, k) {
      p[i].x = w - p[i].x;
      swap(p[i].x, p[i].y);
    }
    forn(i, qn) {
      q[i].x1 = w - q[i].x1;
      q[i].x2 = w - q[i].x2;
      swap(q[i].x1, q[i].x2);
      swap(q[i].x1, q[i].y1);
      swap(q[i].x2, q[i].y2);
    }
    swap(w, h);

    events.clear();
    forn(i, k)
      events.pb({p[i].x, p[i].y, p[i].y, -1});
    forn(i, qn)
      events.pb({q[i].x2, q[i].y1, q[i].y2, i});
    sort(all(events));
    tree.build();

    int i;
    for (auto e : events)
      if (e.type == -1)
        tree.change(e.y1, e.x);
      else if (tree.get(e.y1, e.y2) < q[i = e.type].x1) {
        q[i].bad++;
/*
        printf("q[%d] : [%d,%d] x [%d,%d] bad : ", i, q[i].x1, q[i].x2, q[i].y1, q[i].y2);
        forn(j, k)
          printf("[%d,%d] ", p[j].x, p[j].y);
        puts("");
*/
      }
  }
  forn(i, qn)
    puts(q[i].bad == 2 ? "NO" : "YES");
  return 0;
}