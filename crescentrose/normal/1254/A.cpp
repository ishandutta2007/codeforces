#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#define index index1
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
char s[1000][1000], ans[1000][1000];
int n, m, k, T;
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d", &n, &m, &k);
        int sum = 0;
        for (int i = 1; i <= n; i ++) {
            scanf("%s", s[i] + 1);
            for (int j = 1; j <= m; j ++)
                sum += (s[i][j] = (s[i][j] == 'R'));
        }
        int exp = sum % k;
        sum = sum / k;
        int id = 1, sum1 = sum + (exp > 0);
        exp --;
        for (int i = 1; i <= n; i ++) {
            if (i & 1) {
                for (int j = 1; j <= m; j ++) {
                    if (!sum1 && s[i][j]) {
                        sum1 = sum + (exp > 0);
                        exp --;
                        id ++;
                    }
                    sum1 -= s[i][j];
                    ans[i][j] = id;
                }
            } else {
                for (int j = m; j >= 1; j --) {
                    if (!sum1 && s[i][j]) {
                        sum1 = sum + (exp > 0);
                        exp --;
                        id ++;
                    }
                    sum1 -= s[i][j];
                    ans[i][j] = id;
                }
            }
        }
        for (int i = 1; i <= n; i++, printf("\n"))
            for (int j = 1; j <= m; j++)
                if (ans[i][j] <= 10)
                    printf("%c", ans[i][j] + '0' - 1);
                else
                    if (ans[i][j] <= 36) {
                        printf("%c", ans[i][j] + 'a' - 11);
                    } else
                        printf("%c", ans[i][j] + 'A' - 37);
    }
    return 0;
}