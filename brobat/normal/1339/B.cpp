#include <algorithm>
#include <cstdio>
#include <vector>

#define MAXN 100000

using namespace std;

int a[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    sort(a, a + n);
    vector<int> sol;
    for(int i = 0; i < n / 2; i++) {
      sol.push_back(a[i]);
      sol.push_back(a[n - i - 1]);
    }
    if(n % 2 == 1) {
      sol.push_back(a[n / 2]);
    }
    for(int i = n - 1; i >= 0; i--) {
      printf("%d ", sol[i]);
    }
    printf("\n");
  }
  return 0;
}