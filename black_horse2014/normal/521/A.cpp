#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

#define N 100005
#define MOD 1000000007

const char pat[] = "ACGT";
int cnt[4];
char s[N];

int main() {
    int n, i, j, mx, tot, ans;
    scanf("%d", &n);
    scanf("%s", s);
    for (i = 0; i < n; i++) {
        j = strchr(pat, s[i]) - pat;
        cnt[j]++;
    }
    for (mx = i = 0; i < 4; i++) mx = max(mx, cnt[i]);
    for (tot = i = 0; i < 4; i++) if (cnt[i] == mx) tot++;
    for (ans = 1, i = 0; i < n; i++) ans = 1LL * ans * tot % MOD;
    printf("%d\n", ans);
    return 0;
}