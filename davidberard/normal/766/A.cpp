#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  ios_base::sync_with_stdio();
  string a, b;
  cin >> a;
  cin >> b;

  if(a.compare(b) == 0)
    printf("-1\n");
  else
  {
    int la, lb,lc;
    la = a.length();
    lb = b.length();
    
    if(la < lb)
    {
      lc= la;
      la = lb;
      lb = lc;
    }
    printf("%d\n", la);
  }

  return 0;
}