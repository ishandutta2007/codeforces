#include <stdio.h>
#include <queue>
using namespace std;
typedef long long ll;
ll dis[550][550];
ll path[550][550];
ll ANS[550];
int del[550];
int N;
struct data {
    data() {
        data(0,0);
    }
    data(ll a, int b) {
        d = a, chk = b;
    }
    ll d;
    int chk;
    bool operator < (const data & l) const {
        return d > l.d;
    }
};
priority_queue <data> H;
void input() {
    int i, j;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) for(j = 1; j <= N; j++) scanf("%d", &dis[i][j]);
    for(i = 1; i <= N; i++) scanf("%d", &del[i]);
    return;
}
ll MIN(ll a, ll b){
    return (a>b)?b:a;
}
void get_ans() {
    int i, j, k, t;
    i = del[N], j = del[N-1];
    path[i][j] = dis[i][j], path[j][i] = dis[j][i];
    ll ans = dis[i][j] + dis[j][i];
    ANS[N] = 0, ANS[N-1] = ans;
    for(i = N-2; i >= 1; i--) {
        t = del[i];
        for(j = i+1; j <= N; j++) {
            int t1 = del[j];
            path[t][t1] = dis[t][t1];
            for(k = i+1; k <= N; k++) path[t][t1] = MIN(path[t][t1], dis[t][del[k]]+path[del[k]][t1]);
            path[t1][t] = dis[t1][t];
            for(k = i+1; k <= N; k++) path[t1][t] = MIN(path[t1][t], dis[del[k]][t]+path[t1][del[k]]);
            ans += path[t][t1]+path[t1][t];
        }
        for(j = i+1; j <= N; j++) {
            for(k = i+1; k <= N; k++) {
                if(j == k) continue;
                int t1 = del[j];
                int t2 = del[k];
                ll t3 = path[t1][t]+path[t][t2];
                if(path[t1][t2] > t3) {
                    ans -= path[t1][t2] - t3;
                    path[t1][t2] = t3;
                }
            }
        }
        ANS[i] = ans;
    }
    for(i = 1; i <= N; i++) printf("%I64d ", ANS[i]);
    return;
}
int main() {
    //freopen("input.txt", "r", stdin);
    input();
    if(N == 1) {
        printf("0");
        return 0;
    }
    get_ans();
    return 0;
}