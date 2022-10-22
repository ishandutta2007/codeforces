#include <bits/stdc++.h>
using namespace std;
#define min(...) minn(__VA_ARGS__)
#define max(...) maxx(__VA_ARGS__)
#define stringio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
char _;
typedef long long ll;
typedef pair<int,int> pii;
#define getchar_unlocked getchar
template<typename t>constexpr const t minn(const t x,const t y){return x<y?x:y;}
template<typename t,typename ...r>constexpr const t minn(const t x,const r ...xs){return minn(x,minn(xs...));}
template<typename t>constexpr const t maxx(const t x,const t y){return x>y?x:y;}
template<typename t,typename ...r>constexpr const t maxx(const t x,const r ...xs){return maxx(x,maxx(xs...));}
template <typename t> void scan (t& x) {do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MAXN = 100005;
int main() {
  ll n,k,m,sub = 0, op = 0;
  scan(n,m,k);
  vector<ll> sp(m);
  for (auto &a : sp) scan(a);
  for (int i = 0; i < m;) {
    ll cur = sp[i]; int og = i;
    auto au = --upper_bound(sp.begin(),sp.end(),((cur-sub-1)/k+1)*k+sub);
    op++;
    i = au - sp.begin() + 1;
    sub += i - og;
  }
  printf ("%lld\n",op);
  return 0;
}