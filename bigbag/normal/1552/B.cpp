/**
 *  created: 25/07/2021, 17:39:50
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 50555, inf = 1000111222;

int t, n;
array<int, 5> a[max_n];

bool is_better(int id, int i) {
    int cnt = 0;
    for (int j = 0; j < 5; ++j) {
        cnt += a[id][j] < a[i][j];
    }
    return cnt >= 3;
}

bool check(int id) {
    for (int i = 0; i < n; ++i) {
        if (i == id) {
            continue;
        }
        if (!is_better(id, i)) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        int id = 0;
        for (int i = 1; i < n; ++i) {
            if (is_better(i, id)) {
                id = i;
            }
        }
        if (check(id)) {
            printf("%d\n", id + 1);
        } else {
            puts("-1");
        }
    }
    return 0;
}