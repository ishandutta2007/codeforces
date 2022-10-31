#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1<<17;

char s[MAX];

int main()
{
  int zad=-1, kolko, ne=0, sum=0;

  scanf("%s", s);
  int l = (int) strlen(s);

  for (int i=0; i<l; i++) {
    if (s[i] == '#') {
      zad = i;
      sum--;
    }
    else if (s[i] == '(')
      sum++;
    else
      sum--;
  }

  kolko = 1 + sum;
  if (kolko < 1)
    ne = 1;
    
  for (int i=0, raz=0; i<l; i++) {
    if (s[i] == '(')
      raz++;
    else if (s[i] == ')')
      raz--;
    else {
      if (i < zad)
        raz--;
      else
        raz -= kolko;
    }
    if (raz < 0)
      ne = 1;
  }

  if (ne)
    printf("-1\n");
  else {
    for (int i=0; i<l; i++) {
      if (s[i] == '#') {
        if (i == zad)
          printf("%d\n", kolko);
        else
          printf("1\n");
      }
    }
  }

  return 0;
}