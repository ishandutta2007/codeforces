#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;

int n;
char s[1 << 20];

int cr[1 << 20][2];

bool can_reach(int ps, int t) {
    if (cr[ps][t] != -1) {
        return cr[ps][t];
    }
    if (ps >= n) {
        return (ps == n);
    }
    int st = ps - t - 2;
    bool ok = false;
    for (int ln = ps + 2; ln <= ps + 3; ++ln) {
        bool same = true;
        if (ln - ps - 2 != t) {
            same = false;
        } else {
            for (int i = 0; st + i < ps; ++i) {
                if (s[st + i] != s[ps + i]) {
                    same = false;
                }
            }
        }
        if (!same) {
            ok |= can_reach(ln, ln - ps - 2);
        }
    }
    return (cr[ps][t] = ok);
}

int main() {
    scanf("%s", s);
    n = strlen(s);

    memset(cr, -1, sizeof(cr));
    set<string> ans;
    for (int i = 5; i < n; ++i) {
        for (int j = i + 2; j <= i + 3; ++j) {
            if (j <= n) {
                if (can_reach(j, j - i - 2)) {
                    string x = "";
                    for (int k = i; k < j; ++k) {
                        x += s[k];
                    }
                    ans.insert(x);
                }
            }
        }
    }
    printf("%d\n", (int) ans.size());
    for (const auto &x: ans) {
        printf("%s\n", x.c_str());
    }
    return 0;
}