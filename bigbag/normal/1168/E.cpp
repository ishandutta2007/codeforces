#include <bits/stdc++.h>

using namespace std;

const int max_n = 4222, inf = 1000111222;

int n, a[max_n], p[max_n], q[max_n];
int posp[max_n];

void upd(int p1, int p2, int x) {
    if (p1 > p2) {
        swap(p1, p2);
    }
    //cout << p1 << " " << p2 << ", x = " << x << endl;
    if (!x) {
        return;
    }
    int val = p[p1] ^ x;
    int t = posp[val];
    //cout << "val = " << val << ", t = " << t << endl;
    if (t == p2) {
        swap(posp[p[p1]], posp[p[p2]]);
        swap(p[p1], p[p2]);
        return;
    }
    swap(q[p2], q[t]);
    swap(posp[p[p1]], posp[p[t]]);
    swap(p[p1], p[t]);
    upd(p2, t, q[p2] ^ x ^ q[t]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int x = 0;
    for (int i = 0; i < (1 << n); ++i) {
        scanf("%d", &a[i]);
        x ^= a[i];
        p[i] = q[i] = i;
        posp[p[i]] = i;
    }
    if (x) {
        puts("Fou");
        return 0;
    }
    for (int i = 0; i + 1 < (1 << n); ++i) {
        upd(i, i + 1, a[i] ^ p[i] ^ q[i]);
    }
    puts("Shi");
    for (int i = 0; i < (1 << n); ++i) {
        printf("%d ", p[i]);
    }
    puts("");
    for (int i = 0; i < (1 << n); ++i) {
        printf("%d ", q[i]);
    }
    puts("");
    return 0;
}