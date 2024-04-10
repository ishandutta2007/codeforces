#include <cstdio>
#include <iostream>
using namespace std;


char s[2010];
int ans[2010] = {};
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%s", s);
        for(int j = 0; j < m; ++j) {
            if(s[j] != '.') {
                int p = -1;
                if(s[j] == 'R') {
                    p = j + i;
                }
                if(s[j] == 'L') {
                    p = j - i;
                }
                if(s[j] == 'U') {
                    if(i % 2 == 0)
                        p = j;
                }
                if(s[j] == 'D') {
                    //
                }
                if(p>=0 && p < m)
                    ans[p]++;
            }
        }
    }
    for(int i = 0; i < m; ++i)
        printf("%d%c", ans[i], i == m-1 ? '\n' : ' ');
    return 0;
}