#include <stdio.h>
#include <stdlib.h>

struct element {
  int before;
  int val;
  int after;
};

int connect(element* elements, int a, int b)
{
  int b_begin=b;
  int b_end = b;
  int tentry = b;
  int lentry = b;
  while(tentry != 0)
  {
    if(a == tentry)
      return -1;
    lentry = tentry;
    tentry = elements[lentry].after;
  }
  b_end = lentry;
  tentry = lentry = b;
  while(tentry != 0)
  {
    if(a == tentry)
      return -1;
    lentry = tentry;
    tentry = elements[lentry].before;
  }
  b_begin = lentry;

  int aafter = elements[a].after;
//  printf("  a=%d, b=%d: a.after = %d, b_begin.before = %d, b_end.after = %d, aafter.befeore = %d\n", a, b, b_begin, a, aafter, b_end);
  elements[a].after = b_begin;
  elements[b_begin].before = a;
  elements[b_end].after = aafter;
  if(aafter != 0)
    elements[aafter].before = b_end;
}

int find(const element* elements, const int a, const int b)
{
  int tentry=a;
 while(tentry != 0)
  {
    if(tentry == b)
      return 1;
    tentry = elements[tentry].before;
//    printf("  %d\n", tentry);
  }
  tentry = a; 
//  printf("find %d from %d:\n", b, a);
  while(tentry != 0)
  {
    if(tentry == b)
      return 1;
    tentry = elements[tentry].after;
//    printf("  %d\n", tentry);
  }
  return 0;
}

int main()
{
  int n;
  scanf("%d", &n);

  element* elements = (element*) malloc( sizeof(element) * (n+1) );

  for(int i=0;i<=n;++i)
  {
    elements[i].val = i;
    elements[i].before = 0;
    elements[i].after = 0;
  }

  int* permutations = (int *) malloc(sizeof(int) * n);
  for(int i=0;i<n;++i)
  {
    scanf("%d", &permutations[i]);
  }

  int* favorites = (int* ) malloc(sizeof(int)*n);

  int favorite;
  for(int i=0;i<n;++i)
  {
    scanf("%d", &favorite);
    favorites[i] = favorite;
    // number i+1
//    if(i+1 != favorite)
    if(true)
    {
//      if(favorite == 17)
//        printf("   17!!!! ->");
      if(i-favorite >= 0)
      {
        // connect i+1 and i-favorite+1; smaller goes first.
        connect(elements, i-favorite+1, i+1);
      }
      if(i+favorite < n)
      {
//        if(favorite == 17)
//          printf(" %d\n\n", i+favorite+1);
        connect(elements, i+1, i+favorite+1);
      }
    }
  }

  int errors = 0;
  int f, l, p;
  for(int i=0;i<n;++i)
  {
    f= i+1;
    l = permutations[i];
    if(f> l)
    {
      p = f;
      f = l;
      l = p;
    }
    if(!find(elements, f, l))
    {
      ++errors;
      break;
    }
  }

/*
  if(permutations[4] == 64 && permutations[5] == 6 && permutations[6] == 7 && permutations[7] == 28 && permutations[8] == 9)
  {
    for(int i=0;i<n;++i)
    {
      printf("%d ", favorites[i]);
    }
    int tval = 0;
    for(int i = 0;i<n;++i)
    {
      printf("%d: ", i+1);
      tval = i+1;
      while(tval != 0)
      {
        printf("%d, ", tval);
        tval = elements[tval].after;
      }
      printf("\n");
    }
  }
*/
  if(!errors)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}