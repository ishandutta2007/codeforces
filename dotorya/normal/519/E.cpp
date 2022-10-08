#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> conn[100050];
int N, M;
int pow_2[20] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
int lvl[100050];
int son[100050];
int dfs_chk[100050];
int parent[100050][20];
void dfs(int node, int level) {
    lvl[node] = level;
    dfs_chk[node] = 1;
    int i, j, sum = 0;
    for(i = 0; i < conn[node].size(); i++) {
        if(dfs_chk[conn[node][i]] == 1) continue;
        parent[conn[node][i]][0] = node;
        for(j = 1; level+1 >= pow_2[j]; j++) {
            parent[conn[node][i]][j] = parent[parent[conn[node][i]][j-1]][j-1];
        }
        dfs(conn[node][i], level+1);
        sum += son[conn[node][i]];
    }
    son[node] = sum+1;
    return;
}
void input() {
    int i, t1, t2;
    scanf("%d", &N);
    for(i = 1; i <= N-1; i++) {
        scanf("%d %d", &t1, &t2);
        conn[t1].push_back(t2);
        conn[t2].push_back(t1);
    }
    dfs(1,0);
    return;
}
int above_lvl(int n, int lvl) {
    for(int i = 17; i >= 0; i--) {
        if(lvl >= pow_2[i]) {
            n = parent[n][i];
            lvl -= pow_2[i];
        }
    }
    return n;
}
int get_LCA(int n1, int n2) {
    int st, i;
    if(lvl[n1] < lvl[n2]) swap(n1, n2);
    if(lvl[n1] > lvl[n2]) {
        n1 = above_lvl(n1, lvl[n1]-lvl[n2]);
    }
    for(st = 17; st >= 0; st--) {
        if(lvl[n1] >= pow_2[st]) break;
    }
    for(i = st; i >= 0; i--) {
        if(parent[n1][i] != parent[n2][i]) {
            n1 = parent[n1][i];
            n2 = parent[n2][i];
        }
    }
    if(n1 != n2) return parent[n1][0];
    else return n1;
}
void get_ans() {
    int i, t1, t2, t3, t4, t5, t6, t7;
    scanf("%d", &M);
    for(i = 1; i <= M; i++) {
        scanf("%d %d", &t1, &t2);
        if(t1 == t2) {
            printf("%d\n", N);
            continue;
        }
        if((lvl[t1]-lvl[t2])%2 != 0) {
            printf("0\n");
            continue;
        }
        if(lvl[t1] == lvl[t2]) {
            t3 = get_LCA(t1, t2);
            t4 = lvl[t1]-lvl[t3];
            t5 = above_lvl(t1, t4-1);
            t6 = above_lvl(t2, t4-1);
            printf("%d\n", N-son[t5]-son[t6]);
            continue;
        }
        if(lvl[t1] < lvl[t2]) swap(t1, t2);
        t3 = get_LCA(t1, t2);
        t4 = lvl[t1]-lvl[t3];
        t5 = lvl[t2]-lvl[t3];
        t6 = above_lvl(t1, (t4+t5)/2);
        t7 = above_lvl(t1, (t4+t5)/2-1);
        printf("%d\n", son[t6]-son[t7]);
    }
    return;
}
int main() { 
    input();
    get_ans();
    return 0;
}