#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct data {
    int st, en, bin[35];
    bool operator < (const data & l) const {
        if(st != l.st) return st < l.st;
        else return en > l.en;
    }
} d[100050];
struct data2 {
    int st, en, chk;
} tmp;
int start_chk[100050];
int ans[100050][30];
int ANS[100050];
int sum[100050];
int N, M;
vector <data2> V;
void input() {
    int i, t, j;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= M; i++) {
        scanf("%d %d %d", &d[i].st, &d[i].en, &t);
        for(j = 0; j < 30; j++) {
            d[i].bin[j] = t%2;
            t/=2;
        }
    }
    sort(d+1, d+M+1);
    start_chk[d[1].st] = 1;
    for(i = 1; i <= M-1; i++) {
        if(d[i].st != d[i+1].st) start_chk[d[i+1].st] = i+1;
    }
    return;
}
void get_ans() {
    int t, i, j, S, cnt;
    for(t = 0; t < 30; t++) {
        for(i = 1; i <= M; i++) {
            if(d[i].bin[t] == 1) {
                tmp.st = d[i].st;
                tmp.en = d[i].en;
                tmp.chk = i;
                V.push_back(tmp);
            }
        }
        S = V.size();
        if(V.empty()) continue;
        for(i = V[0].st; i <= V[0].en; i++) ans[i][t] = 1;
        cnt = V[0].en+1;
        for(i = 1; i < S; i++) {
            if(V[i].st > cnt) cnt = V[i].st;
            if(V[i].en >= cnt) {
                for(j = cnt; j <= V[i].en; j++) ans[j][t] = 1;
                cnt = V[i].en+1;
            }
        }
        for(i = 1; i <= N; i++) sum[i] = sum[i-1] + ans[i][t];
        for(i = 1; i <= M; i++) {
            if(d[i].bin[t] == 0) {
                if(sum[d[i].en] - sum[d[i].st-1] == d[i].en-d[i].st+1) break;
            }
        }
        V.clear();
        if(i != M+1) break;
    }
    if(t != 30) {
        printf("NO");
        return;
    }
    int t1 = 1;
    for(i = 0; i < 30; i++) {
        for(j = 1; j <= N; j++) ANS[j] += ans[j][i]*t1;
        t1 *= 2;
    }
    printf("YES\n");
    for(i = 1; i <= N; i++) printf("%d ", ANS[i]);
    return;
}
int main() {
    input();
    get_ans();
    return 0;
}