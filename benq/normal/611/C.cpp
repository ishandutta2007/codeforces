#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

char grid[501][501];
int horizontal[501][501], vertical[501][501];

int main() {
    int h,w,q;
    cin >> h >> w;

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
           cin >> grid[i][j];
        }
    }
    for (int i = 1; i < h; ++i) {
        for (int j = 1; j <= w; ++j) {
            horizontal[i][j] = horizontal[i-1][j]+horizontal[i][j-1]-horizontal[i-1][j-1];
            if (grid[i][j] == '.' && grid[i+1][j] == '.') {
                horizontal[i][j] ++;
            }
        }
    }
    
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j < w; ++j) {
            vertical[i][j] = vertical[i-1][j]+vertical[i][j-1]-vertical[i-1][j-1];
            if (grid[i][j] == '.' && grid[i][j+1] == '.') {
                vertical[i][j] ++;
            }
        }
    }
    
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a,b,c,d, ans=0;
        cin >> a >> b >> c >> d;
        // cout << c << " ";
        // cout << horizontal[c-1][d];
        ans += (horizontal[c-1][d]-horizontal[c-1][b-1]-horizontal[a-1][d]+horizontal[a-1][b-1]);
        ans += (vertical[c][d-1]-vertical[c][b-1]-vertical[a-1][d-1]+vertical[a-1][b-1]);
        cout << ans << endl;
    }
}