#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
char s[1000000];
int help[30];
int l[1000000];
int main() {
   // freopen("input","r", stdin);
    int T;
    for (int i = 0; i < 30; i ++)
        help[i] = 1 << i;
    scanf("%d", &T);
    while (T --){
        scanf("%s", s);
        int n = strlen(s);
        int ans = 0;
        for (int i = 1; i < n ; i ++)
            if (s[i - 1] == '0')
                l[i] = min(l[i - 1], i - 1);
            else
                l[i] = 1e9;
        for (int i = 0; i < n; i ++) {
            int v = 0;
            if (s[i] == '1')
            {
                int yy;
                yy = 0;
            }
            for (int j = i ; i - j + 1 <= 20; j --) {
                v += (s[j] - '0') * (1 << (i - j));
                ans += (v == i - j + 1);
                if (i - j + 1 == 20) {
                    if (v - (i - j + 1) > 0 && v - (i - j + 1) <= j - l[j])
                        ans ++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}