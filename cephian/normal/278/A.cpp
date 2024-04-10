#include <iostream>
#include <cstdio>

using namespace std;

int next(int cur, int n) {
    if (cur == n - 1)
        return 0;
    return cur + 1;
}

int prev(int cur, int n) {
    if (cur == 0)
        return n - 1;
    return cur - 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int vals[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vals[i]);
    }
    int s, t;
    scanf("%d %d", &s, &t);
    --s;
    --t;
    if (s == t) {
        printf("0");
        return 0;
    }

    int o1 = 0, o2 = 0;
    for (int i = s; i != t;) {

        o1 += vals[i];
        i = next(i, n);
    }
    for (int i = s; i != t;) {
        o2 += vals[prev(i, n)];
        i = prev(i, n);
    }
    if (o1 < o2)
        printf("%d", o1);
    else
        printf("%d", o2);
    fflush(stdout);
    return 0;
}