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

const int MAX = 1005;

int a[MAX], b[MAX];

int main()
{
  int n;

  scanf("%d", &n);

  int aa = 0;
  for (int i=1; i<=n; i++) {
    scanf("%d", &a[i]);
    aa |= a[i];
  }
  
  int bb=0;
  for (int i=1; i<=n; i++) {
    scanf("%d", &b[i]);
    bb |= b[i];
  }

  printf("%d\n", aa + bb);

  return 0;
}