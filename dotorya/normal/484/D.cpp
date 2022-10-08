#include <stdio.h>
int d[1000050];
__int64 ans[1000050];
__int64 MAX(__int64 a, __int64 b) {
    if(a<b) return b;
    else return a;
}
int main() {
    long long max_num, max_ans;
    long long min_num, min_ans;
    int N, i, t;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &d[i]);
    max_num = min_num = d[1], max_ans = min_ans = 0;
    for(i = 2; i <= N; i++) {
        ans[i] = 0;
        if(max_num >= d[i]) ans[i] = MAX(ans[i], max_num-d[i]+max_ans);
        if(min_num <= d[i]) ans[i] = MAX(ans[i], d[i]-min_num+min_ans);
        ans[i] = MAX(ans[i], ans[i-1]);
        if(ans[i-1]+d[i] >= max_num+max_ans) {
            max_num = d[i];
            max_ans = ans[i-1];
        }
        if(ans[i-1]-d[i] >= min_ans-min_num) {
            min_ans = ans[i-1];
            min_num = d[i];
        }
    }
    printf("%I64d", ans[N]);
    return 0;
}