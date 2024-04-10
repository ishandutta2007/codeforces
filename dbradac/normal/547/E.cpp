#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> P;
#define X first
#define Y second

const int MAX = 400100;
const int H = 3137, MOD = 1000000009;
const int TOUR = 1<<18;

int Mul(int a, int b)
{
  return (int) (((llint) a * b) % MOD);
}

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int Sub(int a, int b)
{
  return (a + MOD - b) % MOD;
}

int n;
int uklen;
int poc[MAX], len[MAX];
int hash1[MAX], hash2[MAX];
int pot1[MAX], pot2[MAX];
P suffar[MAX];
int pozicije[MAX];
int velsuffar;
char s[MAX];
int lb[MAX], ub[MAX]; //[, ]
vector <int> T[2*TOUR];

int GetH1(int p, int k)
{
  return hash1[k] - hash1[p-1] * pot1[k - p + 1];
}

int GetH2(int p, int k)
{
  return Sub(hash2[k], Mul(hash2[p-1], pot2[k - p + 1]));
}

int Lcp(P a, P b)
{
  int p1 = poc[a.X] + a.Y;
  int p2 = poc[b.X] + b.Y;

  int lo = 0, hi = min(len[a.X] - a.Y, len[b.X] - b.Y);

  for (; lo < hi; ) {
    int mid = (lo + hi + 1) / 2;
   // if (GetH1(p1, p1 + mid - 1) == GetH1(p2, p2 + mid - 1) &&
      if ( GetH2(p1, p1 + mid - 1) == GetH2(p2, p2 + mid - 1) )
          lo = mid;
    else
      hi = mid - 1;
  }

  return lo;
}

bool Manji(P a, P b)
{
  int lc = Lcp(a, b);

  if (a.Y + lc == len[a.X] && b.Y + lc != len[b.X])
    return 1;
  if (b.Y + lc == len[b.X])
    return 0;

  return s[poc[a.X] + a.Y + lc] < s[poc[b.X] + b.Y + lc];
}

void CalcHash()
{
  pot1[0] = pot2[0] = 1;
  for (int i=1; i<MAX; i++) {
    pot1[i] = pot1[i-1] * H;
    pot2[i] = Mul(pot2[i-1], H);
  }

  for (int i=1; i<uklen; i++) {
    hash1[i] = hash1[i-1] * H + s[i] - 'a' + 1;
    hash2[i] = Add(Mul(hash2[i-1], H), s[i] - 'a' + 1);
  }
}

int UpperB(P tmp)
{
  int lo = 0;
  int hi = velsuffar - 1;

  for (; lo < hi; ) {
    int mid = (lo + hi + 1) / 2;
    int lc = Lcp(suffar[mid], tmp);

    if (tmp.Y + lc == len[tmp.X] || suffar[mid].Y + lc == len[suffar[mid].X])
      lo = mid;
    else if (s[poc[tmp.X] + tmp.Y + lc] > s[poc[suffar[mid].X] + suffar[mid].Y + lc])
      lo = mid;
    else
      hi = mid - 1;
  }

  return lo;
}

void Merge(vector <int> &Nov, vector <int> &T1, vector <int> &T2)
{
  int i1 = 0, i2 = 0;

  for (; i1 + i2 < (int) T1.size() + (int) T2.size(); ) {
    if (i1 == (int) T1.size())
      Nov.push_back(T2[i2++]);
    else if (i2 == (int) T2.size())
      Nov.push_back(T1[i1++]);
    else if (T1[i1] < T2[i2])
      Nov.push_back(T1[i1++]);
    else
      Nov.push_back(T2[i2++]);
  }
}

void GenTour()
{
  for (int i=0; i<n; i++) {
    for (int j=0; j<len[i]; j++)
      T[TOUR + i].push_back(pozicije[poc[i] + j]);
    sort(T[TOUR + i].begin(), T[TOUR + i].end());
  }

  for (int i=TOUR-1; i; i--)
    Merge(T[i], T[2*i], T[2*i+1]);
}

llint Vrati(int pos, int lo, int hi, int begin, int end, int ind)
{
  if (lo >= end || hi <= begin)
    return 0;
  if (lo >= begin && hi <= end)
    return upper_bound(T[pos].begin(), T[pos].end(), ub[ind]) - 
           lower_bound(T[pos].begin(), T[pos].end(), lb[ind]);

  return Vrati(2*pos+0, lo, (lo+hi)/2, begin, end, ind) +
         Vrati(2*pos+1, (lo+hi)/2, hi, begin, end, ind);
}

int main()
{
  int brq;
  
  scanf("%d%d", &n, &brq);
  
  uklen = 0;
  for (int i=0; i<n; i++) {
    uklen++;
    poc[i] = uklen;
    scanf("%s", s + poc[i]);
    len[i] = (int) strlen(s + poc[i]);
    for (int j=0; j<len[i]; j++)
      suffar[velsuffar++] = P(i, j);

    uklen += len[i];
  }

  CalcHash();

  sort(suffar, suffar + velsuffar, Manji);
  for (int i=0; i<velsuffar; i++)
    pozicije[poc[suffar[i].X] + suffar[i].Y] = i;

  for (int i=0; i<n; i++) {
    lb[i] = (int) (lower_bound(suffar, suffar + velsuffar, P(i, 0), Manji) - suffar);
    ub[i] = UpperB(P(i, 0));
  }
  
  GenTour();

  for (int i=0; i<brq; i++) {
    int l, r, ind;
    scanf("%d%d%d", &l, &r, &ind); l--; r--; ind--;
    printf("%I64d\n", Vrati(1, 0, TOUR, l, r + 1, ind));
  }

  return 0;
}