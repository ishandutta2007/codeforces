#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

#define MP(a, b) make_pair(a, b)
#define X first
#define Y second

const int MAX = 22, KVAD = MAX * MAX;
const int S = 0, M = 1, POZ1 =  KVAD + 1, POZ2 = 2 * KVAD + 1, F = 3 * KVAD + 1, T = 4 * KVAD + 1, BRNODE = 4 * KVAD + 2;

struct str {
  P poz;
  int brz;
  str (P poz, int brz) : poz(poz), brz(brz) {}
  str () {}
} m[KVAD], f[KVAD];

struct strev {
  int a, b;
  ll t;
  strev (int a, int b, ll t) : a(a), b(b), t(t) {}
  strev () {}
} ev[BRNODE*BRNODE];

bool operator < (const strev &a, const strev &b)
{
  return a.t < b.t;
}

char s[MAX][MAX+1];
int p[MAX][MAX];
int poz[MAX][MAX];
int udalj[MAX][MAX][MAX][MAX];
int brred, brstup;
int edge[MAX][MAX][MAX][MAX];
ll distm[KVAD][MAX][MAX], distf[KVAD][MAX][MAX];
int pr[4] = {1, 0, -1, 0}, ps[4] = {0, 1, 0, -1};
int e[BRNODE][BRNODE];
int bio[BRNODE], odakle[BRNODE];
int matched=0, smatched;
vector <P> V;
queue <P> Q;

int Moze(int red, int stup)
{
  return red >= 0 && red < brred && stup >= 0 && stup < brstup && s[red][stup] == '.';
}

void Bfs(int pocr, int pocs)
{
  udalj[pocr][pocs][pocr][pocs] = 0;
  Q.push(MP(pocr, pocs));

  for (; !Q.empty(); ) {
    P tmp = Q.front();
    Q.pop();
    for (int i=0; i<4; i++) {
      P novi = MP(tmp.X + pr[i], tmp.Y + ps[i]);
      if (Moze(novi.X, novi.Y) && udalj[pocr][pocs][novi.X][novi.Y] == -1) {
        udalj[pocr][pocs][novi.X][novi.Y] = udalj[pocr][pocs][tmp.X][tmp.Y] + 1;
        Q.push(novi);
      }
    }
  }
}

void InputC(str polje[KVAD], int n)
{
  for (int i=0; i<n; i++) {
    scanf("%d%d%d", &polje[i].poz.X, &polje[i].poz.Y, &polje[i].brz);
    polje[i].poz.X--;
    polje[i].poz.Y--;
  }
}

void Dist(str polje[KVAD], ll rje[KVAD][MAX][MAX], int n)
{
  for (int i=0; i<n; i++)
    for (int j=0; j<brred; j++)
      for (int k=0; k<brstup; k++)
        rje[i][j][k] = (ll) udalj[polje[i].poz.X][polje[i].poz.Y][j][k] * polje[i].brz;
}

int Dfs(int node)
{
  bio[node] = 1;

  if (node == T)
    return 1;

  for (int i=0; i<BRNODE; i++) {
    if (e[node][i] && !bio[i]) {
      odakle[i] = node;
      if (Dfs(i))
        return 1;
    }
  }

  return 0;
}

int MaxFlow()
{
  for (;;) {
    memset(bio, 0, sizeof bio);
    if (!Dfs(S))
      return matched;
    
    matched++;
    for (int i=T; i!=S;) {
      int od = odakle[i];
      e[od][i] = 0;
      e[i][od] = 1;
      V.push_back(MP(i, od));
      V.push_back(MP(od, i));
      i = od;
    }
  }
}

int main()
{
  int brm, brf, n, tr, ts, tv;

  scanf("%d%d%d%d", &brred, &brstup, &brm, &brf);

  if (brm != brf - 1 && brf != brm - 1) {
    printf("-1\n");
    return 0;
  }

  for (int i=0; i<brred; i++)
    scanf("%s", s[i]);

  n = max(brm, brf);
  scanf("%d%d%d", &tr, &ts, &tv); tr--; ts--; 
  if (brm > brf)
    f[n-1] = str(MP(tr, ts), tv);
  else
    m[n-1] = str(MP(tr, ts), tv);

  InputC(m, brm);
  InputC(f, brf);

  memset(udalj, -1, sizeof udalj);

  for (int i=0; i<brred; i++)
    for (int j=0; j<brstup; j++)
      if (s[i][j] == '.')
        Bfs(i, j);
  
  for (int i=0; i<n; i++)
    e[S][M+i] = e[F+i][T] = 1;

  for (int j=0; j<brred; j++)
    for (int k=0; k<brstup; k++)
      e[POZ1+j*brstup+k][POZ2+j*brstup+k] = 1;

  Dist(m, distm, n);
  Dist(f, distf, n);
  
  int brev=0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<brred; j++)
      for (int k=0; k<brstup; k++) {
        if (distm[i][j][k] >= 0)
          ev[brev++] = strev(M+i, POZ1+j*brstup+k, distm[i][j][k]);
      }

    for (int j=0; j<brred; j++)
      for (int k=0; k<brstup; k++)
        if (distf[i][j][k] >= 0)
          ev[brev++] = strev(POZ2+j*brstup+k, F+i, distf[i][j][k]);
  }
  
  sort(ev, ev + brev);
  
  for (int i=0; ; i+=KVAD) {
    if (MaxFlow() == n) {
      if (!i) {
        printf("0\n");
        break;
      }
  
      for (int j=0; j<(int) V.size(); j++)
        e[V[j].X][V[j].Y] ^= 1;
      matched = smatched;
      for (int j=i-KVAD;; j++) {
        e[ev[j].a][ev[j].b] = 1;
        if (MaxFlow() == n) {
          printf("%I64d\n", ev[j].t);
          break;
        }
      }
      break;
    }
  
    if (i >= brev) {
      printf("-1\n");
      break;
    }
    
    V.clear();
    smatched = matched;
    for (int j=i; j<brev && j<i+KVAD; j++) {
      e[ev[j].a][ev[j].b] = 1;
      V.push_back(MP(ev[j].a, ev[j].b));
    }
  }
  
  return 0;
}