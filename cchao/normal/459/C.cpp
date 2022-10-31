#include <bits/stdc++.h>
using namespace std;

int a[1010];
int main() {
    int n, k, d;
    scanf("%d%d%d", &n, &k, &d);
    if(k >= n) {
        while(d--) {
            for(int i = 0; i < n; ++i) printf("%d ", i + 1);
            puts("");
        }
        return 0;
    }

    long long t = 1;
    for(int i = 0; i < d && t < n; ++i, t *= k) ;
    if(t < n) {
        puts("-1");
        return 0;
    }
    for(int i = 0; i < n; ++i) a[i] = i;

    while(d--) {
        for(int i = 0; i < n; ++i) {
            printf("%d ", a[i] % k + 1);
            a[i] /= k;
        }
        puts("");
    }


    return 0;
}