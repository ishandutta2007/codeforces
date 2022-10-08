#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> conn[3050];

int Q[3050];
int Q_chk[3050];

int dis[3050][3050];
int main() {
    int N, M, i, j, s1, t1, l1, s2, t2, l2;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= M; i++) {
        scanf("%d %d", &t1, &t2);
        conn[t1].push_back(t2);
        conn[t2].push_back(t1);
    }
    scanf("%d %d %d %d %d %d", &s1, &t1, &l1, &s2, &t2, &l2);

    // BFS
    for(i = 1; i <= N; i++) {
        int st = 1, en = 2;
        Q[1] = i;
        Q_chk[i] = i;
        dis[i][i] = 0;
        while(st < en) {
            int tmp1 = Q[st];
            for(j = 0; j < conn[tmp1].size(); j++) {
                if(Q_chk[conn[tmp1][j]] == i) continue;
                dis[i][conn[tmp1][j]] = dis[i][tmp1]+1;
                Q[en++] = conn[tmp1][j];
                Q_chk[conn[tmp1][j]] = i;
            }
            st++;
        }
    }

    // Get ANS
    int MIN;
    if(dis[s1][t1] > l1 || dis[s2][t2] > l2) {
        printf("-1");
        return 0;
    }
    else MIN = dis[s1][t1]+dis[s2][t2];

    for(i = 1; i <= N; i++) {
        for(j = 1; j <= N; j++) {
            int tmp1 = min(dis[s1][i]+dis[t1][j], dis[s1][j]+dis[t1][i])+dis[i][j];
            int tmp2 = min(dis[s2][i]+dis[t2][j], dis[s2][j]+dis[t2][i])+dis[i][j];
            if(tmp1 > l1 || tmp2 > l2) continue;
            if(tmp1+tmp2-dis[i][j] < MIN) MIN = tmp1+tmp2-dis[i][j];
        }
    }

    printf("%d", M-MIN);
    return 0;
}