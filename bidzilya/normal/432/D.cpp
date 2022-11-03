#include <iostream>
#include <algorithm>
#include <vector>

#include <cstring>
#include <cassert>
using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;

int n;
char s[max_n];
int z[max_n];
int good_len[max_n];
int ans[max_n];

int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%s\n", s);
    n = strlen(s);
    
    z[0] = n;
    for (int i = 1, l = -1, r = -1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        } else {
            z[i] = 0;
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    for (int len = 1; len <= n; ++len) {
        good_len[len] = (z[n - len] >= len);
        ans[len] = 0;
    }
    
    for (int pos = 0; pos < n; ++pos)
        ++ans[z[pos]];
    
    for (int len = n - 1; len > 0; --len)
        ans[len] += ans[len + 1];
    
    int cnt = 0;
    for (int len = 1; len <= n; ++len)
        cnt += good_len[len];
    
    printf("%d\n", cnt);
    for (int len = 1; len <= n; ++len)
        if (good_len[len])
            printf("%d %d\n", len, ans[len]);
    return 0;
}