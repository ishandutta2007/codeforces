#include <iostream>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

map<pll, ll> dp;

// return a - !(a&1)
ll rep(ll a) {
  if(a&1) return a;
  return a-1;
}

//how many more people would it take to partition a gap of sz into ones all less than bound
ll close(ll sz, ll bound) {
  pll state(sz, bound);
  if(dp.count(state)) return dp[state];
  if(rep(sz) < bound)
    return dp[state] = 0;
  else
    return dp[state] = 1 + close((sz-1)/2,bound) + close(sz/2,bound);
}

// given that we have optimally closed gaps of bound+2 in a gap of sz, what is the k-th next position (0-indexed)
ll pos(ll sz, ll bound, ll k) {
  ll l = (sz-1)/2;
  ll r = sz/2;
  if(rep(sz) <= bound) {
			return l+k;
	}
  ll lc = close(l,bound) - close(l,bound+2);
  if(lc >= k) {
    return pos(l,bound,k);
  } else {
    return l + 1 + pos(r,bound,k-lc);
  }
}

ll solve2(ll n, ll k) {
  ll lo = 1, hi = n+1;
  while(lo < hi-1) {
    ll mid = (lo+hi+1)/2;
    ll c = close(n,mid);
    if(c >= k) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  //lo is the lowest num such that if we made all gaps < lo we would have reached the k-th position
  k -= close(n, lo+2);
  return pos(n,lo, k);
}

//handle corner cases of first or second chair
ll solve(ll n, ll k) {
  if(k == 1) return 1;
  if(k == 2) return n;
  return 1+solve2(n-2,k-2);
}

int main() {
  ios::sync_with_stdio(0);
  ll n,k;
  cin >> n >> k;
  cout << solve(n,k) << "\n";
  return 0;
}