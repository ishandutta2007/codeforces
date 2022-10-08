#include <stdio.h>
#include <vector>
using namespace std;
int chk[100050];
int dfs_chk[100050];
vector <int> conn[100050];
vector <int> ANS;

int Q[100050];

int DFS(int node) {
    int i;
    ANS.push_back(node);
    dfs_chk[node] = 2;
    chk[node] = 1-chk[node];

    for(int i = 0; i < conn[node].size(); i++) {
        int j = conn[node][i];
        if(dfs_chk[j] == 2) continue;
        if(DFS(j)) {
            ANS.push_back(node);
            ANS.push_back(j);
            chk[node] = 1-chk[node];
            chk[j] = 1-chk[j];
        }
        ANS.push_back(node);
        chk[node] = 1-chk[node];
    }
    
    return chk[node];
}
int main() {
    int N, M, i, j, t1, t2, st, en;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= M; i++) {
        scanf("%d %d", &t1, &t2);
        conn[t1].push_back(t2);
        conn[t2].push_back(t1);
    }
    for(i = 1; i <= N; i++) scanf("%d", &chk[i]);

    // BFS
    for(i = 1; i <= N; i++) {
        if(dfs_chk[i] == 2) continue;
        st = 1, en = 2, Q[1] = i;
        while(st < en) {
            t1 = Q[st];
            if(chk[t1] == 1) break;
            dfs_chk[t1] = 1;
            for(j = 0; j < conn[t1].size(); j++) {
                t2 = conn[t1][j];
                if(dfs_chk[t2] == 1) continue;
                dfs_chk[t2] = 1;
                Q[en++] = t2;
            }
            st++;
        }
        if(st == en) {
            st = 1, en = 2, Q[1] = i;
            while(st < en) {
                t1 = Q[st];
                for(j = 0; j < conn[t1].size(); j++) {
                    t2 = conn[t1][j];
                    if(dfs_chk[t2] == 2) continue;
                    dfs_chk[t2] = 2;
                    Q[en++] = t2;
                }
                st++;
            }
            continue;
        }
        if(!ANS.empty()) break;
        if(DFS(i)) ANS.pop_back();
    }
    if(i != N+1) printf("-1");
    else {
        printf("%d\n", ANS.size());
        for(i = 0; i < ANS.size(); i++) printf("%d ", ANS[i]);
    }
    return 0;
}