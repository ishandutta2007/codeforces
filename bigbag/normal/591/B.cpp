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

int n, m;
char s[max_n], q[222];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%s", &n, &m, s);
    for (char i = 'a'; i <= 'z'; ++i) {
        q[i] = i;
    }
    while (m--) {
        char a, b;
        scanf("\n%c %c", &a, &b);
        int f = 0;
        for (char i = 'a'; i <= 'z'; ++i) {
            for (char j = 'a'; j <= 'z'; ++j) {
                if (q[i] == a && q[j] == b) {
                    f = 1;
                    swap(q[i], q[j]);
                    break;
                }
            }
            if (f == 1) {
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        s[i] = q[s[i]];
    }
    printf("%s\n", s);
    return 0;
}