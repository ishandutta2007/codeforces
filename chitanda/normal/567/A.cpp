#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 100100;
int n, a[M], b[M], m1[M], m2[M];

bool cmp(int x, int y) { return a[x] < a[y]; }

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = i;
    sort(b + 1, b + n + 1, cmp);
    m1[b[1]] = a[b[2]] - a[b[1]];
    m2[b[1]] = a[b[n]] - a[b[1]];
    m1[b[n]] = a[b[n]] - a[b[n - 1]];
    m2[b[n]] = a[b[n]] - a[b[1]];
    for(int i = 2; i < n; i++){
        m1[b[i]] = min(a[b[i]] - a[b[i - 1]], a[b[i + 1]] - a[b[i]]);
        m2[b[i]] = max(a[b[i]] - a[b[1]], a[b[n]] - a[b[i]]);
    }
    for(int i = 1; i <= n; i++)
        printf("%d %d\n", m1[i], m2[i]);
  return 0;
}