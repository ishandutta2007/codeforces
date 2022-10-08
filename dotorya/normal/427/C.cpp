#include <stdio.h>
#include <vector>
typedef long long ll;
using namespace std;
vector <int> conn[100050];
vector <int> rev_conn[100050];
vector <int> scc;
bool dfs_chk[100050];
ll MOD = 1000000007;
ll cost[100050];
int scc_result[100050];
int queue[100050];
ll mn[100050][2];
void dfs(int node) {
    int i, t;
    dfs_chk[node] = true;
    for(i = 0; i < conn[node].size(); i++) {
        t = conn[node][i];
        if(dfs_chk[t]) continue;
        dfs(t);
    }
    scc.push_back(node);
    return;
}
void get_scc(int node, int val) {
    int st = 1, en = 2, t, i;
    queue[1] = node;
    scc_result[node] = val;
    mn[val][0] = cost[node];
    mn[val][1] = 1;
    while(st < en) {
        t = queue[st];
        for(i = 0; i < rev_conn[t].size(); i++) {
            if(scc_result[rev_conn[t][i]] != 0) continue;
            queue[en++] = rev_conn[t][i];
            scc_result[rev_conn[t][i]] = val;
            if(cost[rev_conn[t][i]] < mn[val][0]) {
                mn[val][0] = cost[rev_conn[t][i]];
                mn[val][1] = 1;
            }
            else if(cost[rev_conn[t][i]] == mn[val][0]) mn[val][1]++;
        }
        st++;
    }
    return;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int N, M, i, j, t1, t2;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%lld", &cost[i]);
        mn[i][0] = MOD;
    }
    scanf("%d", &M);
    for(i = 1; i <= M; i++) {
        scanf("%d %d", &t1, &t2);
        conn[t1].push_back(t2);
        rev_conn[t2].push_back(t1);
    }
    for(i = 1; i <= N; i++) {
        if(dfs_chk[i]) continue;
        dfs(i);
    }
    t1 = 1;
    while(!scc.empty()) {
        t2 = scc.back();
        scc.pop_back();
        if(scc_result[t2] != 0) continue;
        get_scc(t2, t1);
        t1++;
    }
    ll ANS1 = 0, ANS2 = 1;
    for(i = 1; i < t1; i++) {
        ANS1 += mn[i][0];
        ANS2 = (ANS2 * mn[i][1]) % MOD;
    }
    printf("%lld %lld", ANS1, ANS2);
    return 0;
}