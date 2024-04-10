#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17, INF = 0x3f3f3f3f;

vector <P> V[MAX];
int dokr[MAX], odpoc[MAX];
int odakle[MAX], ukdulj[MAX];
ll setd[MAX];
int bio[MAX];
int n;
set <pair<ll, int> > S;

void BfsPoc(int poc, int polje[MAX], int bitna0)
{
  deque <int> Q;

  for (int i=0; i<MAX; i++)
    polje[i] = INF;

  memset(setd, -1, sizeof setd);
  memset(bio, 0, sizeof bio);
  polje[poc] = 0;
  setd[poc] = 0;
  S.insert(P(0, poc));

  for (; !S.empty(); ) {
    int tmp = S.begin()->Y;
    S.erase(S.begin());
    if (bio[tmp])
      continue;

    bio[tmp] = 1;
//    if (bitna0)
  //    printf("ASD %d %d\n", tmp, ukdulj[tmp]);

    for (int i=0; i<(int) V[tmp].size(); i++) {
      P nn = V[tmp][i];
      int ndist = polje[tmp];
      if (ndist || !bitna0 || nn.Y)
        ndist++;

      if (polje[nn.X] > ndist) {
        polje[nn.X] = ndist;
        if (!ndist && bitna0) {
          odakle[nn.X] = tmp;
          ukdulj[nn.X] = ukdulj[tmp] + 1;
        }
      }

      if (polje[nn.X] == ndist) {
        if (bitna0 && (ukdulj[nn.X] == -1 || ukdulj[nn.X] > ukdulj[tmp] + 1)) {          
          ukdulj[nn.X] = ukdulj[tmp] + 1;
          odakle[nn.X] = tmp;
        }
      }

      ll nset = (ll) ndist * MAX + ukdulj[nn.X];
      if (setd[nn.X] == -1) {
        S.insert(P(nset, nn.X));
        setd[nn.X] = nset;
      }
      else if (setd[nn.X] > nset) {
        S.erase(P(setd[nn.X], nn.X));
        S.insert(P(nset, nn.X));
        setd[nn.X] = nset;
      }
    }
  }

  ukdulj[poc] = -1;
}

void NadiPut()
{
  int da = 0;
  int done = 0;
  vector <int> Node[2];
  memset(bio, 0, sizeof bio);

  int best = dokr[0];
  for (int i=0; i<n; i++)
    if (!dokr[i])
      Node[0].push_back(i);

  for (int ind=0;; ind^=1) {
    int minn = INF;
    Node[1^ind].clear();

    for (int i=0; i<(int) Node[ind].size(); i++) {
      int tmp = Node[ind][i];
      if (!tmp) {
        done = 1;
        break;
      }

      for (int j=0; j<(int) V[tmp].size(); j++) {
        P nn = V[tmp][j];
        if (best == odpoc[nn.X] + dokr[nn.X] && dokr[nn.X] > dokr[tmp])
          minn = min(minn, nn.Y);
      }
    }    

    if (done)
      break;

    for (int i=0; i<(int) Node[ind].size(); i++) {
      int tmp = Node[ind][i];
      for (int j=0; j<(int) V[tmp].size(); j++) {
        P nn = V[tmp][j];
        if (best == odpoc[nn.X] + dokr[nn.X] && dokr[nn.X] > dokr[tmp] && nn.Y == minn) {
          if (!bio[nn.X] || ukdulj[nn.X] > ukdulj[tmp] + 1) {
            odakle[nn.X] = tmp;
            ukdulj[nn.X] = ukdulj[tmp] + 1;
            if (!bio[nn.X]) {
              Node[1^ind].push_back(nn.X);
              bio[nn.X] = 1;
            }
          }
        }
      }
    }

    da = 1;
    printf("%d", minn);
  }

  if (!da)
    printf("0");
  printf("\n");

  vector <int> R;

  for (int poz=0; poz!=n-1; poz = odakle[poz])
    R.push_back(poz);
  R.push_back(n-1);
  
  printf("%d\n", (int) R.size());
  for (int i=0; i<(int) R.size(); i++)
    printf("%d ", R[i]);
  printf("\n");
}

int main()
{
  int m;

  memset(odakle, -1, sizeof odakle);
  memset(ukdulj, -1, sizeof ukdulj);

  scanf("%d%d", &n, &m);

  for (int i=0; i<m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    V[a].push_back(P(b, c));
    V[b].push_back(P(a, c));
  }

  BfsPoc(0, odpoc, 0);
  BfsPoc(n-1, dokr, 1);
  
//  for (int i=0; i<n; i++)
  //  printf("%d   %d %d\n", i, dokr[i], ukdulj[i]);
//  exit(0);

  NadiPut();

  return 0;
}