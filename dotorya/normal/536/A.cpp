#include <stdio.h>
typedef long long ll;
int main() {
    ll A, B, L, T, M, st, en, mi, ans;
    int i, N;
    scanf("%lld %lld %d", &A, &B, &N);
    for(i = 1; i <= N; i++) {
        scanf("%lld %lld %lld", &L, &T, &M);
        if(A+(L-1)*B>T) {
            printf("-1\n");
            continue;
        }
        st = L, en = (T-A)/B+1;
        while(st <= en) {
            mi = (st+en)/2;
            if(A*(mi-L+1)+B*(mi*(mi-1)-(L-1)*(L-2))/2 <= M*T) {
                ans = mi;
                st = mi+1;
            }
            else en = mi-1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}