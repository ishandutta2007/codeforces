#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int TOUR = 1<<18, INF = 0x3f3f3f3f;

struct strq {
  int r1, r2, s1, s2, ind;
  strq () {}
} q[TOUR];

struct event {
  int st, red, stup; //st=0 rook, st=1 query
  strq qq;
  event (int st, int red, int stup, strq qq) : st(st), red(red), stup(stup), qq(qq) {}
  event () {}
};

bool operator < (event a, event b)
{
  if (a.red != b.red)
    return a.red < b.red;
  return a.st > b.st;
}

int t[2*TOUR];
int red[TOUR], stup[TOUR];
int brred, brstup;
int rje[TOUR];
int indexxR[TOUR];
int n, brq;
vector <event> V;
vector <int> R[TOUR];

void Stavi(int pos, int val)
{
  for (t[pos+TOUR] = val, pos = (pos + TOUR) / 2; pos; pos /= 2)
    t[pos] = max(t[2*pos], t[2*pos+1]);
}

int Vrati(int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin)
    return 0;
  if (lo >= begin && hi <= end)
    return t[pos];
  return max(Vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
             Vrati(2*pos+1, (lo+hi)/2, hi, begin, end) );
}

void Promjena()
{
  for (int i=0; i<n; i++)
    swap(red[i], stup[i]);

  for (int i=0; i<brq; i++) {
    swap(q[i].r1, q[i].s1);
    swap(q[i].r2, q[i].s2);
  }
}

void Init()
{
  V.clear();
  for (int i=0; i<TOUR; i++)
    R[i].clear();

  for (int i=0; i<n; i++) {
    V.push_back(event(0, red[i], stup[i], strq()));
    R[stup[i]].push_back(red[i]);
  }

  for (int i=0; i<brq; i++)
    V.push_back(event(1, q[i].r1, q[i].s1, q[i]));

  memset(t, INF, sizeof t);
  memset(indexxR, 0, sizeof indexxR);

  for (int i=0; i<TOUR; i++) {
    R[i].push_back(INF);
    sort(R[i].begin(), R[i].end());
    Stavi(i, R[i][0]);
  }

  sort(V.begin(), V.end());
}

int main()
{
  scanf("%d%d%d%d", &brred, &brstup, &n, &brq);

  for (int i=0; i<n; i++)
    scanf("%d%d", &red[i], &stup[i]);

  for (int i=0; i<brq; i++) {
    scanf("%d%d%d%d", &q[i].r1, &q[i].s1, &q[i].r2, &q[i].s2);
    q[i].ind = i;
  }
  
  for (int i=0; i<2; i++) {
    Init();
    for (int j=0; j<(int) V.size(); j++) {
      event tmp = V[j];
      if (!tmp.st) {
        indexxR[tmp.stup]++;
        Stavi(tmp.stup, R[tmp.stup][indexxR[tmp.stup]]);
      }
      else {
        if (Vrati(1, 0, TOUR, tmp.qq.s1, tmp.qq.s2+1) <= tmp.qq.r2)
          rje[tmp.qq.ind] = 1;
      }
    }
    
    Promjena();
  }

  for (int i=0; i<brq; i++) {
    if (rje[i])
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}