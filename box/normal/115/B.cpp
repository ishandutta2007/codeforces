#include <iostream>
#include <algorithm>
using namespace std;

char matr[155][155];
int first[155], last[155];

inline int abs(int x) {
    if(x < 0) return -x;
    return x;
}

int main() {
    int n, m; cin >> n >> m;
    for(int i=0; i<n; i++) {
        first[i] = 3737; last[i] = -1;
        for(int j=0; j<m; j++) {
            char c; cin >> c;
            matr[i][j] = c;
            if(c == 'W') {
                if(first[i] == 3737) first[i] = j;
                last[i] = j;
            }
        }
    }
    int ans = 0;
    int row = 0, col = 0;
    first[n] = 3737; last[n] = -1;
    while(1) {
        // done?
        bool LAST_ROW = true;
        for(int i=row; i<=n; i++)
            if(first[i] != 3737) { LAST_ROW = false; break; }
        if(LAST_ROW) {
            if(ans != 0) ans--;
            break;
        }
        int to;
        if(row % 2) to = min(min(first[row], first[row+1]), col);
        else to = max(max(last[row], last[row+1]), col);
        ans += abs(to-col)+1;
        col = to; row++;
    }
    cout << ans << endl;
}