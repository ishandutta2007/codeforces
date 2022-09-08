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

const int max_n = 2000001, inf = 111111111;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (a != 0 && b != 0) {
        int k = a;
        a = b;
        b = k % b;
    }
    return a + b;
}

int n, a[max_n], parent[max_n], used[10 * max_n];

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int v1, int v2) {
    v1 = find_set(v1), v2 = find_set(v2);
    parent[v1] = v2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        scanf("%d", &a[i]);
        if (a[i] > 10000000) {
            cout << "This test is incorrect!!!" << endl;
            return 0;
        }
        used[a[i]] = i;
    }
    int ans = n;
    for (int x = 1; x <= 5000; ++x) {
        for (int y = 1; y < x; ++y) {
            int a = x * x - y * y, b = 2 * x * y, c = x * x + y * y;
            if (a < 10 * max_n && b < 10 * max_n && c < 10 * max_n) {
                if (gcd(a, b) == 1 && gcd(a, c) == 1 && gcd(b, c) == 1) {
                    a = used[a];
                    b = used[b];
                    c = used[c];
                    if (a != 0 && b != 0 && find_set(a) != find_set(b)) {
                        --ans;
                        union_set(a, b);
                    }
                    if (a != 0 && c != 0 && find_set(a) != find_set(c)) {
                        --ans;
                        union_set(a, c);
                    }
                    if (b != 0 && c != 0 && find_set(b) != find_set(c)) {
                        --ans;
                        union_set(b, c);
                    }
                }
            } else {
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}