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

const int MAX = 205;

int px[MAX], py[MAX];
char s[MAX];

int main()
{
  int n;

  scanf("%d%s", &n, s + 1);

  for (int i=1; i<=n; i++) {
    px[i] = px[i-1];
    py[i] = py[i-1];
    if (s[i] == 'U') py[i]++;
    if (s[i] == 'D') py[i]--;
    if (s[i] == 'L') px[i]--;
    if (s[i] == 'R') px[i]++;
  }

  int ret=0;
  for (int i=1; i<=n; i++)
    for (int j=i; j<=n; j++)
      if (px[j] == px[i-1] && py[j] == py[i-1])
        ret++;

  printf("%d\n", ret);

  return 0;
}