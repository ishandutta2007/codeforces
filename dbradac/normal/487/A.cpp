#include <cstdio>
#include <algorithm>

using namespace std;

int hpja, atja, defja, hpon, aton, defon, chp, cat, cdef;

int main()
{
  int r=-1;

  scanf("%d%d%d%d%d%d%d%d%d", &hpja, &atja, &defja, &hpon, &aton, &defon, &chp, &cat, &cdef);
  
  for (int t=1; t<=205;t++) {
    int tmp=0;
    for (int i=0; i<=205; i++) {
      int kol = max(0, t * (aton - defja - i) - hpja + 1);
      tmp = kol * chp + i * cdef;
      kol = (hpon + t * defon - 1) / t + 1;
      tmp += max(0, cat * (kol - atja));
      if (tmp < r || r == -1)
        r = tmp;
    }
  }

  printf("%d\n", r);

  return 0;
}