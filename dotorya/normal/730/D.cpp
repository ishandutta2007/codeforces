#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1034567891;

ll L[200050];
ll sum[200050];
ll T[200050];

vector<ll> Va;
int main() {
    int N, i, j;
    ll R;
    scanf("%d %lld", &N, &R);
    for(i = 1; i <= N; i++) {
        scanf("%lld", L+i);
        sum[i] = sum[i-1] + L[i];
    }
    for(i = 1; i <= N; i++) scanf("%lld", T+i);

    for(i = 1; i <= N; i++) {
        if(L[i] > T[i]) return !printf("-1\n");
        T[i] = max(0ll, 2*L[i] - T[i]);
    }

    ll st = 0, ans = 0;
    ll curt = 0;
    for(i = 1; i <= N; i++) {
        st = max(st, sum[i-1]);
        ll d = min(L[i], st - sum[i-1]);
        T[i] = max(0ll, T[i] - d);
        if(T[i] == 0) {
            curt += 2*L[i] - d;
            continue;
        }
        curt += d;
        curt += (L[i] - T[i] - d) * 2;

        ll c = (T[i] + R - 1) / R;
        ans += c;
        st = sum[i] + c*R - T[i];

        for(j = 0; j < c && Va.size() < 100000; j++) Va.push_back(curt + R*j);
        curt += T[i];
    }

    printf("%lld\n", ans);
    if(ans <= 100000) {
        for(auto it : Va) printf("%lld ", it);
        printf("\n");
    }
    return 0;
}