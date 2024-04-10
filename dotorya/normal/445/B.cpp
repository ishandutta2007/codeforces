#include <stdio.h>
#include <vector>
using namespace std;
vector <int> conn[100050];
int chk[100050];
int Q[100050];
int main() {
    int N, M, i, j, t1, t2;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= M; i++) {
        scanf("%d %d", &t1, &t2);
        conn[t1].push_back(t2);
        conn[t2].push_back(t1);
    }

    int G = 0;
    for(i = 1; i <= N; i++) {
        if(chk[i] != 0) continue;
        G++;
        int st = 1, en = 2;
        Q[1] = i;
        chk[i] = G;
        while(st < en) {
            int tmp = Q[st];
            for(j = 0; j < conn[tmp].size(); j++) {
                int tmp2 = conn[tmp][j];
                if(chk[tmp2] != 0) continue;
                chk[tmp2] = G;
                Q[en++] = tmp2;
            }
            st++;
        }
    }

    long long ANS = (1ll << (N-G));
    printf("%lld", ANS);
    return 0;
}