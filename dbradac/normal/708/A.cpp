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

const int MAX = 1<<17;

char s[MAX];

int main()
{
  int n;
  scanf("%s", s);
  n = (int) strlen(s);

  int st = 0;

  for (int i=0; i<n; i++) {
    if (s[i] != 'a') {
      st = 1;
      s[i]--;
    }
    else if (st)
      break;
  }

  if (!st)
    s[n-1] = 'z';

  printf("%s\n", s);

  return 0;
}