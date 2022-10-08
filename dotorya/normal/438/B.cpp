#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct data {
    __int64 n, chk;
    bool operator < (const data & l) const {
        return n < l.n;
    }
} d[100050];
int c[100050], N, M;
int size[100050];
int root[100050];
__int64 ANS = 0;
vector <int> con[100050];
void input() {
    int i, t1, t2;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) {
        scanf("%I64d", &d[i].n);
        d[i].chk = i;
        root[i] = i;
        size[i] = 1;
    }
    sort(d+1, d+N+1);
    for(i = 1; i <= N; i++) c[d[i].chk] = i;
    for(i = 1; i <= M; i++) {
        scanf("%d %d", &t1, &t2);
        con[c[t1]].push_back(c[t2]);
        con[c[t2]].push_back(c[t1]);
    }
    return;
}
int get_root(int x) {
    while(x != root[x]) {
        root[x] = root[root[x]];
        x = root[x];
    }
    return x;
}
void unionandfind() {
    int i, j;
    for(i = N; i >= 1; i--) {
        for(j = 0; j < con[i].size(); j++) {
            if(con[i][j] < i) continue;
            if(get_root(i) == get_root(con[i][j])) continue;
            ANS += d[i].n * size[get_root(i)] * size[get_root(con[i][j])];
            size[get_root(con[i][j])] += size[get_root(i)];
            root[get_root(i)] = get_root(con[i][j]);
        }
    }
    printf("%.8lf", (1.0*ANS*2/N)/(N-1));
    return;
}
int main() {
    input();
    unionandfind();
    return 0;
}