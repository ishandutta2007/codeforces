#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 222222, inf = 1111111111;

int n, a, b, k;
char s[max_n];
vector<pair<int, int> > ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &a, &b, &k);
    scanf("%s", s);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int len = 0;
        while (i < n && s[i] == '0') {
            ++i;
            ++len;
        }
        mx += len / b;
    }
    int cnt = mx - a + 1;
    for (int i = 0; i < n; ++i) {
        int len = 0, st = i;
        while (i < n && s[i] == '0') {
            ++i;
            ++len;
        }
        int num = 0;
        for (int j = st + b - 1; j < i; j += b) {
            ++num;
            ans.push_back(make_pair(num, j + 1));
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) {
        printf("%d ", ans[i].second);
    }
    printf("\n");
    return 0;
}