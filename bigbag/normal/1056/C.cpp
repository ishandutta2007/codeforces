#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111222;

int n, m, a[max_n], used[max_n], to[max_n];
int num, steps;

int read() {
    ++steps;
    int x;
    cin >> x;
    --x;
    used[x] = 1;
    if (steps == 2 * n) {
        exit(0);
    }
    return x;
}

void write(int x) {
    ++steps;
    cout << x + 1 << endl;
    used[x] = 1;
    if (steps == 2 * n) {
        exit(0);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(to, -1, sizeof(to));
    cin >> n >> m;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        to[x] = y;
        to[y] = x;
    }
    cin >> num;
    if (num == 2) {
        while (true) {
            int x = read();
            if (to[x] != -1) {
                write(to[x]);
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (used[i] == 0 && to[i] != -1) {
            if (a[i] > a[to[i]]) {
                write(i);
            } else {
                write(to[i]);
            }
            read();
        }
    }
    while (true) {
        int num = -1;
        for (int i = 0; i < 2 * n; ++i) {
            if (used[i] == 0 && (num == -1 || a[num] < a[i])) {
                num = i;
            }
        }
        write(num);
        read();
    }
    return 0;
}