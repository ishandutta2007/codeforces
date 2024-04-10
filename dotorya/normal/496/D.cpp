#include <stdio.h>
#include <algorithm>
struct data {
    int s, t;
    bool operator < (const data & l) const {
        if(s != l.s) return s <l.s;
        else return t < l.t;
    }
} ans[200050];
int d[100050];
int d1[100050];
int d2[100050];
int c_win[100050][3];
int main() {
    int N, i, t1 = 0, t2 = 0, cnt1, cnt2, cnt_ans = 0, win_set1, win_set2, c_p;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d", &d[i]);
        if(d[i] == 1) {
            t1++;
            d1[t1] = i;
            c_win[i][1] = c_win[i-1][1]+1;
            c_win[i][2] = c_win[i-1][2];
        }
        else {
            t2++;
            d2[t2] = i;
            c_win[i][1] = c_win[i-1][1];
            c_win[i][2] = c_win[i-1][2]+1;
        }
    }
    for(i = 1; i <= N; i++) {
        cnt1 = 0, cnt2 = 0, win_set1 = 0, win_set2 = 0, c_p = 0;
        while(1) {
            if(t1 < cnt1+i && t2 < cnt2+i) break;
            if(t1 < cnt1+i) {
                win_set2++;
                c_p = d2[cnt2+i];
                cnt1 = c_win[c_p][1], cnt2 = c_win[c_p][2];
            }
            else if(t2 < cnt2+i) {
                win_set1++;
                c_p = d1[cnt1+i];
                cnt1 = c_win[c_p][1], cnt2 = c_win[c_p][2];
            }
            else {
                if(d1[cnt1+i] > d2[cnt2+i]) {
                    win_set2++;
                    c_p = d2[cnt2+i];
                    cnt1 = c_win[c_p][1], cnt2 = c_win[c_p][2];
                }
                else {
                    win_set1++;
                    c_p = d1[cnt1+i];
                    cnt1 = c_win[c_p][1], cnt2 = c_win[c_p][2];
                }
            }
            if(c_p == N) break;
        }
        if(c_p != N) continue;
        if(win_set2 > win_set1 && d[N] == 2) {
            cnt_ans++;
            ans[cnt_ans].s = win_set2, ans[cnt_ans].t = i;
        }
        if(win_set2 < win_set1 && d[N] == 1) {
            cnt_ans++;
            ans[cnt_ans].s = win_set1, ans[cnt_ans].t = i;
        }
    }
    std::sort(ans+1, ans+cnt_ans+1);
    printf("%d\n", cnt_ans);
    for(i = 1; i <= cnt_ans; i++) {
        printf("%d %d\n", ans[i].s, ans[i].t);
    }
    return 0;
}