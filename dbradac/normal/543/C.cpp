#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;
const int MAX = 21, INF = 0x3f3f3f3f;

struct str {
  int st, val;
  str (int st, int val) : st(st), val(val) {}
  str () {}
};

bool operator < (str a, str b)
{
  if (a.val != b.val)
    return a.val < b.val;
  return a.st > b.st;
}

vector <P> V;
int p[MAX][MAX];
int minn[MAX];
int bio[1<<MAX];
int n, m;
char s[MAX+1][MAX+1];
set <str> S;

int Dijkstra(int poc)
{
  memset(bio, INF, sizeof bio);
  bio[poc] = 0;

  S.insert(str(poc, 0));

  for (; !S.empty(); ) {
    set <str> :: iterator it = S.begin();
    if (it->st == ((1<<m) - 1))
      return it->val;

    for (int i=0; i<(int) V.size(); i++) {
      P tmp = V[i];
      int nst = it->st | tmp.X;
      int nval = tmp.Y + it->val;

      if (bio[nst] > nval) {
        if (bio[nst] != INF)
          S.erase(str(nst, bio[nst]));

        bio[nst] = nval;
        S.insert(str(nst, nval));
      }
    }
    S.erase(it);
  }

  return -1;
}

int main()
{
  scanf("%d%d", &m, &n); //m = broj rijeci, n = broj stupaca

  for (int i=0; i<m; i++)
    scanf("%s", s[i]);

  for (int i=0; i<m; i++)
    for (int j=0; j<n; j++)
      scanf("%d", &p[i][j]);

  memset(minn, INF, sizeof minn);

  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      minn[j] = min(minn[j], p[j][i]);

  for (int i=0; i<m; i++)
    V.push_back(P((1<<i), minn[i]));

  int poc=0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<26; j++) {
      int tmp = 0, sum = 0, maxx = 0;
      for (int k=0; k<m; k++) {
        if (s[k][i] == 'a' + j) {
          tmp |= (1<<k);
          sum += p[k][i];
          maxx = max(maxx, p[k][i]);
        }
      }
      
      if (sum == maxx)
        poc |= tmp;
      else
        V.push_back(P(tmp, sum - maxx));
    }
  }

  printf("%d\n", Dijkstra(poc));

  return 0;
}