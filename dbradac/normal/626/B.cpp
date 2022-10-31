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

int bio[MAX][MAX][MAX];
char s[MAX];

void Dfs(int a, int b, int c)
{
  if (bio[a][b][c])
    return;

  bio[a][b][c] = 1;

  if (a && b)
    Dfs(a - 1, b - 1, c + 1);
  if (a && c)
    Dfs(a - 1, b + 1, c - 1);
  if (b && c)
    Dfs(a + 1, b - 1, c - 1);

  if (a > 1)
    Dfs(a - 1, b, c);
  if (b > 1)
    Dfs(a, b - 1, c);
  if (c > 1)
    Dfs(a, b, c - 1);  
}

int main()
{
  int n;

  scanf("%d%s", &n, s);

  int a=0, b=0, c=0;
  for (int i=0; i<n; i++) {
    if (s[i] == 'B')
      a++;
    if (s[i] == 'G')
      b++;
    if (s[i] == 'R')
      c++;
  }

  Dfs(a, b, c);
  if (bio[1][0][0])
    printf("B");
  if (bio[0][1][0])
    printf("G");
  if (bio[0][0][1])
    printf("R");
  printf("\n");

  return 0;
}