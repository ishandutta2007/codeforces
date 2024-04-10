#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;

const int max_n = 2022, inf = 1000111222;

int n;
char a[max_n][max_n], b[max_n][max_n], s[max_n], f[max_n][max_n];
bool row[max_n], col[max_n];
int pos;

bool has(int col) {
    for (int i = 0; i < n; ++i) {
        if (f[i][col]) {
            return true;
        }
    }
    return false;
}

void write(char f[max_n][max_n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (int) f[i][j];
        }
        cout << endl;
    }
}

bool check(int pos) {
    //write();
    for (int i = 0; i < n; ++i) {
        row[i] = 0;
        if (f[i][pos]) {
            row[i] = 1;
            for (int j = 0; j < n; ++j) {
                f[i][j] ^= s[j];
            }
        }
    }
    //write();
    for (int j = 0; j < n; ++j) {
        if (pos == j) {
            continue;
        }
        if (has(j)) {
            for (int i = 0; i < n; ++i) {
                f[i][j] ^= s[i];
            }
            if (has(j)) {
                return false;
            }
            col[j] = 1;
        } else {
            col[j] = 0;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    bool has = false;
    for (int i = 0; i < n; ++i) {
        scanf("%s", b[i]);
        for (int j = 0; j < n; ++j) {
            a[i][j] -= '0';
            b[i][j] -= '0';
            a[i][j] ^= b[i][j];
            if (a[i][j]) {
                has = true;
            }
        }
    }
    //write(a);
    scanf("%s", s);
    pos = -1;
    for (int i = 0; i < n; ++i) {
        s[i] -= '0';
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == 1) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        if (has) {
            puts("-1");
            return 0;
        }
        puts("0");
        return 0;
    }
    for (int tp = 0; tp < 2; ++tp) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[i][j] = a[i][j];
            }
        }
        if (tp) {
            for (int i = 0; i < n; ++i) {
                f[i][pos] ^= s[i];
            }
        }
        col[pos] = tp;
        if (check(pos)) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += row[i];
                cnt += col[i];
            }
            printf("%d\n", cnt);
            for (int i = 0; i < n; ++i) {
                if (row[i]) {
                    printf("row %d\n", i);
                }
            }
            for (int i = 0; i < n; ++i) {
                if (col[i]) {
                    printf("col %d\n", i);
                }
            }
            return 0;
        }
    }
    puts("-1");
    return 0;
}