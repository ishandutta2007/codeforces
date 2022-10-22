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
vector<int> adj[MAXN];
vector<pii> graph;
bool prime (int n) {
  for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
  return 1;
}
int main() {
#ifdef LOCAL
    start = chrono::high_resolution_clock::now();
#endif
  int n,edges=0;
  scan(n);
  for (int i = 1; i <= n; i++) graph.push_back({i,i == n ? 1 : i+1}), edges++;
  //for (n=3;n<=1000;n++) {
  int threes = 0;
  while (1) {
      if (prime(edges+threes)) {
        for (int i = 1; threes && i + 3 <= n; i+=3) graph.push_back({i,i+2}), edges++, threes--;
        if (threes) graph.push_back({2,5}), threes--;
        assert(!threes);
        break;
      }
      threes++;

  }
 printf ("%d\n",graph.size());
 for (pii p : graph) printf ("%d %d\n",p.first,p.second);
  //}


#ifdef LOCAL
    printf ("Time: %fs\n",(chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start))/1e6);
#endif
    return 0;
}