#include <bits/stdc++.h>
using namespace std;
#define min(...) minn(__VA_ARGS__)
#define max(...) maxx(__VA_ARGS__)
#define stringio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(),(x).end()
#define getchar_unlocked getchar
char _;
typedef long long ll;
typedef pair<int,int> pii;
template<typename t>constexpr const t minn(const t x,const t y){return x<y?x:y;}
template<typename t,typename ...r>constexpr const t minn(const t x,const r ...xs){return minn(x,minn(xs...));}
template<typename t>constexpr const t maxx(const t x,const t y){return x>y?x:y;}
template<typename t,typename ...r>constexpr const t maxx(const t x,const r ...xs){return maxx(x,maxx(xs...));}
template <typename t> void scan (t& x) {do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MAXN = 100005;
chrono::high_resolution_clock::time_point start;
int main() {
#ifdef LOCAL
    start = chrono::high_resolution_clock::now();
#endif


  int n,tot=0,coal;
  scan(n);
  vector<int> a(n), gov;
  for (auto &au : a) scan(au), tot += au;
  coal = a[0];
  for (int i = 1; i < n; i++) if (a[i] * 2 <= a[0]) coal += a[i], gov.push_back(i+1);
  if (coal * 2 <= tot) return !printf ("0\n");
  printf ("%d\n1",gov.size()+1);
  for (int i : gov) printf (" %d",i);
  printf ("\n");



#ifdef LOCAL
    printf ("Time: %fs\n",(chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start))/1e6);
#endif
    return 0;
}