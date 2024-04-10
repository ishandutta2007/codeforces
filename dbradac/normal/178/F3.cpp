#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAXN = 2005, MAXL = 505;
const ll INF = 1e15;

int n;
char ss[MAXL];
string s[MAXN];
int lcp[MAXN];
ll dp[2*MAXN][MAXN];
map <P, int> M;
int indx=0;

int daj_ind(int a, int b)
{
  if (M.find(P(a, b)) != M.end()) return M[P(a, b)];
  assert(indx < 2*MAXN);
  return M[P(a, b)] = indx++;
}

ll rek(int l, int r, int ind, int k)
{
  assert(l <= r);
  if (dp[ind][k] != INF)
    return dp[ind][k];

  if (l == r) {
    dp[ind][0] = dp[ind][1] = 0;
    FOR(i, 2, MAXN) dp[ind][i] = -INF;
    return dp[ind][k];
  }

  P mn = {MAXN, MAXN};
  FOR(i, l, r)
    mn = min(mn, P(lcp[i], i));

  int l_ind = daj_ind(l, mn.Y);
  int r_ind = daj_ind(mn.Y+1, r);
  int sz_l = mn.Y - l + 1;
  int sz_r = r - mn.Y;
  
  REP(i, MAXN) dp[ind][i] = -INF;

  REP(lijevo, sz_l+1) {
    REP(desno, sz_r+1) {
      dp[ind][lijevo+desno] = max(dp[ind][lijevo+desno], rek(l, mn.Y, l_ind, lijevo) +
				  rek(mn.Y+1, r, r_ind, desno) + lijevo * desno * mn.X);
    }
  }
  
  return dp[ind][k];
}

int daj_lc(string &s1, string &s2)
{
  int len = (int) min(s1.size(), s2.size()), ret = 0;
  for (; ret < len && s1[ret] == s2[ret]; ret++);
  return ret;
}

int K;
void load()
{
  scanf("%d%d", &n, &K);
  REP(i, n) {
    scanf(" %s", ss);
    s[i] = ss;
  }
}

int main()
{
  load();
  
  sort(s, s + n);

  REP(i, n-1)
    lcp[i] = daj_lc(s[i], s[i+1]);

  REP(i, 2*MAXN) REP(j, MAXN) dp[i][j] = INF;

  printf("%lld\n", rek(0, n-1, daj_ind(0, n-1), K));

  return 0;
}