#include <cstdio>
#include <algorithm>
using namespace std;

int n, m[100010], a, b, ans = 0;
int main() {
    scanf("%d", &n); for(int i = 0; i < n; ++i) scanf("%d", &m[i]);
    sort(m, m+n); n = unique(m, m+n) - m;
    scanf("%d%d", &a, &b);
    for(int x,i; n && a > b; a-=x, ++ans)
        for(i=0, x=1; i < n; ++i)
            if(a%m[i] > a-b) m[i--] = m[--n];
            else x = max(x, a%m[i]);
    printf("%d\n", ans + a - b);
    return 0;
}