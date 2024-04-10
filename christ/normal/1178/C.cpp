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
const int MAXN = 1005, MOD = 998244353;
int madd (int a, int b) {
  int sum = a+b;
  return sum >= MOD ? sum - MOD : sum;
}
void self_madd (int &a, int b) {a = madd(a,b);}
int mmult (int a, int b) {
  ll prod = (ll)a*b;
  return prod >= MOD ? prod%MOD : prod;
}
void self_mmult (int &a, int b) {a = mmult(a,b);}
chrono::high_resolution_clock::time_point start;
int ans[MAXN][MAXN];
int main() {
#ifdef LOCAL
    start = chrono::high_resolution_clock::now();
#endif

  int n,m;
  scan(n,m);
  ans[1][1] = 4;
  for (int i = 2; i <= max(n,m); i++) ans[1][i] = ans[i][1] = mmult(ans[1][i-1],2);
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= m; j++)
      ans[i][j] = madd(ans[i-1][j],ans[i][j-1]);
  printf ("%d\n",ans[n][m]);

#ifdef LOCAL
    printf ("Time: %fs\n",(chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start))/1e6);
#endif
    return 0;
}