#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
int p[256];

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

long long sl = 1;
long long mn = 1;

int us[256];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }
  
  for (int i = 0; i < n; ++i) {
    memset(us, -1, sizeof(us));
    int d = 0;
    int j = i;
    do {
      us[j] = d;
      ++d;
      j = p[j];
    } while (us[j] == -1);
    int st = d - us[j];
    if (us[j] > mn) {
      mn = us[j];
    }
    // printf("BR %d %d %d\n", i, j, us[j]);
    sl = sl * st / gcd(sl, st);
  }
  long long isl = sl;
  sl = (long long) mn / isl;
  sl = sl * isl;
  while (sl < mn || sl <= 0) {
    sl += isl;
  }
  printf("%lld\n", sl);
  return 0;
}