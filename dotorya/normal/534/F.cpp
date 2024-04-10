#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
pii dp1[21][12][12][12][12][12];
pii dp2[21][12][12][12][12][12];

int A[10];
int B[25];
int N, M;
int chk[8];
int chk2[8];
int pow12[6] = {1,12,144,1728,20736,248832};
vector <int> dp_val[4];
void dp_initialize(int x) {
    dp_val[0].push_back(0);
    dp_val[1].push_back(1);
    if(x == 1) return;

    dp_val[1].push_back(2);
    dp_val[1].push_back(3);
    if(x == 2) return;

    dp_val[1].push_back(4);
    dp_val[2].push_back(5);
    dp_val[1].push_back(6);
    dp_val[1].push_back(7);
    if(x == 3) return;

    dp_val[1].push_back(8);
    dp_val[2].push_back(9);
    dp_val[2].push_back(10);
    dp_val[2].push_back(11);
    dp_val[1].push_back(12);
    dp_val[2].push_back(13);
    dp_val[1].push_back(14);
    dp_val[1].push_back(15);
    if(x == 4) return;

    dp_val[1].push_back(16);
    dp_val[2].push_back(17);
    dp_val[2].push_back(18);
    dp_val[2].push_back(19);
    dp_val[2].push_back(20);
    dp_val[3].push_back(21);
    dp_val[2].push_back(22);
    dp_val[2].push_back(23);
    dp_val[1].push_back(24);
    dp_val[2].push_back(25);
    dp_val[2].push_back(26);
    dp_val[2].push_back(27);
    dp_val[1].push_back(28);
    dp_val[2].push_back(29);
    dp_val[1].push_back(30);
    dp_val[1].push_back(31);
    return;
}

void index_initialize(int lvl) {
    if(lvl == 7) {
        dp1[chk[1]][chk[2]][chk[3]][chk[4]][chk[5]][chk[6]] = make_pair(-1,-1);
        dp2[chk[1]][chk[2]][chk[3]][chk[4]][chk[5]][chk[6]] = make_pair(-1,-1);
        return;
    }
    if(lvl == 1) {
        for(int i = 0; i <= 20; i++) {
            chk[lvl] = i;
            index_initialize(lvl+1);
        }
    }
    else {
        for(int i = 0; i <= 11; i++) {
            chk[lvl] = i;
            index_initialize(lvl+1);
        }
    }
    return;
}

void getDP1(int x, int lvl) {
    int i, j;
    if(lvl == N+1) {
        int du[6], cnt[6], is1[6];
        for(i = 1; i <= N; i++) {
            du[i] = chk[i];
            cnt[i] = chk[i]%6;
            is1[i] = chk[i]/6;
        }
        for(i = N+1; i <= 5; i++) du[i] = 0;
        if(dp1[x-1][du[1]][du[2]][du[3]][du[4]][du[5]].second == -1) return;

        int state = du[1]*pow12[1]+du[2]*pow12[2]+du[3]*pow12[3]+du[4]*pow12[4]+du[5]*pow12[5];

        for(i = 0; i < dp_val[B[x]].size(); i++) {
            int t_pos[6], tmp = dp_val[B[x]][i];
            int t_du[6], t_cnt[6], t_is1[6];
            for(j = 1; j <= N; j++) {
                t_pos[j] = tmp%2;
                tmp /= 2;
                if(t_pos[j] == 0) {
                    t_cnt[j] = cnt[j];
                    t_is1[j] = 0;
                }
                else {
                    t_is1[j] = 1;
                    t_cnt[j] = cnt[j] + ((is1[j] == 1)?0:1);
                }
                t_du[j] = t_is1[j]*6+t_cnt[j];
            }
            for(j = N+1; j <= 5; j++) t_du[j] = 0;
            dp1[x][t_du[1]][t_du[2]][t_du[3]][t_du[4]][t_du[5]] = make_pair(state, dp_val[B[x]][i]);
        }
        return;
    }
    for(i = 0; i < 12; i++) {
        chk[lvl] = i;
        getDP1(x, lvl+1);
    }
    return;
}

void getDP2(int x, int lvl) {
    int i, j;
    if(lvl == N+1) {
        int du[6], cnt[6], is1[6];
        for(i = 1; i <= N; i++) {
            du[i] = chk[i];
            cnt[i] = chk[i]%6;
            is1[i] = chk[i]/6;
        }
        for(i = N+1; i <= 5; i++) du[i] = 0;
        if(dp2[x+1][du[1]][du[2]][du[3]][du[4]][du[5]].second == -1) return;

        int state = du[1]*pow12[1]+du[2]*pow12[2]+du[3]*pow12[3]+du[4]*pow12[4]+du[5]*pow12[5];

        for(i = 0; i < dp_val[B[x]].size(); i++) {
            int t_pos[6], tmp = dp_val[B[x]][i];
            int t_du[6], t_cnt[6], t_is1[6];
            for(j = 1; j <= N; j++) {
                t_pos[j] = tmp%2;
                tmp /= 2;
                if(t_pos[j] == 0) {
                    t_cnt[j] = cnt[j];
                    t_is1[j] = 0;
                }
                else {
                    t_is1[j] = 1;
                    t_cnt[j] = cnt[j] + ((is1[j] == 1)?0:1);
                }
                t_du[j] = t_is1[j]*6+t_cnt[j];
            }
            for(j = N+1; j <= 5; j++) t_du[j] = 0;
            dp2[x][t_du[1]][t_du[2]][t_du[3]][t_du[4]][t_du[5]] = make_pair(state, dp_val[B[x]][i]);
        }
        return;
    }
    for(i = 0; i < 12; i++) {
        chk[lvl] = i;
        getDP2(x, lvl+1);
    }
    return;
}

bool getANS(int x, int lvl) {
    int i, j;
    if(lvl == N+1) {
        for(i = 1; i <= N; i++) {
            if(chk[i] >= 12 || chk2[i] >= 12 || chk[i] < 0 || chk2[i] < 0) return false;
        }
        if(dp1[x][chk[1]][chk[2]][chk[3]][chk[4]][chk[5]].second != -1 && dp2[x+1][chk2[1]][chk2[2]][chk2[3]][chk2[4]][chk2[5]].second != -1) return true;
        return false;
    }
    for(i = 0;i<=5;i++) {
        chk[lvl] = i, chk2[lvl] = A[lvl]-i;
        if(chk2[lvl] < 0 || chk2[lvl] >= 6) continue;
        if(getANS(x, lvl+1)) return true;
        chk[lvl] = i+6, chk2[lvl] = A[lvl]-i;
        if(getANS(x, lvl+1)) return true;
        chk[lvl] = i, chk2[lvl] = A[lvl]-i+6;
        if(getANS(x, lvl+1)) return true;
        if(A[lvl]-i == 5) continue;
        chk[lvl] = i+6, chk2[lvl] = A[lvl]-i+7;
        if(getANS(x, lvl+1)) return true;
        
    }
    return false;
}

char F_ANS[10][30];
int main() {
    int i, j;
    scanf("%d %d", &N, &M);
    dp_initialize(N);
    index_initialize(1);
    for(i = 1; i <= N; i++) scanf("%d", &A[i]);
    for(i = 1; i <= M; i++) scanf("%d", &B[i]);

    // Exception
    if(M == 1) {
        for(i = 1; i <= N; i++) {
            if(A[i] == 0) printf(".\n");
            else printf("*\n");
        }
        return 0;
    }

    // DP
    int dp1s = M/2;
    for(i = 0; i < dp_val[B[1]].size(); i++) {
        int t_pos[6], tmp = dp_val[B[1]][i];
        for(j = 1; j <= N; j++) {
            t_pos[j] = tmp%2;
            tmp /= 2;
        }
        int du[6];
        for(j = 1; j <= N; j++) du[j] = t_pos[j]*7;
        for(j = N+1; j <= 5; j++) du[j] = 0;
        dp1[1][du[1]][du[2]][du[3]][du[4]][du[5]] = pii(-1, dp_val[B[1]][i]);
    }
    for(i = 2; i <= dp1s; i++) getDP1(i, 1);
    
    for(i = 0; i < dp_val[B[M]].size(); i++) {
        int t_pos[6], tmp = dp_val[B[M]][i];
        for(j = 1; j <= N; j++) {
            t_pos[j] = tmp%2;
            tmp /= 2;
        }
        int du[6];
        for(j = 1; j <= N; j++) du[j] = t_pos[j]*7;
        for(j = N+1; j <= 5; j++) du[j] = 0;
        dp2[M][du[1]][du[2]][du[3]][du[4]][du[5]] = pii(-1, dp_val[B[M]][i]);
    }
    for(i = M-1; i > dp1s; i--) getDP2(i, 1);

    // DNQ
    for(i = N+1; i <= 5; i++) chk[i] = chk2[i] = 0;
    if(!getANS(dp1s, 1)) {
        printf("ERRR");
        return 0;
    }
    int rs[6] = {0,chk[1],chk[2],chk[3],chk[4],chk[5]};
    for(i = dp1s; i >= 1; i--) {
        int t_rs = dp1[i][rs[1]][rs[2]][rs[3]][rs[4]][rs[5]].first;
        int tmp = dp1[i][rs[1]][rs[2]][rs[3]][rs[4]][rs[5]].second;
        for(j = 1; j <= N; j++) {
            F_ANS[j][i] = ((tmp%2==1)?'*':'.');
            tmp /= 2;
        }
        for(j = 1; j <= N; j++) {
            t_rs /= 12;
            rs[j] = t_rs%12;
        }
    }

    rs[1] = chk2[1], rs[2] = chk2[2], rs[3] = chk2[3], rs[4] = chk2[4], rs[5] = chk2[5];
    for(i = dp1s+1; i <= M; i++) {
        int t_rs = dp2[i][rs[1]][rs[2]][rs[3]][rs[4]][rs[5]].first;
        int tmp = dp2[i][rs[1]][rs[2]][rs[3]][rs[4]][rs[5]].second;
        for(j = 1; j <= N; j++) {
            F_ANS[j][i] = ((tmp%2==1)?'*':'.');
            tmp /= 2;
        }
        for(j = 1; j <= N; j++) {
            t_rs /= 12;
            rs[j] = t_rs%12;
        }
    }

    for(i = 1; i <= N; i++) {
        for(j = 1; j <= M; j++) printf("%c", F_ANS[i][j]);
        printf("\n");
    }
    return 0;
}