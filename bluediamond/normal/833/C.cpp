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

const int C = 18;

vector<int> tokenizer(ll num) {
  vector<int> digits(C);
  for (int i = 0; i < C; i++) {
    digits[i] = num % 10;
    num /= 10;
  }
  reverse(digits.begin(), digits.end());
  return digits;
}

void print(vector<int> digits) {
  cout << "---> ";
  for (auto& d : digits) {
    cout << d;
  }
  cout << "\n";
}
bool has_one = false;
int frq;
int cntccc[10];
int sol;
int f[10];
vector<int> dl, dr;

bool is_ok(int p, bool isl, bool isr) {
  if (p == C) return 1;
  assert(isl || isr);
  if (isl && isr) {
    if (dl[p] == dr[p]) {
      if (!f[dl[p]]) return 0;

      f[dl[p]]--;
      bool ok = is_ok(p + 1, 1, 1);
      f[dl[p]]++;
      return ok;
    }
    for (int i = dl[p] + 1; i < dr[p]; i++) {
      if (f[i]) return 1;
    }
    assert(dl[p] <= dr[p]);
    bool ok = 0;
    if (f[dl[p]]) {
      f[dl[p]]--;
      ok |= is_ok(p + 1, 1, 0);
      f[dl[p]]++;
    }
    if (f[dr[p]]) {
      f[dr[p]]--;
      ok |= is_ok(p + 1, 0, 1);
      f[dr[p]]++;
    }
    return ok;
  }
  if (isl) {
    assert(!isr);
    for (int i = dl[p] + 1; i <= 9; i++) {
      if (f[i]) return 1;
    }
    if (!f[dl[p]]) return 0;
    f[dl[p]]--;
    bool ok = is_ok(p + 1, 1, 0);
    f[dl[p]]++;
    return ok;
  }
  else {
    assert(isr);
    for (int i = 0; i < dr[p]; i++) {
      if (f[i]) return 1;
    }
    if (!f[dr[p]]) return 0;
    f[dr[p]]--;
    bool ok = is_ok(p + 1, 0, 1);
    f[dr[p]]++;
    return ok;
  }
}

void bkt(int position, int total) {
  if (position == 10) {
    if (total != C) return;
    frq++;
    if (frq <= 1) return;
    for (int i = 0; i <= 9; i++) f[i] = cntccc[i];
    sol += is_ok(0, true, true) || (frq == 2 && has_one);

    return;
  }
  for (cntccc[position] = 0; cntccc[position] + total <= C; cntccc[position]++) {
    bkt(position + 1, cntccc[position] + total);
  }
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

  ll l, r;
  cin >> l >> r;
  if (r == (ll)1e18) {
    has_one = true;
    r--;
  }
  if (l <= r) {
    dl = tokenizer(l), dr = tokenizer(r);

   // print(tokenizer(l));
   // print(tokenizer(r));

    bkt(0, 0);
    sol += has_one;
  }
  else {
    sol = has_one;
  }
  cout << sol << "\n";
}