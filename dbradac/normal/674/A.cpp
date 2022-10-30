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

const int MAX = 5005;

int p[MAX];
int rje[MAX];
int br[MAX];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);
  
  for (int i=0; i<n; i++) {
    memset(br, 0, sizeof br);
    int mx = 0;

    for (int j=i; j<n; j++) {
      br[p[j]]++;
      if (br[mx] < br[p[j]] || (br[mx] == br[p[j]] && p[j] < mx))
        mx = p[j];

      rje[mx-1]++;
    }
  }

  for (int i=0; i<n; i++)
    printf("%d ", rje[i]);
  printf("\n");

  return 0;
}