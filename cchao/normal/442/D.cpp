#include <cstdio>
const int N = 1000010;
int n, p[N], a[N]={}, b[N]={}, c[N]={};
int main() {
    scanf("%d", &n); for(int j = 1; j <= n; ++j) {
        scanf("%d", &p[j]); p[j]--;
        for(int i = j;; i=p[i]) {
            int m = a[i]+((a[i]-b[i])?0:1);
            if(!i || c[i] >= m) break; c[i] = m;
            if(m > a[p[i]]) a[p[i]] = m;
            else if(m > b[p[i]]) b[p[i]] = m;
        }
        printf("%d%c", a[0], j==n?'\n': ' ');
    }
    return 0;
}