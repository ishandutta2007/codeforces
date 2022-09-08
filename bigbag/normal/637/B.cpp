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

const int max_n = 201111, max_l = 11;

int n;
char s[max_n][max_l];
set<string> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (!q.count(s[i])) {
            printf("%s\n", s[i]);
            q.insert(s[i]);
        }
    }
    return 0;
}