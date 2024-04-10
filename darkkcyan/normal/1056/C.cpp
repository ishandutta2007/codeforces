#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

template<class x> vector<typename x::value_type> tovec(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> tovec(u a, u b) { return vector<ptrtype(u)>(a, b); }

template<typename x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<typename u, typename v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}/*}}}*/

#define maxn 1010
int n, m;
int p[maxn * 2] = {0};
int pa[maxn * 2] = {0};
bool picked[maxn * 2];

int champleft;

int getchoice() {
  int c; cin >> c;
  if (c == -1) exit(0);
  if (--champleft == 0) exit(0);
  picked[c] = 1;
  return c;
}

void answer(int x) {
  cout << x << endl;
  if (--champleft == 0) exit(0);
  picked[x] = 1;
}

void del(int x) {
  pa[pa[x]] = 0;
  pa[x] = 0;
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep1(i, 2 * n) cin >> p[i];
  rep(i, m) {
    int u, v; cin >> u >> v;
    pa[u] = v;
    pa[v] = u;
  }
  champleft = 2 * n;

  int turn; cin >> turn;
  int juryc = 0;
  for (; ; turn = 3 - turn) {
    if (turn == 2) {
      juryc = getchoice();
      continue;
    }
    if (pa[juryc]) {
      answer(pa[juryc]);
      del(juryc);
      continue;
    }
    int maxi = 0;
    int okans = 0;
    rep1(i, 2 * n) {
      if (picked[i]) continue;
      if (p[maxi] < p[i]) maxi = i;
      if (!pa[i]) continue;
      if (p[okans] < p[i]) okans = i;
    }
    if (okans) {
      answer(okans);
      del(okans);
    } else {
      answer(maxi);
      if (pa[maxi]) del(maxi);
    }
  }

  return 0;
}