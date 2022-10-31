#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
  int uk, ha, hb, wa, wb;
  ll rje=0;

  scanf("%d%d%d%d%d", &uk, &ha, &hb, &wa, &wb);

  int dvaab = uk - 2 * (ll) wa * wb;
  dvaab -= dvaab % ((ll) wa * wb);
  
  dvaab = max(dvaab, 0);

  if ((ll) ha * wb > (ll) hb * wa)
    rje = (ll) dvaab / wa * ha;
  else
    rje = (ll) dvaab / wb * hb;

  if (wa < wb) {
    swap(wa, wb);
    swap(ha, hb);
  }

  ll plus = 0;
 
  for (int i=0; (ll) i * wa <= uk - dvaab; i++)
    plus = max(plus, (ll) i * ha + ((uk - dvaab - (ll) i * wa) / wb) * hb);
  
  cout << rje + plus << endl;

  return 0;
}