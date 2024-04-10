#include <stdio.h>
typedef long long ll;
ll d[100050][2];
ll abs(ll a) {
    return (a>0)?a:-a;
}
ll MAX(ll a, ll b) {
    return (a<b)?b:a;
}
int main() {
    int N, M, i;
    ll MX = 0, t;

    scanf("%d %d", &N, &M);
    for(i = 1; i <= M; i++) {
        scanf("%lld %lld", &d[i][0], &d[i][1]);
    }

    MX = d[1][0]+d[1][1]-1;

    for(i = 1; i < M; i++) {
        if(abs(d[i+1][1]-d[i][1]) > d[i+1][0]-d[i][0]) break;
        ll ans = (d[i][1]+d[i+1][1]+d[i+1][0]-d[i][0])/2;
        if(MX < ans) MX = ans;
    }
    if(i != M) {
        printf("IMPOSSIBLE");
        return 0;
    }
    if(N+d[M][1]-d[M][0] > MX) MX = N+d[M][1]-d[M][0];
    printf("%lld", MX);
    return 0;
}