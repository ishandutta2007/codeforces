#include <cstdio>
#include <bitset>
#include <complex>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<20;

int p[MAX];
int bio[MAX];
int kol[MAX];
vector <int> C;
int n, k;

void cik()
{
  REP(i, n) {
    if (bio[i]) continue;
    int sz = 0;
    for (int tmp=i; tmp != i || !sz; sz++, tmp=p[tmp])
      bio[tmp] = 1;

    C.push_back(sz);
    kol[sz]++;
  }
}

bitset <MAX> B;
int dajmin()
{
  B[0] = 1;

  REP(i, MAX) {
    for (int j=1; j<=kol[i]; j*=2) {
      B |= B << (j * i);
      kol[i] -= j;
    }

    if (kol[i])
      B |= B << (i * kol[i]);
  }

  if (B[k]) return k;
  return k+1;
}

int dajmax(vector <int> V)
{
  int nepar = 0;
  int jos = k;
  int ret = 0;

  for (auto it : V) {
    int mic = min(jos, it / 2);
    jos -= mic;
    ret += 2 * mic;
    if (it & 1) nepar++;
  }

  ret += min(nepar, jos);

  assert(ret <= n);

  return ret;
}

int main()
{
  scanf("%d%d", &n, &k);

  REP(i, n) {
    scanf("%d", &p[i]); p[i]--;
  }

  cik();

  printf("%d %d\n", dajmin(), dajmax(C));

  return 0;
}