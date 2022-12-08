#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace {
int x1, y1, x2, y2, x3, y3;
int x, y, n;
int medium(int x, int y, int z) {
    return x + y + z - max(max(x, y), z) - min(min(x, y), z);
}
void rmain() {
    scanf("%d", &n);
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    scanf("%d%d", &x, &y);
    int X = medium(x1, x2, x3), Y = medium(y1, y2, y3);
    if ((X == 1 || X == n) && (Y == 1 || Y == n)) {
        if (x == X || y == Y) puts("YES");
        else puts("NO");
        return;
    }
    if (x % 2 == x1 % 2 && y % 2 == y1 % 2) puts("YES");
    else if (x % 2 == x2 % 2 && y % 2 == y2 % 2) puts("YES");
    else if (x % 2 == x3 % 2 && y % 2 == y3 % 2) puts("YES");
    else puts("NO");
}
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}