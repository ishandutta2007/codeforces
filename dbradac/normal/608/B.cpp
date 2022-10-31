#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 1<<18;

char a[MAX], b[MAX];
int pref[2][MAX];

int main()
{
  scanf("%s%s", a + 1, b + 1);
  int la = strlen(a + 1);
  int lb = strlen(b + 1);
  
  for (int i=1; i<=lb; i++) {
    pref[b[i] - '0'][i] = 1;
    for (int j=0; j<2; j++)
      pref[j][i] += pref[j][i-1];
  }
  
  ll ret=0;
  for (int i=1; i<=la; i++) {
    int ind = 1 ^ (a[i] - '0');
    ret += pref[ind][lb-(la-i)] - pref[ind][i-1];
  }

  printf("%lld\n", ret);

  return 0;
}