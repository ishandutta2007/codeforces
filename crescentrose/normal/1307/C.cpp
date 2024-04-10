#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
char s[N];
long long sum[26][26], cnt[26];
int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 26; j ++)
            sum[j][s[i] - 'a'] += cnt[j];
        cnt[s[i] - 'a'] ++;
    }
    long long ans = 0;
    for (int i = 0; i < 26; i ++)
        for (int j = 0; j < 26; j ++)
            ans = max(ans, max(sum[i][j], cnt[j]));
    printf("%lld\n", ans);
    return 0;
}