#include <stdio.h>
#include <algorithm>
#include <vector>
struct data {
    data(int a, int b) {
        node = a;
        chk = b;
    }
    int node, chk;
};
using namespace std;
vector <data> conn[100050];
vector <int> odd_chk;
int cnt[100050];
int d[300050][2];
int chk[300050];
vector <int> ANS;
void dfs(int node, int chk_l) {
    int i;
    data t = data(0,0);
    while(!conn[node].empty()) {
        t = conn[node].back();
        if(chk[t.chk] == 1) {
            conn[node].pop_back();
            continue;
        }
        chk[t.chk] = 1;
        conn[node].pop_back();
        if(node > t.node) t.chk *= -1;
        dfs(t.node, t.chk);
    }
    if(chk_l != 0) ANS.push_back(chk_l);
    return;
}
int main() {
    int N, M, i, t, t1, t2;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= M; i++) {
        scanf("%d %d", &d[i][0], &d[i][1]);
        if(d[i][0] > d[i][1]) swap(d[i][0], d[i][1]);
        conn[d[i][0]].push_back(data(d[i][1], i));
        conn[d[i][1]].push_back(data(d[i][0], i));
        cnt[d[i][0]]++;
        cnt[d[i][1]]++;
    }
    for(i = 1; i <= N; i++) {
        if(cnt[i] % 2 != 0) odd_chk.push_back(i);
    }
    t = M;
    while(!odd_chk.empty()) {
        t++;
        t1 = odd_chk.back();
        odd_chk.pop_back();
        t2 = odd_chk.back();
        odd_chk.pop_back();
        if(t1 > t2) swap(t1, t2);
        d[t][0] = t1, d[t][1] = t2;
        conn[t1].push_back(data(t2, t));
        conn[t2].push_back(data(t1, t));
    }
    if(t % 2 == 1) {
        t++;
        d[t][0] = d[t][1] = 1;
        conn[1].push_back(data(1,t));
        conn[1].push_back(data(1,t));
    }
    printf("%d\n", t);
    dfs(1, 0);
    while(!ANS.empty()) {
        t1 = ANS.back();
        ANS.pop_back();
        t2 = ANS.back();
        ANS.pop_back();
        if(t1 > 0 && t2 > 0) {
            printf("%d %d\n", d[t1][0], d[t1][1]);
            printf("%d %d\n", d[t2][1], d[t2][0]);
        }
        else if(t1 > 0 && t2 < 0) {
            printf("%d %d\n", d[t1][0], d[t1][1]);
            printf("%d %d\n", d[-t2][0], d[-t2][1]);
        }
        else if(t1 < 0 && t2 > 0) {
            printf("%d %d\n", d[-t1][1], d[-t1][0]);
            printf("%d %d\n", d[t2][1], d[t2][0]);
        }
        else {
            printf("%d %d\n", d[-t1][1], d[-t1][0]);
            printf("%d %d\n", d[-t2][0], d[-t2][1]);
        }
    }
    return 0;
}