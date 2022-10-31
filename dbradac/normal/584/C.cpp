#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1<<17;

char s[2][MAX];
char rje[MAX];

char Raz2(char c, char d)
{
  if (c != 'a' && d != 'a')
    return 'a';
  if (c != 'b' && d != 'b')
    return 'b';
  return 'c';
}

char Raz(char c)
{
  if (c == 'a')
    return 'b';
  return 'a';
}

void Nope()
{
  printf("-1\n");
  exit(0);
}

int main()
{
  int n, t;

  scanf("%d%d%s%s", &n, &t, s[0], s[1]);

  int raz = 0;
  for (int i=0; i<n; i++)
    if (s[0][i] != s[1][i])
      raz++;

  if (raz > 2 * t)
    Nope();

  for (int i=0; i<n && raz > t;) {
    vector <int> V;
    int j=i;
    for (; j<n && (int) V.size() < 2; j++)
      if (s[0][j] != s[1][j])
        V.push_back(j);

    if (V.size() == 2) {
      raz -= 2;
      t--;
      rje[V[0]] = s[0][V[0]];
      rje[V[1]] = s[1][V[1]];
    }

    i = j;
  }

  for (int i=0; i<n && t; i++) {
    if (s[0][i] != s[1][i] && !rje[i]) {
      rje[i] = Raz2(s[0][i], s[1][i]);
      raz--;
      t--;
    }
  }

  for (int i=0; i<n && t; i++)
    if (s[0][i] == s[1][i]) {
      rje[i] = Raz(s[0][i]);
      t--;
    }

  if (t)
    Nope();

  for (int i=0; i<n; i++) {
    if (rje[i])
      printf("%c", rje[i]);
    else
      printf("%c", s[0][i]);
  }

  printf("\n");

  return 0;
}