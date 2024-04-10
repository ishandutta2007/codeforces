#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 205, MAXL = 1<<20;

char qq[MAXL];
char s[MAX][MAX];
P kamo[MAX][MAX];
vector <P> R[MAX][MAX];
int indeg[MAX][MAX];
int cik[MAX][MAX];
int imacik[MAX*MAX][10];
int brred, brstup;
int pr[10], ps[10];
int bio[MAX][MAX];
int dokle[MAX][MAX];
int imaq[MAXL][10];
int brc=1;

int Vani(int red, int stup)
{
  return red < 0 || red >= brred || stup < 0 || stup >= brstup;
}

void Osisaj()
{
  queue <P> Q;

  for (int i=0; i<brred; i++)
    for (int j=0; j<brstup; j++)
      if (!indeg[i][j])
        Q.push(P(i, j));

  for (; !Q.empty(); ) {
    P tmp = Q.front();
    bio[tmp.X][tmp.Y] = 1;
    Q.pop();
    P nn = kamo[tmp.X][tmp.Y];
    indeg[nn.X][nn.Y]--;
    if (!indeg[nn.X][nn.Y])
      Q.push(nn);
  }

  for (int i=0; i<brred; i++) {
    for (int j=0; j<brstup; j++) {
      if (!bio[i][j]) {
        int sz=0;
        for (P tmp=P(i, j); tmp != P(i, j) || !sz; sz++, tmp = kamo[tmp.X][tmp.Y]) {
          bio[tmp.X][tmp.Y] = 1;
          cik[tmp.X][tmp.Y] = brc;
          imacik[brc][s[tmp.X][tmp.Y] - '0'] = 1;
        }

        brc++;
      }
    }
  }
}

int Rijesi()
{
  queue <P> Q;
  memset(dokle, 0, sizeof dokle);

  int len = (int) strlen(qq);

  for (int i=0; i<=len; i++)
    for (int j=0; j<10; j++)
      imaq[i][j] = 0;

  for (int i=len-1; i>=0; i--) {
    imaq[i][qq[i] - '0'] = 1;
    for (int j=0; j<10; j++)
      imaq[i][j] |= imaq[i+1][j];
  }

  for (int i=0; i<brred; i++)
    for (int j=0; j<brstup; j++) {
      indeg[i][j] = (int)R[i][j].size();
      if (!indeg[i][j])
        Q.push(P(i, j));
    }

  for (; !Q.empty(); ) {
    P tmp = Q.front();
    Q.pop();

    int nd = dokle[tmp.X][tmp.Y];
    if (s[tmp.X][tmp.Y] == qq[nd])
      nd++;

    if (nd == len)
      return 1;

    P nn = kamo[tmp.X][tmp.Y];
    dokle[nn.X][nn.Y] = max(dokle[nn.X][nn.Y], nd);
    indeg[nn.X][nn.Y]--;
    if (!indeg[nn.X][nn.Y])
      Q.push(nn);
  }  

  for (int i=0; i<brred; i++) {
    for (int j=0; j<brstup; j++) {
      if (cik[i][j]) {
        int da = 1;
        int indc = cik[i][j];
        for (int k=0; k<10; k++)
          if (!imacik[indc][k] && imaq[dokle[i][j]][k])
            da = 0;
        
        if (da)
          return 1;
      }
    }
  }

  return 0;
}

int main()
{
  int brq;

  scanf("%d%d%d", &brred, &brstup, &brq);

  for (int i=0; i<brred; i++)
    scanf("%s", s[i]);

  for (int i=0; i<10; i++)
    scanf("%d%d", &pr[i], &ps[i]);

  for (int i=0; i<brred; i++) {
    for (int j=0; j<brstup; j++) {
      int nr = i + pr[s[i][j] - '0'];
      int ns = j + ps[s[i][j] - '0'];
      if (Vani(nr, ns))
        kamo[i][j] = P(i, j);
      else
        kamo[i][j] = P(nr, ns);

      indeg[kamo[i][j].X][kamo[i][j].Y]++;
      R[kamo[i][j].X][kamo[i][j].Y].push_back(P(i, j));
    }    
  }

  Osisaj();

  for (int i=0; i<brq; i++) {
    scanf("%s", qq);
    printf("%s\n", Rijesi() ? "YES" : "NO");
  }

  return 0;
}