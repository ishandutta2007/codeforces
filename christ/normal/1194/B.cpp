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
const int MAXN = 1005;
vector<vector<bool>> grid;
vector<vector<int>> r, l, u, d;
int main() {
    int n,m,q,ans;
    scan(q);
    while (q--) {
      scan(n,m); ans = 0;
      grid.resize(n); r.resize(n); l.resize(n); d.resize(n); u.resize(n);
      for (int i = 0; i < n; i++) {
        grid[i].resize(m); r[i].resize(m); l[i].resize(m); d[i].resize(m); u[i].resize(m);
        for (int j = 0; j < m; j++)
          l[i][j] = r[i][j] = u[i][j] = d[i][j] = 0;
        }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          grid[i][j] = getchar_unlocked() == '*';
          if (!grid[i][j]) l[i][j] = j ? l[i][j-1] : 0;
          else l[i][j] = j ? l[i][j-1] + 1 : 1;
        }
        getchar_unlocked();
      }
      for (int i = 0; i < n; i++) {
        for (int j = m-1; j >= 0; j--) {
          if (!grid[i][j]) r[i][j] = j == m-1 ? 0 : r[i][j+1];
          else r[i][j] = j == m-1 ? 1 : r[i][j+1] + 1;
        }
      }
      for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
          if (!grid[i][j]) u[i][j] = i == 0 ? 0 : u[i-1][j];
          else u[i][j] = i == 0 ? 1 : u[i-1][j] + 1;
        }
      }
      for (int j = 0; j < m; j++) {
        for (int i = n-1; i >= 0; i--) {
          if (!grid[i][j]) d[i][j] = i == n-1 ? 0 : d[i+1][j];
          else d[i][j] = i == n-1 ? 1 : d[i+1][j] + 1;
          ans = max(ans,l[i][j] + r[i][j] + u[i][j] + d[i][j] - (grid[i][j] ? 3 : 0));
        }
      }
      printf ("%d\n",n+m-1-ans);
    }
    return 0;
}