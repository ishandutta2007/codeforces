#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, 0, -1, 1, -1, 1};

char s[10][10];

int f[10][10][100];

bool go(int x, int y, int len) {
    if (len > 50) return false;
    if (f[x][y][len] >= 0) return f[x][y][len];
    if (x == 7 && y == 7) return true;

    int& res = f[x][y][len];
    res = 0;

    for (int k = 0; k < 9; k++) {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (xx < 0) continue;
        if (xx > 7) continue;
        if (yy < 0) continue;
        if (yy > 7) continue;
        
        int X = xx + len;
        if (X < 8 && s[X][yy] == 'S') continue;
        if (X+1 < 8 && s[X+1][yy] == 'S') continue;

        res |= go(xx, yy, len + 1);
    }

    return res;
}

void solve() {
    for (int i = 7; i >= 0; i--) cin >> s[i];

    memset(f, -1, sizeof f);
    if (go(0, 0, 0)) cout << "WIN"; else cout << "LOSE";
    cout << endl;
}

int main() {
    solve();
    return 0;
}