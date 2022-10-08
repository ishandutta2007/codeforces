#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct data {
    data() {
        data(0,0,0);
    }
    data(int a, int b, int c) {
        node = a, line = b, chk = c;
    }
    int node, line, chk;
} t4;
struct data2 {
    data2(int a, int b, int c) {
        node = a, dis = b, chk = c;
    }
    int node, dis, chk;
    bool operator < (const data2 & l) const {
        if(dis != l.dis) return dis > l.dis;
        else return chk < l.chk;
    }
};
vector <data> conn[100050];
priority_queue <data2> H;
int chk[100050][5]; // 0 : , 1 : 1 , 2 :   (), 3 :   (), 4 :  
int d[100050][3];
int ans_chk[100050];
int main() {
    int N, M, i, t1, t2, t3, t5, t6, ans_cnt = 0;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= M; i++) {
        scanf("%d %d %d", &d[i][0], &d[i][1], &d[i][2]);
        conn[d[i][0]].push_back(data(d[i][1], i, d[i][2]));
        conn[d[i][1]].push_back(data(d[i][0], i, d[i][2]));
    }
    H.push(data2(1, 0, 0));
    for(i = 2; i <= N; i++) chk[i][0] = N+1;
    while(!H.empty()) {
        t1 = H.top().node;
        if(chk[t1][4] == 1) {
            H.pop();
            continue;
        }
        t2 = H.top().dis;
        t3 = H.top().chk;
        for(i = 0; i < t1[conn].size(); i++) {
            t4 = conn[t1][i];
            if(chk[t4.node][4] == 1) continue;
            t5 = t2+1;
            t6 = t3+t4.chk;
            if(chk[t4.node][0] > t5 || (chk[t4.node][1] <= t6 && chk[t4.node][0] == t5)) {
                chk[t4.node][0] = t5;
                chk[t4.node][1] = t6;
                chk[t4.node][2] = t1;
                chk[t4.node][3] = t4.line;
                H.push(data2(t4.node, t5, t6));
            }
        }
        chk[t1][4] = 1;
        H.pop();
    }
    t1 = N;
    while(1) {
        ans_chk[chk[t1][3]] = 1;
        t1 = chk[t1][2];
        if(t1 == 0) break;
    }
    for(i = 1; i <= M; i++) if(ans_chk[i] != d[i][2]) ans_cnt++;
    printf("%d\n", ans_cnt);
    for(i = 1; i <= M; i++) {
        if(ans_chk[i] != d[i][2]) {
            printf("%d %d %d\n", d[i][0], d[i][1], ans_chk[i]);
        }
    }
    return 0;
}