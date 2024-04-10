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

void Nope()
{
  printf("Impossible\n");
  exit(0);
}

ll Pov2(int x)
{
  return (ll) x * (x - 1) / 2;
}

int main()
{
  ll a00, a11, a01, a10;

  cin >> a00 >> a01 >> a10 >> a11;

  if (a00 + a01 + a10 + a11 == 0) {
    printf("1\n");
    return 0;
  }

  int a=-1, b=-1;
  for (int i=0; i<1e6; i++)
    if (Pov2(i) == a00)
      a = i;

  for (int i=0; i<1e6; i++)
    if (Pov2(i) == a11)
      b = i;

  if (a == -1 || b == -1)
    Nope();

  int moga[2] = {0, a};
  int mogb[2] = {0, b};

  int done = 0;
  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      if (Pov2(moga[i]) == a00 && Pov2(mogb[j]) == a11 &&
          (ll) moga[i] * mogb[j] == a01 + a10) {
        a = moga[i];
        b = mogb[j];
        done = 1;
        break;
      }
    }
    if (done)
      break;
  }

  if (!b) {
    for (int i=0; i<a; i++)
      printf("0");
    return 0;
  }

  if (!done)
    Nope();

  ll ispr = a01 / b;
  for (int i=0; i<ispr; i++)
    printf("0");

  ll ost = a01 % b;

  for (int i=0; i<b-ost; i++)
    printf("1");

  if (ispr < a)
    printf("0");
  for (int i=0; i<ost; i++)
    printf("1");

  for (int i=0; i<a-ispr-1; i++)
    printf("0");
  printf("\n");

  return 0;
}