#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

#define TRACE(x) cerr << #x <<  " = " << x << endl
#define _ << " " <<
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> P;

const ll LIM = 10004205361450474;
const int K = 10000;

ll cnt = 0;

P query(vector <ll> V) { //don't ask first and last(these are just for me)
  cnt++;
  assert(cnt <= 5);

  assert(V[0] >= (ll) V.size() - 2);
  assert(V.size() <= K+2);

  printf("%d ", (int) V.size()-2);
  FOR(i, 1, (int) V.size()-1)
    printf("%lld ", V[i]);
  printf("\n");
  fflush(stdout);

  int ind;
  scanf("%d", &ind);

  if (ind == -1) exit(0);
  if (ind == 0) return P(V[0], V[1] - 1);
  if (ind == (int) V.size() - 2) return P(V[V.size()-2]+1, V.back());
  return P(V[ind]+1, V[ind+1]-1);
}

ll what_next[6][K+1];
ll kolko_vel[6];

ll get_what(int step, ll val) { //last_covers
  assert(step < 5);
  if (val < K) return what_next[step][val] - 1;
  if (val >= LIM) return LIM;
  return val + kolko_vel[step] - 1;
}

void calc() {
  kolko_vel[1] = K;
  FOR(i, 2, 6)
    kolko_vel[i] = (K+1) * kolko_vel[i-1] + K;

  FOR(i, 1, K+1)
    what_next[1][i] = 2*i;

  FOR(step, 2, 6) {
    FOR(i, 1, K+1) {
      int kolko = min(i, K);
      ll nxt = get_what(step-1, i) + 1;

      REP(j, kolko)
        nxt = get_what(step-1, nxt+1) + 1;

      what_next[step][i] = nxt;
    }
  }
}

ll find_prev(int steps, ll val) { //min guy that covers me
  ll lo = 1, hi = val;
  for (; lo < hi; ) {
    ll mid = (lo + hi) / 2;

    if (get_what(steps, mid) >= val) hi = mid;
    else lo = mid + 1;
  }

  return lo;
}

void go(ll lo, ll hi, int steps) {
  if (steps == 1) {
    assert(lo + min((ll) K, lo)-1 >= hi);
    vector<ll> T = {lo};
    for (ll i=lo; i<=hi; i++) T.push_back(i);
    T.push_back(hi);
    query(T);
    assert(0);
  }

  vector <ll> T;
  for (ll tmp = hi; (ll) T.size() < min((ll) K, lo); ) {
    ll nov = max(1ll, find_prev(steps-1, tmp) - 1);
    T.push_back(nov);
    tmp = nov - 1;
  }

  reverse(T.begin(), T.end());
  T.insert(T.begin(), lo);
  T.push_back(hi);

  P dalje = query(T);
  go(dalje.X, dalje.Y, steps-1);
}

int main()
{
  calc();
  go(1, LIM, 5);

  return 0;
}