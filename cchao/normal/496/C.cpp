#include <bits/stdc++.h>
using namespace std;

char s[1010][1010];
int n, m;
bool ok[1010] = {};
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
        scanf("%s", s[i]);
    int ans = 0;
    for(int j = 0; j < m; ++j) {
        bool f = false;
        for(int i = 0; i + 1 < n; ++i)
            if(s[i][j] > s[i+1][j] && !ok[i]) {
                f = true;
                break;
            }
        if(f) ans++;
        else {
            for(int i = 0; i + 1 < n; ++ i)
                if(s[i][j] < s[i+1][j])
                    ok[i] = true;
        }
    }
    printf("%d\n", ans);
    return 0;
}