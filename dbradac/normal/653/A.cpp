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

int ima[1005];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d", &tmp);
    ima[tmp] = 1;
  }

  for (int i=0; i<=1000; i++) {
    if (ima[i] && ima[i+1] && ima[i+2]) {
      printf("YES\n");
      return 0;
    }
  }

  printf("NO\n");

  return 0;
}