#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

struct trnd {
    int son[26];
    string ter;
};

int n, w;
int ml = 0;
char in[10020];

char buf[1024];
char lwr[1024];
int dp[10020];

int ln = 0;
trnd tr[1 << 20];

void trie_insert() {
    int v = 0;
    for (int i = strlen(buf) - 1; i >= 0; --i) {
        int t = lwr[i] - 'a';
        if (tr[v].son[t] == -1) {
            ++ln;
            tr[v].son[t] = ln;
            memset(tr[ln].son, -1, sizeof(tr[ln].son));
        }
        v = tr[v].son[t];
    }
    tr[v].ter = buf;
}

vector<string> sol;

int go(int pos) {
    if (pos >= n) {
        return 1;
    }
    if (dp[pos] != -1) {
        return dp[pos];
    }
    int v = 0;
    for (int i = 1; i <= ml && pos + i <= n; ++i) {
        int t = in[pos + i - 1] - 'a';
        if (tr[v].son[t] != -1) {
            v = tr[v].son[t];
        } else {
            break;
        }
        if (tr[v].ter != "" && go(pos + i)) {
            sol.push_back(tr[v].ter);
            dp[pos] = 1;
            return 1;
        }
    }
    dp[pos] = 0;
    return dp[pos];
}

int main() {
    memset(tr[0].son, -1, sizeof(tr[0].son));
    scanf("%d", &n);
    scanf("%s", in);
    scanf("%d", &w);
    for (int i = 0; i < w; ++i) {
        scanf("%s", buf);
        int ln = strlen(buf);
        ml = max(ml, ln);
        memcpy(lwr, buf, ln);
        for (int j = 0; j < ln; ++j) {
            if (lwr[j] >= 'A' && lwr[j] <= 'Z') {
                lwr[j] = lwr[j] - 'A' + 'a';
            }
        }
        trie_insert();
    }

    memset(dp, -1, sizeof(dp));
    go(0);
    for (int i = (int) sol.size() - 1; i >= 0; --i) {
        printf("%s%c", sol[i].c_str(), " \n"[!i]);
    }
    return 0;
}