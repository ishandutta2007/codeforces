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

const int max_n = 222222, inf = 1011111111;

int n, used[max_n];
char s[max_n];
set<int> q[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'D') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
        q[s[i]].insert(i);
    }
    while (true) {
        for (int i = 0; i < n; ++i) {
            if (used[i] == 0) {
                int num = s[i] ^ 1;
                if (q[num].size() == 0) {
                    if (s[i] == 0) {
                        printf("D\n");
                    } else {
                        printf("R\n");
                    }
                    return 0;
                }
                set<int>::iterator it = q[num].lower_bound(i);
                if (it == q[num].end()) {
                    it = q[num].begin();
                }
                int pos = *it;
                used[pos] = 1;
                q[num].erase(pos);
            }
        }
    }
    return 0;
}