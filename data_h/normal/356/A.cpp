#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

const int N = 333333;

int left[N], right[N], result[N];
int n, m;

int find(int fa[], int x) {
    int p = x;
    while(fa[p] != p)
        p = fa[p];
    while(x != p) {
        int t = fa[x];
        fa[x] = p;
        x = t;
    }
    return p;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n + 1; i++)
        right[i] = i;
    int lastWin = 0;
    for(int i = 1; i <= m; i++) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        for(int i = find(right, l); i < x; i = find(right, i + 1)) {
            result[i] = x;
            right[i] = x;
        }
        for(int i = find(right, x + 1); i <= r; i = find(right, i + 1)) {
            result[i] = x;
            right[i] = right[r + 1];
        }
        lastWin = x;
    }
    for(int i = 1; i <= n; i++)
        if (lastWin != i && result[i] == 0)
            result[i] = lastWin;
    for(int i = 1; i <= n; i++)
        printf("%d%c", result[i], i == n ? '\n' : ' ');
    return 0;
}