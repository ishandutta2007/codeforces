#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int d[300050];
pair <int, int> d2[300050];
bool chk[300050];
int ans_chk[300050];
vector <int> ANS;
int main() {
    int N, i, j;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d", &d[i]);
        d2[i].first = d[i];
        d2[i].second = i;
    }
    sort(d2+1, d2+N+1);
    for(i = 1; i <= N; i++) {
        int t1 = d2[i].second;
        if(chk[t1]) continue;
        chk[t1] = true;
        int st, en;
        for(j = t1-1; j >= 1; j--) {
            if(d[j]%d[t1] != 0) break;
            chk[j] = true;
        }
        st = j+1;
        for(j = t1+1; j <= N; j++) {
            if(d[j]%d[t1] != 0) break;
            chk[j] = true;
        }
        en = j-1;
        ans_chk[st] = en-st;
    }
    int max = 0;
    for(i = 1; i <= N; i++) if(ans_chk[i] > max) max = ans_chk[i];
    for(i = 1; i <= N; i++) if(ans_chk[i] == max) ANS.push_back(i);
    printf("%d %d\n", ANS.size(), max);
    for(i = 0; i < ANS.size(); i++) printf("%d ", ANS[i]);
    return 0;
}