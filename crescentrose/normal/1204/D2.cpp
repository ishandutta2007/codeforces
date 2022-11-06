#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
char s[1000001];
int n;
vector<int>g[1000001];
int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0;i < n; i ++ )
        s[i] -= '0';
    int l = 0;
    int tot = 0;
    for (int i = 0; i < n ; i ++)
        if (i != n - 1 && s[i] == 1 &&  s[i + 1] == 0) {
            ++tot;
            for (int j = l ; j < i; j ++)
                g[tot].push_back(j);
            l = i + 2;
        }
    if (l < n) {
        ++tot;
        for (int j = l; j < n; j++)
            g[tot].push_back(j);
    }
    ++tot;
    int sum0 = 0;
    for (int i = tot - 1; i >= 1; i --){
        int sum1 = 0;
        for (auto u:g[i])
            if (s[u] == 1)
                sum1 ++;
        for (auto v:g[i + 1])
            if (s[v] == 0)
                sum0 ++;
        for (auto u:g[i])
            if (sum1 > sum0 && s[u] == 1) {
                s[u] = -1;
                sum1 --;
            }
        sum0 = max(sum0 - sum1, 0);
    }
    for (int i = 0;i < n; i++)
        printf("%d", (int)max((int)s[i], 0));
    return 0;
}