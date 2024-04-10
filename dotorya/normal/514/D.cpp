#include <stdio.h>
#include <vector>
using namespace std;
struct data {
    data(int a, int b) {
        n = a, p = b;
    }
    int n, p;
};
vector <data> t[6];
int start[6];
int d[100050][6];
int main() {
    int N, M, K, i, j, k, st, en, mi, chk, ans[6]= {0,0,0,0,0,0}, t_sum, t_ans[6];
    scanf("%d %d %d", &N, &M, &K);
    for(i = 1; i <= N; i++) for(j = 1; j <= M; j++) scanf("%d", &d[i][j]);
    st = 1, en = N;
    while(st <= en) {
        chk = 0;
        for(i = 1; i <= M; i++) {
            start[i] = 0;
            t[i].clear();
        }
        mi = (st+en)/2;
        for(i = 1; i <= mi-1; i++) {
            for(j = 1; j <= M; j++) {
                for(k = t[j].size()-1; k >= start[j]; k--) {
                    if(t[j][k].n < d[i][j]) t[j].pop_back();
                    else break;
                }
                t[j].push_back(data(d[i][j], i));
            }
        }
        for(i = mi; i <= N; i++) {
            t_sum = 0;
            for(j = 1; j <= M; j++) {
                while(start[j] < t[j].size()) {
                    if(t[j][start[j]].p + mi <= i) start[j]++;
                    else break;
                }
                for(k = t[j].size()-1; k >= start[j]; k--) {
                    if(t[j][k].n < d[i][j]) t[j].pop_back();
                    else break;
                }
                t[j].push_back(data(d[i][j], i));
                t_sum += t[j][start[j]].n;
                t_ans[j] = t[j][start[j]].n;
            }
            if(t_sum <= K) break;
        }
        if(i != N+1) {
            for(j = 1; j <= M; j++) ans[j] = t_ans[j];
            st = mi+1;
        }
        else en = mi-1;
    }
    for(i = 1; i <= M; i++) printf("%d ", ans[i]);
    return 0;
}