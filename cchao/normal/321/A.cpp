#include <bits/stdc++.h>
using namespace std;
bool can(int x, int y, int dx, int dy) {
    if(dx == 0 && dy == 0) return x == 0 && y == 0;
    if(dx == 0) return x == 0 && y % dy == 0 && y / dy >= 0;
    if(dy == 0) return y == 0 && x % dx == 0 && x / dx >= 0;
    return x % dx == 0 && y % dy == 0 && x / dx == y / dy && x / dx >= 0;
}
int main() {
    int tx, ty; string s;
    cin >> tx >> ty >> s;
    int dx = 0, dy = 0;
    for(char c: s) {
        if(c == 'U') dy++;
        else if(c == 'D') dy--;
        else if(c == 'L') dx--;
        else dx++;
    }
    int x = 0, y = 0;
    bool ans = can(tx - x, ty - y, dx, dy);
    if(!ans) for(char c: s) {
        if(c == 'U') y++;
        else if(c == 'D') y--;
        else if(c == 'L') x--;
        else x++;
        if((ans = can(tx - x, ty - y, dx, dy))) break;
    }
    puts(ans ? "Yes" : "No");
    return 0;
}