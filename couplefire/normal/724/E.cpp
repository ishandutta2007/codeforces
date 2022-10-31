#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, C;
vector<int> P, S;
vector<ll> dp1, dp2;

int main() {
    scanf("%d %d", &N, &C);
    P.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
    }
    S.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }

    dp1 = dp2 = vector<ll>(N + 1, 0);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dp2[j] = min(dp1[j + 1] + P[i], 1LL*j*C + dp1[j] + S[i]);
        }
        dp1 = dp2;
    }

    printf("%lld", dp1[0]);
}