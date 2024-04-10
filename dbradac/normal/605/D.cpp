#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<18;

struct str {
  int pocx, pocy, krajx, krajy, ind;
} p[MAX];

bool operator < (const str &a, const str &b)
{
  if (a.pocy != b.pocy)
    return a.pocy > b.pocy;
  return a.pocx > b.pocx;
}

vector <int> Fen[MAX];
int bio[MAX], odakle[MAX];
int n;
queue <int> Q;

void Stavi(int ind)
{
  for (int pos=p[ind].pocx+1; pos < MAX; pos += pos & -pos)
    Fen[pos].push_back(ind);
}

void Pobacaj(int pos, int gran, int vr, int od)
{
  for (pos++; pos; pos -= pos & -pos) {
    for (; !Fen[pos].empty(); ) {
      int tmp = Fen[pos].back();
      if (p[tmp].pocy > gran)
        break;

      Fen[pos].pop_back();
      if (bio[tmp] == -1) {
        bio[tmp] = vr;
        odakle[tmp] = od;
        Q.push(tmp);
      }
    }
  }
}

void Bfs()
{
  p[n] = str {0, 0, 0, 0, n};

  memset(bio, -1, sizeof bio);
  Q.push(n);
  bio[n] = 0;

  for (; !Q.empty(); ) {
    int tmp = Q.front();
    Q.pop();

    Pobacaj(p[tmp].krajx, p[tmp].krajy, bio[tmp] + 1, tmp);
  }
}

int main()
{
  scanf("%d", &n);
  vector <int> V;

  for (int i=0; i<n; i++) {
    scanf("%d%d%d%d", &p[i].pocx, &p[i].pocy, &p[i].krajx, &p[i].krajy);
    p[i].ind = i;
    V.push_back(p[i].pocx);
    V.push_back(p[i].krajx);
  }

  V.push_back(0);
  sort(V.begin(), V.end());

  for (int i=0; i<n; i++) {
    p[i].pocx = lower_bound(V.begin(), V.end(), p[i].pocx) - V.begin();
    p[i].krajx = lower_bound(V.begin(), V.end(), p[i].krajx) - V.begin();
  }

  sort(p, p + n);

  int kraj=0;
  for (int i=0; i<n; i++) {
    Stavi(i);
    if (p[i].ind == n-1)
      kraj = i;
  }

  Bfs();

  printf("%d\n", bio[kraj]);
  if (bio[kraj] != -1) {
    vector <int> R;
    for (int tmp=kraj; p[tmp].ind!=n; tmp=odakle[tmp])
      R.push_back(p[tmp].ind + 1);

    for (int i=(int) R.size()-1; i>=0; i--)
      printf("%d ", R[i]);
    printf("\n");
  }


  return 0;
}