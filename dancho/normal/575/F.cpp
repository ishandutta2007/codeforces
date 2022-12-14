#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
int x;
int l[5020], r[5020];

int main() {
    scanf("%d %d", &n, &x);
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &l[i], &r[i]);
    }

    int fl = x;
    int fr = x;
    
    for (int i = 0; i < n; ++i) {
        if (fr < l[i]) {
            res += l[i] - fr;
            fl = fr;
            fr = l[i];
        } else if (r[i] < fl) {
            res += fl - r[i];
            fr = fl;
            fl = r[i];
        } else {
            // intersect;
            fl = max(fl, l[i]);
            fr = min(fr, r[i]);
        }
    }

    printf("%lld\n", res);
    return 0;
}