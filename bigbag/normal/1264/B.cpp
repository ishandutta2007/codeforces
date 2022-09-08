#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int a, b, c, d;

void no() {
    puts("NO");
    exit(0);
}

void write1(int x, int cnt) {

}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a == b + 1) {
        if (c || d) {
            no();
        }
        puts("YES");
        for (int i = 0; i < b; ++i) {
            printf("0 1 ");
        }
        printf("0\n");
        exit(0);
    }
    if (d == c + 1) {
        if (a || b) {
            no();
        }
        puts("YES");
        for (int i = 0; i < c; ++i) {
            printf("3 2 ");
        }
        printf("3\n");
        exit(0);
    }
    b -= a;
    c -= d;
    //cout << b << " " << c << endl;
    if (b < 0 || c < 0) {
        no();
    }
    int cnt = min(b, c);
    b -= cnt;
    c -= cnt;
    if (b >= 2 || c >= 2) {
        no();
    }
    puts("YES");
    if (b) {
        printf("1 ");
    }
    for (int i = 0; i < a; ++i) {
        printf("0 1 ");
    }
    for (int i = 0; i < cnt; ++i) {
        printf("2 1 ");
    }
    for (int i = 0; i < d; ++i) {
        printf("2 3 ");
    }
    if (c) {
        printf("2");
    }
    puts("");
    return 0;
}