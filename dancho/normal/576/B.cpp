#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
int p[1 << 20];
int onc[1 << 20];
vector< vector<int> > cs;

bool us[1 << 20];

void dfs(int v) {
    if (onc[v]) {
        return;
    }
    onc[v] = 1;
    cs.back().push_back(v);
    dfs(p[v]);
}

int main() {
    scanf("%d", &n);
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
        if (p[i] == i) {
            s = i;
        }
    }
    
    if (s) {
        printf("YES\n");
        for (int i = 1; i <= n; ++i) {
            if (i != s) {
                printf("%d %d\n", i, s);
            }
        }
        return 0;
    }

    memset(onc, 0, sizeof(onc));

    int t = -1;
    for (int i = 1; i <= n; ++i) {
        if (!onc[i]) {
            cs.push_back(vector<int>());
            dfs(i);
            if (cs.back().size() == 2) {
                t = cs.size() - 1;
            }
            if (cs.back().size() % 2 == 1) {
                printf("NO\n");
                return 0;
            }
        }
    }
    if (t == -1) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    memset(us, 0, sizeof(us));
    printf("%d %d\n", cs[t][0], cs[t][1]);
    for (int i = 0; i < (int) cs.size(); ++i) {
        if (i == t) {
            continue;
        }
        for (int j = 0; j < (int) cs[i].size(); j += 2) {
            printf("%d %d\n", cs[t][0], cs[i][j]);
            printf("%d %d\n", cs[t][1], cs[i][j + 1]);
        }
    }
    return 0;
}