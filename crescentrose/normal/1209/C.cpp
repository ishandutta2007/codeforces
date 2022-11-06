#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
const int N = 4e5  +1;
int a[N], to[N], f[N][10], b[N];
bool bz[N];
int T, n;
bool work(int y) {
    for (int i = 1; i <= n ; i++)
        bz[i] = 0;
    int x = 0;
    b[0] = 0;
    while (x < n && a[to[x]] <= y) {
        bz[to[x]] =1 ;
        b[++b[0]] = a[to[x]];
        x = to[x];
    }
    for (int i = 1; i <= n ; i ++)
        if (!bz[i])
            b[++b[0]] = a[i];
    bool sig = 1;
    for (int i = 1; i < n ; i++)
        sig &= (b[i] <= b[i + 1]);
    if (!sig) return 0;
    for (int i = 1; i <= n ; i++)
        if (bz[i]) printf("1");else printf("2");
    printf("\n");
    return 1;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n ; i ++) {
            char c;
            scanf(" %c", &c);
            a[i] = c- '0';
            bz[i] = 0;
        }
        int id = n;
        for (int i = n - 1 ; i>= 0; i --) {
            to[i] = id;
            if (a[id] >= a[i])
                id = i;
        }
        bool sig = 0;
        for (int i = 0; i <= 9; i ++)
            if (work(i)) {
                sig = 1;
                break;
            }
        if (!sig)
            printf("-\n");
    }
    return 0;
}