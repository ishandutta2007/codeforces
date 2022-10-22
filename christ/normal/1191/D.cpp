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
map<int,int> cnt;
int twos=0,two;
int main() {
  int n; ll tot = 0;
  scan(n);
  vector<int> stones(n);
  for (auto &a : stones) scan(a);
  sort(stones.begin(),stones.end());
  for (int i = 0; i < n; i++) {
    if (i && stones[i] == stones[i-1]) twos++, two = stones[i];
    tot += max(stones[i] - i,0);
  }
  if (twos >= 2 || (twos == 1 && (two == 0 || find(stones.begin(),stones.end(),two-1) != stones.end()))) return !printf ("cslnb\n");
  printf (tot&1? "sjfnb\n" : "cslnb\n");
  return 0;
}