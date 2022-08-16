/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

pll get_prob(string s);
pll solve(ll n, ll k);
void fadd(pll& a, pll b);

int main() {
  fast_cin();
  int n; string p_inp;
  cin >> n >> p_inp;
  pll p = get_prob(p_inp);
  for (int k = 0; k <= n; ++k) {
    pll pk = solve(n, k);
    // cout << k << ' ' << pk.first << ' ' << pk.second << endl;
    if (pk.first * p.second >= pk.second * p.first) {
      cout << k << '\n';
      return 0;
    }
  }
}

pll get_prob(string s) {
  int dot = find(s.begin(), s.end(), '.') - s.begin();
  ll tmp = stoi(s.substr(0, dot));
  ll after = stoi(s.substr(dot + 1, s.size()));
  int times = max(0, int(s.size()) - dot - 1);
  int p10 = 1;
  while (times--) {
    p10 *= 10;
  }
  return {tmp * p10 + after, p10};
}

pll solve(ll n, ll k) {
  pll ans = {0, 1};
  fadd(ans, {k * (k - 1) * (k - 2), 6});
  fadd(ans, {k * (k - 1) * (n - k), 2});
  fadd(ans, {k * (n - k) * (n - k - 1), 4});
  ans.first *= 6;
  ans.second *= n * (n - 1) * (n - 2);
  return ans;
}

void fadd(pll& a, pll b) {
  if (!b.first) {
    return;
  }
  ll lcm = (a.second * b.second) / __gcd(a.second, b.second);
  a.first *= (lcm / a.second);
  b.first *= (lcm / b.second);
  a.first += b.first;
  a.second = lcm;
}