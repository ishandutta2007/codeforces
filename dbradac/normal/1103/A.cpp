#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

int main()
{
  char s[1005];
  scanf("%s", s);
  int l = (int) strlen(s);
  int h = 0, v = 0;

  REP(i, l) {
    if (s[i] == '0') { //vertical
      if (!v)
	printf("1 4\n");
      else
	printf("3 4\n");

      v ^= 1;
    }
    else {
      if (!h)
	printf("4 1\n");
      else
	printf("4 3\n");
      h ^= 1;
    }
  }
  
  return 0;
}