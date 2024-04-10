#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1034567891;
pii in[3050];
int dp1[3050][3050];
int dp2[3050][3050];
int u[3050];
int main() {
    int N, P, S, i, j;
    scanf("%d %d %d", &N, &P, &S);
    for(i = 1; i <= N; i++) scanf("%d", &in[i].first);
    for(i = 1; i <= N; i++) scanf("%d", &in[i].second);

    for(i = 1; i <= N; i++) u[i] = i;
    sort(u+1, u+N+1, [](int a, int b) {
         return in[a].first - in[a].second > in[b].first - in[b].second;
    });

    for(i = 0; i <= N+1; i++) for(j = 0; j <= N; j++) dp1[i][j] = dp2[i][j] = -INF;
    dp1[0][0] = 0;
    for(i = 1; i <= N; i++) {
        for(j = 0; j <= N; j++) {
            dp1[i][j] = dp1[i-1][j];
            if(j != 0) dp1[i][j] = max(dp1[i][j], dp1[i-1][j-1] + in[u[i]].first);
        }
    }
    dp2[N+1][0] = 0;
    for(i = N; i >= 1; i--) {
        for(j = 0; j <= N; j++) {
            dp2[i][j] = dp2[i+1][j];
            if(j != 0) dp2[i][j] = max(dp2[i][j], dp2[i+1][j-1] + in[u[i]].second);
        }
    }
    int ans = 0, mx = 0;
    for(i = 1; i <= N; i++) {
        if(ans < dp1[i][P] + dp2[i+1][S]) {
            ans = dp1[i][P] + dp2[i+1][S];
            mx = i;
        }
    }
    printf("%d\n", ans);

    vector <int> a1;
    vector <int> a2;
    i = mx, j = P;
    while(j) {
        if(dp1[i][j] == dp1[i-1][j-1] + in[u[i]].first) {
            a1.push_back(u[i]);
            i--;
            j--;
        }
        else i--;
    }
    i = mx+1, j = S;
    while(j) {
        if(dp2[i][j] == dp2[i+1][j-1] + in[u[i]].second) {
            a2.push_back(u[i]);
            i++;
            j--;
        }
        else i++;
    }

    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    for(auto it : a1) printf("%d ", it);
    printf("\n");
    for(auto it : a2) printf("%d ", it);
    printf("\n");
    return 0;

}