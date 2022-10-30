#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 100100, MOD = 1e9 + 7, GRAN = 100;

int Add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int Eksp(int b, int e)
{
  int ret = 1;
  for (; e; e /= 2, b = Mul(b, b))
    if (e & 1)
      ret = Mul(ret, b);

  return ret;
}

int Inv(int x)
{
  return Eksp(x, MOD - 2);
}

int fak[MAX], invfak[MAX];
int e25[MAX], e26[MAX];

void GenFakPot()
{
  fak[0] = invfak[0] = 1;
  for (int i=1; i<MAX; i++) {
    fak[i] = Mul(i, fak[i-1]);
    invfak[i] = Inv(fak[i]);
  }

  e25[0] = 1;
  for (int i=1; i<MAX; i++)
    e25[i] = Mul(25, e25[i-1]);
}
int Povrh(int a, int b)
{
  if (b < 0 || a < b)
    return 0;
  return Mul(fak[a], Mul(invfak[b], invfak[a-b]));
}

vector <int> Rje[MAX];

void Gen(int len)
{
  if (!Rje[len].empty())
    return;

  int p[MAX];
  memset(p, 0, sizeof p);

  for (int i=0; i<MAX; i++)
    if (i >= len)
      p[i] = Mul(Povrh(i-1, len-1), e25[i-len]);
  
  int tmp = 0;
  for (int i=0; i<MAX; i++) {
    tmp = Add(Mul(tmp, 26), p[i]);
    Rje[len].push_back(tmp);
  }
}

char s[MAX];

int main()
{
  GenFakPot();

  int q;
  
  scanf("%d%s", &q, s);
  int len = (int) strlen(s);
  Gen(len);

  for (; q--; ) {
    int st;
    scanf("%d", &st);
    if (st == 1) {
      scanf("%s", s);
      len = (int) strlen(s);
      Gen(len);
    }
    else {
      int tmp;
      scanf("%d", &tmp);
      printf("%d\n", Rje[len][tmp]);
    }
  }

  return 0;
}