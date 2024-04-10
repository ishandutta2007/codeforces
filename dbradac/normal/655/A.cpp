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

char s[2][2][3];
P poz[4] = { P(0, 0), P(0, 1), P(1, 1), P(1, 0) };
int slj[2];

int main()
{
  for (int i=0; i<4; i++)
    scanf("%s", s[i/2][i%2]);

  for (int i=0; i<2; i++) {
    slj[i] = -1;
    for (int j=0; slj[i] <= 0; j = (j + 1) % 4) {
      if (slj[i] == -1 && s[i][poz[j].X][poz[j].Y] == 'A')
        slj[i] = 0;
      else if (!slj[i] && s[i][poz[j].X][poz[j].Y] != 'X')
        slj[i] = s[i][poz[j].X][poz[j].Y] - 'A' + 1;
    }    
  }

  printf("%s\n", slj[0] == slj[1] ? "YES" : "NO");

  return 0;
}