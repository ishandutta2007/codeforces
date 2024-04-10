#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 111111;

long long h[N], p[N];
int n, m;

long long canDone(long long pos, long long l, long long r) {
    if (r <= pos)
        return pos - l;
    if (pos <= l)
        return r - pos;
    return r - l + min(r - pos, pos - l);
}

int check(long long limit) {
    int j = 1;
    for(int i = 1; i <= n; i++) {
        int last = j;
        while(j <= m && canDone(h[i], p[last], p[j]) <= limit)
            j++;
    }
    return j > m;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%I64d", &h[i]);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%I64d", &p[i]);
    }
    long long l = 0, r = 20000000000000ll, mid;
    while(l < r) {
        mid = (l + r) / 2;
        if (check(mid)) 
            r = mid;
        else
            l = mid + 1;
    }
    printf("%I64d\n", l);
    return 0;
}