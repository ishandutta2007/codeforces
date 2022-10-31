#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;
#define X first
#define Y second

int h[2], x[2], y[2], tar[2];
int m;

int Mul(int a, int b)
{
  return (int) (((llint) a * b) % m);
}

int Add(int a, int b)
{
  return (a + b) % m;
}

int RunPoc()
{
  for (int i=0; i<m; i++) {
    if (h[0] == tar[0] && h[1] == tar[1])
      return i;
    for (int j=0; j<2; j++)
      h[j] = Add(Mul(h[j], x[j]), y[j]);
  }
  
  return -1;
}

pii Cik(int ind)
{
  int tmp = h[ind];
  int poz = -1;

  for (int i=0; ; i++) {
    if (tmp == tar[ind])
      poz = i;
    if (tmp == h[ind] && i)
      return pii(i, poz);
    tmp = Add(Mul(tmp, x[ind]), y[ind]);
  }
}

int main()
{
  scanf("%d", &m);

  for (int i=0; i<2; i++)
    scanf("%d%d%d%d", &h[i], &tar[i], &x[i], &y[i]);
  
  pii cik[2];
  
  int tmp = RunPoc();

  if (tmp != -1) {
    printf("%d\n", tmp);
    return 0;
  }

  for (int i=0; i<2; i++) {
    cik[i] = Cik(i);
    if (cik[i].Y == -1) {
      printf("-1\n");
      return 0;
    }
    cik[i].Y %= cik[i].X;
  }

  if (!cik[0].X) {
    printf("%d\n", m + cik[1].Y);
    return 0;
  }
  else if (!cik[1].X) {
    printf("%d\n", m + cik[0].Y);
    return 0;
  }

  llint t = cik[0].Y;
  
  for (int i=0; i<m; i++, t += cik[0].X) {
    if (t % cik[1].X == cik[1].Y) {
      cout << t + m << endl;
      return 0;
    }
  }
  
  printf("-1\n");

  return 0;
}