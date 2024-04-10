#include <stdio.h>
#include <vector>
using namespace std;
const int MX = 131072;
vector <int> V1;
vector <int> V2;
struct data {
    data() {
        int i;
        for(i = 0; i <= 59; i++) d[i] = i;
    }
    int d[60];
} it[MX*2];
void update(int pos, int n) {
    int i, t = pos, t2;
    for(i = 0; i < 60; i++) {
        if(i % n == 0) it[pos].d[i] = i+2;
        else it[pos].d[i] = i+1;
    }
    while(t > 1) {
        t /= 2;
        for(i = 0; i < 60; i++) {
            t2 = it[2*t].d[i];
            it[t].d[i] = (t2/60)*60+it[2*t+1].d[t2%60];
        }
    }
    return;
}
void get_ans(int st, int en) {
    if(st == en) {
        V1.push_back(st);
        return;
    }
    if(st % 2 == 1) {
        V1.push_back(st);
        st++;
    }
    if(st == en) {
        V1.push_back(st);
        return;
    }
    if(en % 2 == 0) {
        V2.push_back(en);
        en--;
    }
    get_ans(st/2, en/2);
}
int main() {
    int N, i, j, Q, t, t1, t2;
    char chk[2];
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        scanf("%d", &t);
        update(MX+i, t);
    }
    scanf("%d", &Q);
    for(i = 1; i <= Q; i++) {
        scanf("%s %d %d" , chk, &t1, &t2);
        if(chk[0] == 'C') {
            update(MX+t1-1, t2);
            continue;
        }
        get_ans(MX+t1-1, MX+t2-2);
        int ans = 0;
        for(j = 0; j < V1.size(); j++) {
            t = V1[j];
            ans = it[t].d[ans%60]+(ans/60)*60;
        }
        for(j = V2.size()-1; j >= 0; j--) {
            t = V2[j];
            ans = it[t].d[ans%60]+(ans/60)*60;
        }
        printf("%d\n", ans);
        V1.clear();
        V2.clear();
    }
    return 0;
}