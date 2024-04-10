#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> g[100020];
bool iss[100020];
int par[100020];
int tn[100020][4];
int tp[100020];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > q;

bool done(int v) {
    if (tp[v] != -1) {
        return false;
    }
    // printf("DONE? %d :: %d %d\n", v, (int) g[v].size(), tn[v][0] + tn[v][1] + tn[v][2] + tn[v][3]);
    if (tn[v][0] + tn[v][1] + tn[v][2] + tn[v][3] < (int) g[v].size() - 1) {
        return false;
    }
    if (tn[v][2] || tn[v][3]) {
        tp[v] = 3;
        return true;
    }
    if (tn[v][1] + tn[v][0] <= 1) {
        tp[v] = 1;
        return true;
    }
    if (tn[v][0] + tn[v][1] <= 2) {
        tp[v] = 2;
        return true;
    }
    tp[v] = 3;
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(tp, -1, sizeof(tp));

    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1) {
            tp[i] = 0;
            q.push(make_pair(0, i));
        }
    }

    while (q.size()) {
        int a = q.top().second;
        // printf("POP %d\n", a);
        q.pop();
        for (int i = 0; i < (int) g[a].size(); ++i) {
            int b = g[a][i];
            tn[b][ tp[a] ]++;
            if (done(b)) {
                q.push(make_pair(tp[b], b));
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        // printf("TP %d %d\n", i, tp[i]);
        int trn = 0;
        for (int j = 0; j < (int) g[i].size(); ++j) {
            if (tp[g[i][j]] == 3) {
                ++trn;
            }
        }
        if (trn >= 3) {
            printf("No\n");
            return 0;
        }
        if (trn == 2 && tp[i] != 3) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}