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

const int max_n = 555555, max_f = 30, inf = 1111111111;

int n, first, cnt[max_n * max_f], nxt[max_n * max_f][2];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

void add(int x) {
    int v = 0;
    for (int i = max_f - 1; i >= 0; --i) {
        int b = get_bit(x, i);
        if (nxt[v][b] == -1) {
            ++first;
            nxt[v][b] = first;
        }
        v = nxt[v][b];
        ++cnt[v];
    }
}

void err(int x) {
    int v = 0;
    for (int i = max_f - 1; i >= 0; --i) {
        int b = get_bit(x, i);
        v = nxt[v][b];
        --cnt[v];
    }
}

int get(int x) {
    int res = 0, v = 0;
    for (int i = max_f - 1; i >= 0; --i) {
        int b = get_bit(x, i) ^ 1;
        if (nxt[v][b] == -1 || cnt[nxt[v][b]] == 0) {
            b ^= 1;
        } else {
            res += (1 << i);
        }
        v = nxt[v][b];
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(nxt, -1, sizeof(nxt));
    scanf("%d", &n);
    add(0);
    while (n--) {
        char c;
        int x;
        scanf("\n%c%d", &c, &x);
        if (c == '+') {
            add(x);
        } else if (c == '-') {
            err(x);
        } else {
            printf("%d\n", get(x));
        }
    }
    return 0;
}